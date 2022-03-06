#include "base.h"

class Graphic
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;

public:
    Graphic();
    void DefaultGraphic();
    SDL_Window *getWindow();
    SDL_Renderer *getRenderer();
    void InitSDL(unsigned int windowFlags,
            unsigned int rendererFlags);
    void QuitSDL();
    SDL_Texture *loadTexture(std::string& filename);
    void DrawTexture(SDL_Texture *texture, int x, int y);
    void renderPresent();
};



