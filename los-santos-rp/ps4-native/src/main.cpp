/*
 * Los Santos RP — native PS4 bring-up scaffold
 *
 * Purpose: prove that an SDL2-based native build can open a window,
 * process events and display a simple status screen before porting game
 * systems. This is NOT the full game and has not yet been compiled for PS4.
 *
 * Build against the SDL2 port supplied for the selected OpenOrbis setup.
 */
#include <SDL.h>
#include <cstdio>

static void drawStatus(SDL_Window* window, bool controllerConnected, bool upPressed) {
    SDL_Surface* surface = SDL_GetWindowSurface(window);
    if (!surface) return;

    const Uint32 background = SDL_MapRGB(surface->format, 14, 24, 31);
    const Uint32 accent = SDL_MapRGB(surface->format, 55, 210, 125);
    const Uint32 muted = SDL_MapRGB(surface->format, 57, 77, 87);
    SDL_FillRect(surface, nullptr, background);

    SDL_Rect titleBar{24, 24, surface->w > 48 ? surface->w - 48 : 1, 10};
    SDL_FillRect(surface, &titleBar, accent);

    SDL_Rect statusBar{24, 58, controllerConnected ? 220 : 130, 18};
    SDL_FillRect(surface, &statusBar, controllerConnected ? accent : muted);

    SDL_Rect inputBar{24, 92, upPressed ? 220 : 70, 18};
    SDL_FillRect(surface, &inputBar, upPressed ? accent : muted);

    SDL_UpdateWindowSurface(window);
}

int main(int, char**) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER) != 0) {
        std::fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Los Santos RP - Native Bring-up",
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

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
            if (event.type == SDL_CONTROLLERBUTTONDOWN &&
                event.cbutton.button == SDL_CONTROLLER_BUTTON_B) {
                running = false;
            }
        }

        bool upPressed = false;
        if (controller && SDL_GameControllerGetButton(
                controller, SDL_CONTROLLER_BUTTON_DPAD_UP)) {
            upPressed = true;
        }

        const Uint8* keyboard = SDL_GetKeyboardState(nullptr);
        if (keyboard && keyboard[SDL_SCANCODE_UP]) upPressed = true;

        drawStatus(window, controller != nullptr, upPressed);
        SDL_Delay(16);
    }

    if (controller) SDL_GameControllerClose(controller);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
