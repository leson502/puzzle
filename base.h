#ifndef H_BASE
#define H_BASE

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#define WINDOW_TITTLE "8Puzzle"

const unsigned int SCREEN_WIDTH = 1280;
const unsigned int SCREEN_HEIGHT = 720;
const unsigned int BLOCKSIZE = 220;
const unsigned int PUZZLEZONE = 660;
const unsigned int PUZZLE_ORIGIN_X = 310;
const unsigned int PUZZLE_ORIGIN_Y = 30;
const unsigned int FONT_SIZE = 20;

void logSDLerror(std::ostream &os,std::string msg, bool fatal);
void logGeneralError(std::ostream &os,std::string msg, bool fatal);
void swap(int *A, int *B);
int max(const int A, const int B);
int min(const int A, const int B);
void setRect(SDL_Rect* rect,const int x, const int y, const int w, const int h);
int abs(int A);

#endif