#include "BaseObject.hpp"
#include "MainObject.hpp"
#include "AmmoObject.hpp"
#include "Define.h"
#include "ThreatObject.hpp"
int rand()
{
    return rand() % 1 + SCREEN_WIDTH;
}
class Game
{
public:
    bool IS_RUNNING = true;
    ~Game() {}
    void update();
    void handleEvent();
    void close();
    bool isRunning() { return IS_RUNNING; }
    void render(BaseObject *object);
};
// void Game::render(BaseObject *object) { SDL_RenderCopy(renderer, object->objTexture, NULL, &(object->dst_Rect)); }
void Game::close()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
void Game::update() { SDL_RenderPresent(renderer); }
void Game::handleEvent()
{
    while (SDL_PollEvent(&event) != 0)
    {
        switch (event.type)
        {
        case SDL_QUIT:
            IS_RUNNING = false;
            break;
        }
    }
}
Game *game = new Game();
//============GAME OBJECT=============//
BaseObject *BACK_GROUND = new BaseObject();
MainObject *YELLOW_SPACESHIP = new MainObject();
ThreatObject *RED_SPACESHIP = new ThreatObject();

// MainCharacter *YELLOW_SPACESHIP = new MainCharacter();
//==============Neccesary Function==========a======//
int main(int argc, char *argv[])
{
    BACK_GROUND->setRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    BACK_GROUND->loadIMG("Assets/space.png");
    YELLOW_SPACESHIP->setRect(500, 500);
    YELLOW_SPACESHIP->loadIMG("Assets/spaceship_red.png");
    bool isRunning = true;
    int count = 0;
    RED_SPACESHIP->loadIMG("Assets/spaceship_red.png");
    while (isRunning)
    {
        BACK_GROUND->render();

        while (SDL_PollEvent(&event) != 0)
        {
            switch (event.type)
            {
            case SDL_QUIT:
                isRunning = false;
                break;
            }
            YELLOW_SPACESHIP->Handle_Input_Action(event);
        }
        RED_SPACESHIP->handle_move(SCREEN_WIDTH, SCREEN_HEIGHT);
        YELLOW_SPACESHIP->Handle_Move();
        YELLOW_SPACESHIP->render();
        RED_SPACESHIP->render();
        YELLOW_SPACESHIP->handle_and_render_ammo();
        FramePerSecond();
        SDL_RenderPresent(renderer);
    }
}