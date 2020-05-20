#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include"option.h"
#include"menu.h"
#include"st1.h"



int main()
{
    int hauteur_fenetre = 800,
        largeur_fenetre = 1100;

   

    SDL_Init(SDL_INIT_VIDEO);

    //FENETRE PRINCIPALE
    SDL_Surface *screen = NULL;
    screen = SDL_SetVideoMode(largeur_fenetre, hauteur_fenetre, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("My Game", NULL); // titre de la fenetre

    //afficher le menu
    int menu=-1;

    do 
    {
menu=afficher_menu(screen);
    switch (menu)
{
case 1: 
stage1(screen);
break;
case 2 :

 afficher_option( screen);
break;
case 3 :
//credit 
break;

}


  
    }while (menu!=0);
   
    SDL_Quit();

    return 0;
}
