#include "entite.h"

int nb_frames_e = 15,
    down=0,up=0,
    max_down=500 , max_up=100;


void init_tab_anim_entite(SDL_Rect *clip)
{
    //vers droite
    clip[0].x = 0;
    clip[0].y = 0;
    clip[0].w = 100;
    clip[0].h = 100;
    int i = 1;
    for (i = 1; i < nb_frames_e; i++)
    {
        clip[i].w = 100;
        clip[i].h = 100;
        clip[i].x = clip[i].w + clip[i - 1].x;
        clip[i].y = 0;
    }

    //vers gauche
    clip[15].x = 0;
    clip[15].y = 100;
    clip[15].w = 100;
    clip[15].h = 100;
    i = 16;
    for (i = 16; i < (2 * nb_frames_e); i++)
    {
        clip[i].w = 100;
        clip[i].x = clip[i - 1].x + clip[i].w;
        clip[i].y = 100;
        clip[i].h = 100;
    }
    //stable right
    clip[30].x = 0;
    clip[30].y = 200;
    clip[30].w = 100;
    clip[30].h = 100;
    i = 31;
    for (i = 31; i < (3 * nb_frames_e); i++)
    {
        clip[i].w = 100;
        clip[i].x = clip[i - 1].x + clip[i].w;
        clip[i].y = 200;
        clip[i].h = 100;
    }

    //stable right
    clip[45].x = 0;
    clip[45].y = 300;
    clip[45].w = 100;
    clip[45].h = 100;
    i = 46;
    for (i = 46; i < (4 * nb_frames_e); i++)
    {
        clip[i].w = 100;
        clip[i].x = clip[i - 1].x + clip[i].w;
        clip[i].y = 300;
        clip[i].h = 100;
    }
}

void initialiser_entite(entite *e)
{
    e->entite = IMG_Load("graphic/air-guy.png");
    e->entite_pos.x = 900;
    e->entite_pos.y = 100;
    init_tab_anim_entite(e->animation_entite);
    e->frame_entite=0;
    e->type=1;
e->col=0;
}

void detect_collision(personnage *p, entite* e){
  if (e->col==0){
if ((p->perso_pos.x + p->perso_pos. w< e->entite_pos. x) || (p->perso_pos.x> e->entite_pos. x + e->entite_pos. w) ||
(p->perso_pos.y + p->perso_pos.h< e->entite_pos. y) || (p->perso_pos.y> e->entite_pos. y + e->entite_pos. h ))
e->col= 0;
else
e->col=1;
}

}

void afficher_entite(entite * e , SDL_Surface *screen)
{

   SDL_BlitSurface(e->entite,&e->animation_entite[e->frame_entite], screen, &e->entite_pos);



}

void anim(entite *e)
{    e->frame_entite++;
    if (e->frame_entite <0 || e->frame_entite > 14)
       e->frame_entite=0;

}

void mvt_entite(entite *e)
{
if(e->entite_pos.y<=max_up){
  down=1;
  up=0;}
if(e->entite_pos.y>=max_down){
  down=0;
  up=1;}

  if (up==1) e->entite_pos.y--;
  if (down==1) e->entite_pos.y++;

}
