#ifndef MainObject_H_
#define MainObject_H_
#include <vector>
#include "BaseObject.hpp"
#include "AmmoObject.hpp"

class MainObject : public BaseObject
{
protected:
    std::vector<AmmoObject *> p_ammo_list;
    int x_val;
    int y_val;

public:
    ~MainObject() {}
    MainObject();

    void set_List_Ammo(std::vector<AmmoObject *> p_ammo_list) { this->p_ammo_list = p_ammo_list; }
    std::vector<AmmoObject *> get_List_Ammo() const { return p_ammo_list; }
    void handle_and_render_ammo();

    int get_x_val() { return x_val; }
    int get_y_val() { return y_val; }

    void Handle_Move();
    void Handle_Input_Action(SDL_Event events);
};
void MainObject::Handle_Input_Action(SDL_Event events)
{
    if (events.type == SDL_KEYDOWN)
    {
        switch (events.key.keysym.sym)
        {
        case SDLK_s:
            y_val += SHIP_VEL;
            break;
        case SDLK_w:
            y_val -= SHIP_VEL;
            break;
        case SDLK_a:
            x_val -= SHIP_VEL;
            break;
        case SDLK_d:
            x_val += SHIP_VEL;
            break;
        }
    }
    else if (events.type == SDL_KEYUP)
    {
        switch (events.key.keysym.sym)
        {
        case SDLK_s:
            y_val = 0;
            break;
        case SDLK_w:
            y_val = 0;
            break;
        case SDLK_a:
            x_val = 0;
            break;
        case SDLK_d:
            x_val = 0;
            break;
        }
    }
    else if (events.type == SDL_MOUSEBUTTONDOWN)
    {
        AmmoObject *p_ammo = new AmmoObject();
        if (events.button.button == SDL_BUTTON_LEFT)
        {
            // them dan de ban va set tinh tang vien dan ra true
            p_ammo->SetWidthHeight(LASER_WIDTH, LASER_HEIGHT);
            p_ammo->setRect(this->dst_Rect.x + 40, this->dst_Rect.y + 25);
            
            p_ammo->loadIMG("Assets/Bullet.png");
            p_ammo->set_ammo_type(AmmoObject::LASER);
            p_ammo->set_is_move(true);
            p_ammo_list.push_back(p_ammo);
        }
    }
    else if (events.type == SDL_MOUSEBUTTONUP)
    {
    }
    else
    {
    }
}
void MainObject::Handle_Move()
{
    dst_Rect.x += x_val;
    if (dst_Rect.x + SPACESHIP_WIDTH > SCREEN_WIDTH || dst_Rect.x < 0)
    {
        dst_Rect.x -= x_val;
    }
    dst_Rect.y += y_val;
    if (dst_Rect.y + SPACESHIP_HEIGHT > SCREEN_HEIGHT || dst_Rect.y < 0)
    {
        dst_Rect.y -= y_val;
    }
}
MainObject::MainObject()
{
    dst_Rect.x = 0;
    dst_Rect.y = 0;
    dst_Rect.w = SPACESHIP_WIDTH;
    dst_Rect.h = SPACESHIP_HEIGHT;
    x_val = 0;
    y_val = 0;
}
void MainObject::handle_and_render_ammo()
{
    for (int i = 0; i < p_ammo_list.size(); i++)
    {
        //update tung thanh phan 1 roi render 1 the
        std::vector<AmmoObject *> BULLET = p_ammo_list;
        AmmoObject *x = BULLET[i];
        if (x != NULL)
        {
            if (x->get_is_move() == true)
            {
                x->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
                x->render();
            }
            else
            {
                if (x != NULL)
                {
                    // xoa phan tu o danh sach tam thoi vi tri i neu nhu no di chuyen khong dung
                    BULLET.erase(BULLET.begin(), BULLET.begin() + i);
                    // update lai danh sach
                    p_ammo_list = BULLET;
                }
            }
        }
    }
}
#endif