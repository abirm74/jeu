#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct {
SDL_Surface *perso ; // nsob feha taswiret perso
SDL_Rect perso_pos; // pos du perso dans fenetre
SDL_Rect animation[60];
int frame; // pour parcourir tab animation : taswira 1 / 2 / 3 ....
int direction; //right = 0 ; left =1
int stable; // vrai = 1 ; faux=0
}personnage ;

void init_tab_anim(SDL_Rect* clip); //t3abi tab animation
void initialiser (personnage *p) ;
void afficher_perso(personnage * p , SDL_Surface *screen);
void anim_right(personnage *p);
void anim_left(personnage *p);
void anim_stable(personnage *p);

#endif 