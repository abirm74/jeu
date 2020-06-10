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
SDL_Surface *perso ;
SDL_Rect perso_pos,perso_pos_relative; 
SDL_Rect animation[60];
int frame;
int direction; //right = 0 ; left =1
int stable; // vrai = 1 ; faux=0
int vie;
int score;
int x1,x2,x3,x4,x5,x6,x7,x8,x9; //pt collision avec mask
int y1,y2,y3,y4,y5,y6,y7,y8,y9; //pt collision avec mask
int nb_perso;

}personnage ;
// pointeurrrrr
typedef struct {
SDL_Surface *point ; // nsob feha taswiret perso
SDL_Rect point_pos,point_pos_relative; // pos du perso dans fenetre
}pointeur ;


void init_tab_anim(SDL_Rect* clip); //t3abi tab animation
void initialiser (personnage *p, pointeur *pt , int x) ;
void afficher_perso(personnage * p , pointeur *pt , SDL_Surface *screen);
void anim_right(personnage *p);
void anim_left(personnage *p);
void anim_stable(personnage *p);
void mvt_perso_droite(personnage *p, pointeur *pt , int mvtx);
void mvt_perso_gauche(personnage *p, pointeur *pt , int mvtx);
int gameover(personnage *p);


#endif
