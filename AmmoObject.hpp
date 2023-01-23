#ifndef AMMOOBJECT_H_
#define AMMOOBJECT_H_
#include "BaseObject.hpp"
#define LASER_WIDTH 12
#define LASER_HEIGHT 24
class AmmoObject : public BaseObject
{
public:
    enum AmmoType
    {
        NONE = 0,
        LASER = 1,
        DOUBLE_LASER = 2,
        SEPHERE = 3
    };
    AmmoObject();
    ~AmmoObject();
    
    void HandleInputAction(SDL_Event event);
    void HandleMove(const int &x_boder, const int &y_boder);

    int get_ammo_type();
    void set_ammo_type(int amo_type);

    bool get_is_move() const;
    void set_is_move(bool is_move);
    // khoi tao width height cua hinh chu nhat
    void SetWidthHeight(const int &width, const int &height)
    {
        dst_Rect.w = width;
        dst_Rect.h = height;
    }

protected:
    int x_val;
    int y_val;
    bool is_move;
    int amo_type;
};
AmmoObject::~AmmoObject()
{
    std::cout << "AmmoObject destroyed" << std::endl;
}
AmmoObject::AmmoObject()
{
    x_val = 0;
    y_val = 0;
    dst_Rect.x = 0;
    dst_Rect.y = 0;
    is_move = false;
    amo_type = NONE;
}

// GET SET AMMO_TYPE
int AmmoObject::get_ammo_type()
{
    return amo_type;
}
void AmmoObject::set_ammo_type(int amo_type)
{
    this->amo_type = amo_type;
}
// GET SET IS_MOVE
bool AmmoObject::get_is_move() const
{
    return is_move;
}
void AmmoObject::set_is_move(bool is_move)
{
    this->is_move = is_move; 
}
// HANDLE A MOVE
void AmmoObject::HandleMove(const int &x_border, const int &y_border)
{
    dst_Rect.y -= BULLET_VEL;
    if(dst_Rect.y  < 0)
    {
        is_move = false;
    }
}
void AmmoObject::HandleInputAction(SDL_Event event)
{
}
#endif