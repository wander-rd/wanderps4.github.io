// Los Santos Online RP — native PS4-oriented SDL2 prototype
// Original fictional city assets. This source requires SDL2/SDL-PS4 and an OpenOrbis build setup.
#include <SDL.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

struct Building { float x, y, w, h; SDL_Color color; };
struct TrafficCar { float x, y, vx, vy; SDL_Color color; };
struct PlayerCar { float x=960, y=540, angle=0, speed=0; int model=0; };

static constexpr int W=1920, H=1080;
static SDL_Color colors[]={{225,65,65,255},{38,123,214,255},{237,184,63,255},{32,42,53,255},{66,199,123,255},{233,233,233,255}};
static SDL_Color trafficColors[]={{232,232,232,255},{38,123,214,255},{37,43,51,255},{217,178,62,255},{72,166,106,255},{168,68,68,255}};
static void rect(SDL_Renderer* r, SDL_Color c, int x,int y,int w,int h){ SDL_SetRenderDrawColor(r,c.r,c.g,c.b,c.a); SDL_Rect q{x,y,w,h}; SDL_RenderFillRect(r,&q); }
static void line(SDL_Renderer* r, SDL_Color c, int x1,int y1,int x2,int y2){ SDL_SetRenderDrawColor(r,c.r,c.g,c.b,c.a); SDL_RenderDrawLine(r,x1,y1,x2,y2); }

int main(int argc,char** argv){
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_GAMECONTROLLER|SDL_INIT_EVENTS)!=0) return 1;
    SDL_Window* win=SDL_CreateWindow("Los Santos Online RP",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,W,H,SDL_WINDOW_SHOWN);
    if(!win){SDL_Quit();return 2;}
    SDL_Renderer* ren=SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if(!ren) ren=SDL_CreateRenderer(win,-1,SDL_RENDERER_SOFTWARE);
    if(!ren){SDL_DestroyWindow(win);SDL_Quit();return 3;}
    SDL_GameController* pad=nullptr;
    for(int i=0;i<SDL_NumJoysticks();++i) if(SDL_IsGameController(i)){pad=SDL_GameControllerOpen(i);if(pad)break;}
    std::vector<Building> buildings;
    for(int bx=-4;bx<=4;++bx) for(int by=-4;by<=4;++by){
        if(std::abs(bx)<1&&std::abs(by)<1) continue;
        float x=960+bx*250+70, y=540+by*190+55;
        float w=110+((bx*17+by*7+99)%65), h=70+((bx*11+by*19+99)%55);
        buildings.push_back({x,y,w,h,{(Uint8)(92+(bx*7+by*3+99)%60),(Uint8)(99+(bx*5+by*11+99)%55),(Uint8)(105+(bx*13+by*2+99)%50),255}});
    }
    std::vector<TrafficCar> traffic;
    for(int i=0;i<12;++i) traffic.push_back({float((i*173)%W),float((i*137)%H),i%2?0.f:float(70+(i%4)*15),i%2?float(65+(i%3)*12):0.f,trafficColors[i%6]});
    PlayerCar car; bool running=true; Uint32 last=SDL_GetTicks(); float cash=2500; int upgrades=0; bool prevY=false, prevX=false;
    while(running){
        Uint32 now=SDL_GetTicks(); float dt=std::min(.04f,(now-last)/1000.f);last=now;
        SDL_Event e; while(SDL_PollEvent(&e)){if(e.type==SDL_QUIT)running=false;if(e.type==SDL_KEYDOWN&&e.key.keysym.sym==SDLK_ESCAPE)running=false;}
        const Uint8* k=SDL_GetKeyboardState(nullptr);
        float accel=(k[SDL_SCANCODE_W]||k[SDL_SCANCODE_UP])?1.f:0.f;
        float brake=(k[SDL_SCANCODE_S]||k[SDL_SCANCODE_DOWN])?1.f:0.f;
        float steer=(k[SDL_SCANCODE_D]||k[SDL_SCANCODE_RIGHT]?1.f:0.f)-(k[SDL_SCANCODE_A]||k[SDL_SCANCODE_LEFT]?1.f:0.f);
        if(pad){
            const Sint16 ax=SDL_GameControllerGetAxis(pad,SDL_CONTROLLER_AXIS_LEFTX);
            if(std::abs(ax)>6500)steer=ax/32767.f;
            if(SDL_GameControllerGetAxis(pad,SDL_CONTROLLER_AXIS_TRIGGERRIGHT)>9000)accel=1.f;
            if(SDL_GameControllerGetAxis(pad,SDL_CONTROLLER_AXIS_TRIGGERLEFT)>9000)brake=1.f;
            bool yPressed=SDL_GameControllerGetButton(pad,SDL_CONTROLLER_BUTTON_Y)!=0;
            bool xPressed=SDL_GameControllerGetButton(pad,SDL_CONTROLLER_BUTTON_X)!=0;
            if(yPressed&&!prevY)car.model=(car.model+1)%6;
            if(xPressed&&!prevX&&cash>=750){cash-=750;++upgrades;}
            prevY=yPressed; prevX=xPressed;
        }
        car.speed+=accel*(150.f+upgrades*20)*dt; car.speed-=brake*210.f*dt;
        if(!accel&&!brake)car.speed*=std::pow(.985f,dt*60);
        car.speed=std::clamp(car.speed,-90.f,300.f+upgrades*35.f);
        car.angle+=steer*dt*(.9f+std::min(std::abs(car.speed)/130.f,1.5f))*(car.speed<0?-1.f:1.f);
        car.x+=std::sin(car.angle)*car.speed*dt; car.y-=std::cos(car.angle)*car.speed*dt;
        if(car.x<0)car.x=W;if(car.x>W)car.x=0;if(car.y<0)car.y=H;if(car.y>H)car.y=0;
        for(auto& t:traffic){t.x+=t.vx*dt;t.y+=t.vy*dt;if(t.x>W)t.x=0;if(t.y>H)t.y=0;}
        SDL_SetRenderDrawColor(ren,79,103,79,255);SDL_RenderClear(ren);
        // Roads and lane markings: repeat across the map.
        for(int x=-250;x<W+250;x+=250){rect(ren,{48,57,63,255},x,0,74,H);for(int y=0;y<H;y+=55)rect(ren,{225,215,170,255},x+35,y,4,25);}
        for(int y=-190;y<H+190;y+=190){rect(ren,{48,57,63,255},0,y,W,64);for(int x=0;x<W;x+=55)rect(ren,{225,215,170,255},x,y+30,25,4);}
        for(const auto& b:buildings){rect(ren,{38,44,47,255},(int)b.x+5,(int)b.y+6,(int)b.w,(int)b.h);rect(ren,b.color,(int)b.x,(int)b.y,(int)b.w,(int)b.h);for(int wx=10;wx<(int)b.w-8;wx+=24)for(int wy=9;wy<(int)b.h-6;wy+=22)rect(ren,{126,177,190,255},(int)b.x+wx,(int)b.y+wy,11,9);}
        for(const auto& t:traffic){rect(ren,{18,23,28,255},(int)t.x-13,(int)t.y-23,26,46);rect(ren,t.color,(int)t.x-11,(int)t.y-21,22,42);}
        // Player car is a simple original top-down placeholder.
        SDL_Rect body{(int)car.x-15,(int)car.y-26,30,52};SDL_SetRenderDrawColor(ren,colors[car.model].r,colors[car.model].g,colors[car.model].b,255);SDL_RenderFillRect(ren,&body);
        line(ren,{255,255,255,255},(int)car.x,(int)car.y,(int)(car.x+std::sin(car.angle)*34),(int)(car.y-std::cos(car.angle)*34));
        // Simple HUD bars: cash and speed are represented without font dependencies.
        rect(ren,{8,15,24,235},24,24,260,72);rect(ren,{68,229,255,255},38,40,std::min(220,(int)(std::abs(car.speed)/335.f*220)),10);
        rect(ren,{8,15,24,235},W-190,24,166,72);rect(ren,{255,198,109,255},W-176,44,std::min(138,(int)(std::abs(car.speed)/335.f*138)),18);
        rect(ren,{8,15,24,235},24,H-78,310,48);rect(ren,{142,255,177,255},36,H-64,std::min(280,(int)(cash/10000.f*280)),18);
        SDL_RenderPresent(ren);
    }
    if(pad)SDL_GameControllerClose(pad);SDL_DestroyRenderer(ren);SDL_DestroyWindow(win);SDL_Quit();return 0;
}
