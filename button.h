#ifndef H_BUTTON
#define H_BUTTON

#include "base.h"
#include "base_object.h"
#include "destination_structure.h"
#include "event.h"

enum{
    HOVERED_NORMAL, HOVERED_FADE, HOVERED_LARGER
};

class Button : public Base_object, public Destination_structure
{
protected:
    bool hovered,clicked;
    int hoverEffect;
public:
    Button();
    Button(SDL_Renderer *render_target);
    Button(SDL_Renderer *render_target, std::string filename);
    Button(int x,int y,int w, int h);
    Button(SDL_Renderer *render_target, std::string filename,int x,int y,int w,int h);
    ~Button();
    void Init();
    void blit();
    void SetAlphaMod(const int a);
    bool checkHitBox(int x,int y);
    void loadTexture(std::string filename);
    void MouseProcess(const int x,const int y,const bool m_click);
    bool isClicked();
    bool isHovered();
    void setHoverEffect(int t_hoverEffect);
    SDL_Texture* getTexture();
    void destroy();
};

#endif