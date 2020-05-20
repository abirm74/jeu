
#include "st1.h"

int mvtx = 10,
    mvty = 10;
int stage1(SDL_Surface *screen)
{
        TTF_Init();
        background b;
        initialiserr(&b);

        int m = 0;

        personnage p;
        entite e;
        initialiser_entite(&e);
        initialiser(&p);
        //CREATION TEXTE

        TTF_Font *police = NULL;
        police = TTF_OpenFont("graphic/font.ttf", 40);
        SDL_Color couleur = {255, 255, 255}; //red green blue
        SDL_Surface *texte = NULL;
        texte = TTF_RenderText_Solid(police, "stage 1", couleur); //texte yetbadal solid //shaded texte mayetbadalech fon uni// blanded texte mayetbadalech fond image barcha couleurs

        //pos texte
        SDL_Rect texte_pos;
        texte_pos.x = 50;
        texte_pos.y = 50;

        SDL_EnableKeyRepeat(200, 0);
        SDL_Event event;

        int done = 1;
        while (done)
        {
                p.stable=1;

                if (SDL_PollEvent(&event)) // ki ninzel ala ay haja
                {
                        switch (event.type) //tal9a type el 7aja
                        {

                        case SDL_QUIT: //nenzel 3al (X) el 7amra
                                done = 0;
                                break;

                        //avec clavier
                        case SDL_KEYDOWN:                     // ay haja fil clav
                                switch (event.key.keysym.sym) // taref type l haja l nzalt alaha fil clav
                                {

                                case SDLK_ESCAPE: //echap
                                        done = 0;
                                        break;
                                case SDLK_RIGHT: //flech right
                                        p.stable=0;
                                        m = scrol_right(&b, screen, &e);
                                        if (m == 1  )
                                        if (p.perso_pos.x < 1000)
                                                p.perso_pos.x += mvtx;
                                    p.direction=0;
                                        anim_right(&p);
                                        break;

                                case SDLK_LEFT: //flech left
                                        p.stable=0;
                                        m = scrol_left(&b, screen, &e);
                                        if (m == 1)
                                                p.perso_pos.x -= mvtx;
                                                  p.direction=1;
                                        anim_left(&p);

                                        break;
                                case SDLK_UP: //flech fou9
                                        p.perso_pos.y -= mvty;
                                        break;

                                case SDLK_DOWN: //flech louta
                                        p.perso_pos.y += mvty;
                                        break;
                                }
                        } //fin switch

                } //fin if
                m = 0;
                detect_collision(&p, &e);
                //afficher back
                anim(&e);
                mvt_entite(&e);
                affiche_back(&b, screen);

                detect_collision(&p, &e);
                if (e.col == 0)
                    afficher_entite(&e, screen);
                if (p.stable==1)
                    anim_stable(&p);
                afficher_perso(&p, screen);
                SDL_BlitSurface(texte, NULL, screen, &texte_pos);
                SDL_Flip(screen);
        } //fin while

        SDL_FreeSurface(b.back);
        SDL_FreeSurface(p.perso);
        SDL_FreeSurface(texte);
        TTF_CloseFont(police);
        TTF_Quit();

} //fin fct
