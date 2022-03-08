#include "base.h"

class Event
{
private:
    int mouse_x, mouse_y;
    bool LbuttonDown;
    bool App_quit;
public:
    Event();
    void updateEvent();
    void defaultEvent();
    void doMouseButtonDown(SDL_MouseButtonEvent *event);
    int MousePosX();
    int MousePosY();
    bool isLbuttonDown();
    bool isQuit();
};
 