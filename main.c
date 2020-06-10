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
    int hauteur_fenetre = 700,
        largeur_fenetre = 1100;



    SDL_Init(SDL_INIT_VIDEO);

    //FENETRE PRINCIPALE
    SDL_Surface *screen = NULL;
    screen = SDL_SetVideoMode(largeur_fenetre, hauteur_fenetre, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Avaritia", NULL); // titre de la fenetre

//afficher le menu
    int action =-1;
 int c =-1;
    do
    {if (c!=-1) {action=c;c=-1;}
if (c==-1 && action != 0) 
afficher_menu(screen , &action );
    switch (action)
{
case 1:
stage1(screen, &c);
break;
case 2 :
 afficher_option( screen, &c );
break;
case 3 :
//credit
break;

}



    }while (action != 0);

    SDL_Quit();
    return 0;
}
