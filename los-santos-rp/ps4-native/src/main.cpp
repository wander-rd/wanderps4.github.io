/*
 * Los Santos RP — native gameplay bring-up
 *
 * A small 2D top-down proof of concept for validating the SDL event loop,
 * keyboard/controller input, a player/car state, a delivery objective and
 * local RPG progression before porting the larger web prototype.
 *
 * This is NOT the full 3D game. It has not been compiled or tested on PS4.
 * Build only against an SDL-PS4 setup whose APIs match this source.
 */
#include <SDL.h>
#include <algorithm>
#include <cmath>
#include <cstdio>

struct Actor {
    float x;
    float y;
};

static void fill(SDL_Surface* s, int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b) {
    if (!s || w <= 0 || h <= 0) return;
    SDL_Rect rect{x, y, w, h};
    SDL_FillRect(s, &rect, SDL_MapRGB(s->format, r, g, b));
}

static void worldRect(SDL_Surface* s, const Actor& camera, float wx, float wy,
                      int ww, int wh, int scale, Uint8 r, Uint8 g, Uint8 b) {
    const int sx = s->w / 2 + static_cast<int>((wx - camera.x) * scale) - ww * scale / 2;
    const int sy = s->h / 2 - static_cast<int>((wy - camera.y) * scale) - wh * scale / 2;
    fill(s, sx, sy, ww * scale, wh * scale, r, g, b);
}

static bool near(const Actor& a, const Actor& b, float distance) {
    const float dx = a.x - b.x;
    const float dy = a.y - b.y;
    return dx * dx + dy * dy <= distance * distance;
}

static void drawWorld(SDL_Window* window, const Actor& player, const Actor& car,
                      const Actor& npc, bool inCar, bool missionActive,
                      int cash, int reputation, int deliveries) {
    SDL_Surface* s = SDL_GetWindowSurface(window);
    if (!s) return;
    SDL_FillRect(s, nullptr, SDL_MapRGB(s->format, 35, 58, 47));

    const int scale = 3;
    const Actor& camera = inCar ? car : player;

    // City blocks and road grid, kept deliberately simple for the first native build.
    for (int i = -8; i <= 8; ++i) {
        worldRect(s, camera, i * 24.0f, 0, 9, 240, scale, 48, 53, 57);
        worldRect(s, camera, 0, i * 24.0f, 240, 9, scale, 48, 53, 57);
        worldRect(s, camera, i * 24.0f + 7, 0, 1, 240, scale, 205, 190, 135);
        worldRect(s, camera, 0, i * 24.0f + 7, 240, 1, scale, 205, 190, 135);
    }

    // River and bridge delivery destination.
    worldRect(s, camera, 0, -80, 14, 65, scale, 39, 112, 137);
    worldRect(s, camera, 0, -80, 10, 56, scale, 115, 120, 123);
    for (int mark = -104; mark <= -56; mark += 6) {
        worldRect(s, camera, 0, static_cast<float>(mark), 1, 2, scale, 232, 222, 174);
    }

    // NPC, car and player markers.
    worldRect(s, camera, npc.x, npc.y, 2, 2, scale, 242, 194, 93);
    worldRect(s, camera, car.x, car.y, 4, 7, scale, 187, 70, 58);
    if (!inCar) worldRect(s, camera, player.x, player.y, 2, 2, scale, 103, 241, 211);

    // Minimal HUD bars: cash, reputation and mission state.
    fill(s, 16, 16, 210, 12, 18, 29, 35);
    fill(s, 18, 18, std::min(206, 30 + cash / 500), 8, 75, 223, 133);
    fill(s, 16, 36, 210, 8, 18, 29, 35);
    fill(s, 18, 38, std::min(206, 10 + reputation * 2), 4, 80, 176, 238);
    fill(s, s->w - 34, 16, 18, 18, missionActive ? 75 : 95,
         missionActive ? 245 : 105, missionActive ? 120 : 115);
    SDL_UpdateWindowSurface(window);

    char title[180];
    std::snprintf(title, sizeof(title),
        "Los Santos RP Native Test | $%d | Rep %d | Deliveries %d | %s | F: mission, E/Y: car",
        cash, reputation, deliveries, missionActive ? "DELIVERY ACTIVE" : "FREE ROAM");
    SDL_SetWindowTitle(window, title);
}

int main(int, char**) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER) != 0) {
        std::fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Los Santos RP - Native RPG Test",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        960, 540, SDL_WINDOW_SHOWN
    );
    if (!window) {
        std::fprintf(stderr, "SDL_CreateWindow failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 2;
    }

    SDL_GameController* controller = nullptr;
    if (SDL_NumJoysticks() > 0 && SDL_IsGameController(0)) {
        controller = SDL_GameControllerOpen(0);
    }

    Actor player{0.0f, 60.0f};
    Actor car{4.0f, 60.0f};
    Actor npc{8.0f, 53.0f};
    bool running = true;
    bool inCar = false;
    bool missionActive = false;
    bool previousInteract = false;
    bool previousCarButton = false;
    int cash = 50000;
    int reputation = 0;
    int deliveries = 0;
    Uint32 lastTick = SDL_GetTicks();

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) running = false;
        }

        const Uint8* keys = SDL_GetKeyboardState(nullptr);
        float dx = 0.0f;
        float dy = 0.0f;
        if (keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_LEFT]) dx -= 1.0f;
        if (keys[SDL_SCANCODE_D] || keys[SDL_SCANCODE_RIGHT]) dx += 1.0f;
        if (keys[SDL_SCANCODE_W] || keys[SDL_SCANCODE_UP]) dy += 1.0f;
        if (keys[SDL_SCANCODE_S] || keys[SDL_SCANCODE_DOWN]) dy -= 1.0f;

        bool interactPressed = keys[SDL_SCANCODE_F] != 0;
        bool carPressed = keys[SDL_SCANCODE_E] != 0;
        if (controller) {
            const Sint16 ax = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTX);
            const Sint16 ay = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTY);
            if (std::abs(ax) > 6500) dx += static_cast<float>(ax) / 32767.0f;
            if (std::abs(ay) > 6500) dy -= static_cast<float>(ay) / 32767.0f;
            interactPressed = interactPressed ||
                SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A);
            carPressed = carPressed ||
                SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_Y);
            if (SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B)) running = false;
        }

        const bool interactEdge = interactPressed && !previousInteract;
        const bool carEdge = carPressed && !previousCarButton;
        previousInteract = interactPressed;
        previousCarButton = carPressed;

        if (carEdge) {
            if (inCar) {
                inCar = false;
                player.x = car.x + 2.5f;
                player.y = car.y;
            } else if (near(player, car, 5.0f)) {
                inCar = true;
            }
        }

        Actor& controlled = inCar ? car : player;
        const float magnitude = std::sqrt(dx * dx + dy * dy);
        if (magnitude > 0.08f) {
            const float speed = inCar ? 24.0f : 11.0f;
            const float normalizer = magnitude > 1.0f ? magnitude : 1.0f;
            controlled.x += dx / normalizer * speed / 60.0f;
            controlled.y += dy / normalizer * speed / 60.0f;
            controlled.x = std::max(-180.0f, std::min(180.0f, controlled.x));
            controlled.y = std::max(-180.0f, std::min(180.0f, controlled.y));
        }

        if (interactEdge && !missionActive && !inCar && near(player, npc, 5.0f)) {
            missionActive = true;
        }
        if (missionActive && near(controlled, Actor{0.0f, -80.0f}, 8.0f)) {
            missionActive = false;
            cash += 1500;
            reputation += 10;
            deliveries += 1;
        }

        drawWorld(window, player, car, npc, inCar, missionActive, cash, reputation, deliveries);
        const Uint32 now = SDL_GetTicks();
        const Uint32 elapsed = now - lastTick;
        if (elapsed < 16) SDL_Delay(16 - elapsed);
        lastTick = now;
    }

    if (controller) SDL_GameControllerClose(controller);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
