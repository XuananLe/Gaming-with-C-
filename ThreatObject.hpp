#ifndef __THREAT_OBJECT_H__
#define __THREAT_OBJECT_H__
#include "Define.h"
#include "BaseObject.hpp"
#define THREAT_WIDTH 90
#define THREAT_HEIGHT 90
#define THREAT_VEL 7
class ThreatObject : public BaseObject
{
protected:
    int x_val;
    int y_val;
    bool can_move;

public:
    ThreatObject();
    ~ThreatObject();

    int get_x_val() { return x_val; }
    void set_x_val(int x_val) { this->x_val = x_val; }
    int get_y_val() { return y_val; }
    void set_y_val(int y_val) { this->y_val; }

    bool get_can_move() { return can_move; }
    void set_can_move(bool can_move) { this->can_move = can_move; }

    void handle_move(const int &x, const int &y);
    void handle_input_action(SDL_Event event);
};

ThreatObject::ThreatObject()
{
    x_val = 0;
    y_val = 0;
    can_move = true;
    dst_Rect.w = THREAT_WIDTH;
    dst_Rect.h = THREAT_HEIGHT;
    dst_Rect.x = 12;
    dst_Rect.y = 0;
}
ThreatObject::~ThreatObject()
{
}
void ThreatObject::handle_input_action(SDL_Event event)
{
}
void ThreatObject::handle_move(const int &x, const int &y)
{
    if (dst_Rect.y < SCREEN_HEIGHT)
        dst_Rect.y += THREAT_VEL;
    else
    {
        dst_Rect.y = rand()% 300;
    }
}

#endif