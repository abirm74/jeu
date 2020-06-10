#ifndef pause_H_INCLUDED
#define pause_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#include "option.h"


int quit_pause (SDL_Surface *ecran);

void pause(SDL_Surface *screen,int *action);




  #endif // DS_H_INCLUDED