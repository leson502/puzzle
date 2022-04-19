#include "puzzlebar.h"

PuzzleBar::PuzzleBar()
{
    memAllocate();
    defaultBar();
}
void PuzzleBar::memAllocate()
{
    border = new SDL_Rect;
    UpButton = new Object;
    DownButton = new Object;
}
void PuzzleBar::loadObject()
{
    std::string filename = "gfx/puzzle_.png";
    for (char c = '1'; c<='5'; c++)
    {
        filename[10] = c;
        Object *object = new Object;
        object->setRender_target(renderer);
        object->loadTexture(filename);
        puzzlelist.push_back(object);
    }
    filename = "gfx/uparrow.png";
    UpButton->loadTexture(filename);
    filename = "gfx/downarrow.png";
    DownButton->loadTexture(filename);
    top = 0;
    current = 0;
}
void PuzzleBar::defaultBar()
{
    setRect(border,BAR_ORIGIN_X, BAR_ORIGIN_Y, BAR_WIDTH, BAR_HEIGHT);
    UpButton->setPos(UPBUTTON_X, UPBUTTON_Y);
    UpButton->setSize(BUTTON_W,BUTTON_H);
}

void PuzzleBar::Blit()
{
    
    for(int i=0; i<DISPLAY_OBJECT_NUM; i++)
        {
            puzzlelist[i+top]->setPos(BAR_ORIGIN_X,BAR_ORIGIN_Y+i*BAR_WIDTH);
            puzzlelist[i+top]->setSize(BAR_WIDTH, BAR_WIDTH);
            puzzlelist[i+top]->blit();
        }
    UpButton->blit();
    SDL_RenderDrawRect(renderer, border);
    SDL_RenderDrawLine(renderer, BAR_ORIGIN_X,BAR_ORIGIN_Y+BAR_WIDTH,
                        BAR_ORIGIN_X+BAR_WIDTH, BAR_ORIGIN_Y+BAR_WIDTH);
    SDL_RenderDrawLine(renderer, BAR_ORIGIN_X,BAR_ORIGIN_Y+BAR_WIDTH*2,
                        BAR_ORIGIN_X+BAR_WIDTH, BAR_ORIGIN_Y+BAR_WIDTH*2);
}

void PuzzleBar::move(int x)
{
    top=max(min(top+x,OBJECT_NUM-DISPLAY_OBJECT_NUM),0);
}

bool PuzzleBar::MouseProcess(const int x, const int y, const bool clicked)
{
    if (hitBoxCheck(x,y,UPBUTTON_X, UPBUTTON_Y, BUTTON_W, BUTTON_H) && clicked)
    {
        move(1);
    }
    if (hitBoxCheck(x,y, BAR_ORIGIN_X, BAR_ORIGIN_Y, BAR_WIDTH, BAR_WIDTH*3))
        {
            int i = (y-BAR_ORIGIN_Y)/BAR_WIDTH;
            if (clicked)
            {
                current = i + top;
                return 1;
            }
        }
    return 0;
}

SDL_Texture *PuzzleBar::GetNewTexture()
{
    return puzzlelist[current]->getTexture();
}

PuzzleBar::~PuzzleBar()
{
    delete border;
    for (Object* v:puzzlelist) delete v;
    puzzlelist.clear();
}

void PuzzleBar::setRender_target(SDL_Renderer *render_target)
{
    renderer = render_target;
    UpButton->setRender_target(renderer);
}