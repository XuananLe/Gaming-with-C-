#ifndef BASEOBJECT_H_
#define BASEOBJECT_H_
#include "Define.h"
class BaseObject // dung de ke thua cac lop kia
{
protected:
    // vi tri cua BaseObject
    int width, height;
    int xPos = 0, yPos = 0;
    SDL_Rect dst_Rect;
    SDL_Texture *objTexture = NULL;
public:
    ~BaseObject();
    BaseObject();
    void free();
    void setRect(const int &_x, const int &y, const int &w, const int&h);
    SDL_Rect GetRect() const { return dst_Rect;}
    void setRect(const int &_x, const int &_y);
    void init(const char *file, int xPos, int yPos, int width, int height);
    void loadIMG(const char *file);
    SDL_Texture *getTexture() const;
    void render(const SDL_Rect *src_rect);
};
// vi tri ma muon render
void BaseObject::setRect(const int &_x, const int &_y)
{
    dst_Rect.x = _x;
    dst_Rect.y = _y;
}
void BaseObject::setRect(const int &_x, const int &_y, const int &_w, const int& _h)
{
    dst_Rect.x = _x;
    dst_Rect.y = _y;
    dst_Rect.w = _w;
    dst_Rect.h = _h;
}
SDL_Texture *BaseObject::getTexture() const 
{
return objTexture;
}
BaseObject::~BaseObject()
{
    free();
}
BaseObject::BaseObject()
{
    objTexture = NULL;
    dst_Rect.h = 0;
    dst_Rect.w = 0;
    dst_Rect.x = 0;
    dst_Rect.y = 0;
}
void BaseObject::render(const SDL_Rect *src_rect = NULL)
{
    SDL_RenderCopy(renderer, objTexture,NULL, &dst_Rect);
}
void BaseObject::loadIMG(const char *file)
{
    free();
    SDL_Texture *newTexure = NULL;
    SDL_Surface *surface = IMG_Load(file);
    newTexure = SDL_CreateTextureFromSurface(renderer, surface);
    if (newTexure != NULL)
    {       
        objTexture = newTexure;
        SDL_FreeSurface(surface);
    }
    else std::cout << SDL_GetError() << std::endl;
}
void BaseObject::free()
{
    if (objTexture != NULL)
    {
        SDL_DestroyTexture(objTexture);
        objTexture = NULL;
        dst_Rect.w = 0;
        dst_Rect.h = 0;
        objTexture = NULL;
    }
}
void BaseObject::init(const char *file, int xPos, int yPos, int width, int height)
{
    SDL_Surface *surface = IMG_Load(file);
    objTexture = SDL_CreateTextureFromSurface(renderer, surface);
    if (objTexture == NULL)
    {
        std::cout << "Error";
        exit(0);
    }
    dst_Rect.x = xPos;
    dst_Rect.y = yPos;
    dst_Rect.w = width;
    dst_Rect.h = height;
    SDL_FreeSurface(surface);
}
bool Object_Collison(const BaseObject *object1, const BaseObject *object2)
{
    const SDL_Rect rect1 = object1->GetRect();
    const SDL_Rect rect2 = object2->GetRect();
    if (SDL_HasIntersection(&(rect1), &(rect2)) == SDL_TRUE) return true;
    return false;
}
#endif