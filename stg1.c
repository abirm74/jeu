
#include "st1.h"

int mvtx = 10,
    mvty = 10;
int stage1(SDL_Surface *screen,int *action)
{
        TTF_Init();
        background b;
        initialiserr(&b);

int a=1,a2=1; //enregistre le retour de la gestion vie et score



int touch_down=0;

        personnage p ;
        pointeur pt ;
        entite e;
        initialiser_entite(&e);
        initialiser(&p,&pt,1);
        personnage p2;
      initialiser(&p2,&pt,2);
        //CREATION TEXTE

        TTF_Font *police = NULL;
        police = TTF_OpenFont("graphic/font.ttf", 40);
        SDL_Color couleur = {255, 255, 255}; //red green blue
        SDL_Surface *texte = NULL;
        texte = TTF_RenderText_Solid(police, "stage 1", couleur); //texte yetbadal solid //shaded texte mayetbadalech fon uni// blanded texte mayetbadalech fond image barcha couleurs

        //pos texte
        SDL_Rect texte_pos;
        texte_pos.x = 50;
        texte_pos.y = 30;

vie_perso val_vie;
init_vie(&val_vie,1);
vie_perso val_vie2;
init_vie(&val_vie2,2);
score_perso val_score;
init_score(&val_score,1);
score_perso val_score2;
init_score(&val_score2,2);





        SDL_EnableKeyRepeat(200, 0);
        SDL_Event event;

        int done = 1;
        while (done)
        {

          update_point_collision(&p);
        update_point_collision(&p2);

                p.stable=1;
                p2.stable=1;

                if (SDL_PollEvent(&event)) // ki ninzel ala ay haja
                {
                        switch (event.type) //tal9a type el 7aja
                        {

                        case SDL_QUIT: //nenzel 3al (X) el 7amra
                            (*action)=0;
                                done = 0;
                                 break ; 
                        //avec clavier
                        case SDL_KEYDOWN:                     // ay haja fil clav
                                switch (event.key.keysym.sym) // taref type l haja l nzalt alaha fil clav
                                {

                                case SDLK_ESCAPE: //echap
                                        pause(screen , action);
				get_volume() ;
         (*action)=0;
                                        break ;

                                case SDLK_RIGHT: //flech right
                               if (scrol_right(&b, screen, &p , mvtx))
                                      mvt_perso_droite(&p,&pt,mvtx);
                                  
                                        break;

                                case SDLK_LEFT: //flech left
                                     if (scrol_left(&b, screen , &p , mvtx))
                                      mvt_perso_gauche(&p , &pt, mvtx) ;
                                        break;
                                case SDLK_UP: //flech fou9
                                      p.perso_pos.y -= mvty ;
                                      pt.point_pos.y -= (mvty/5);

                                        break;

                                       
                                     case SDLK_DOWN: //flech fou9
                                       p.perso_pos.y += mvty;
                                       pt.point_pos.y += (mvty/5);
                                                break;   
                                       
                                       
                                       
                         //deuxieme personnage              


                                        case SDLK_d: //flech right
                                        if (scrol_right(&b, screen,&p2 , mvtx))
                                      mvt_perso_droite(&p2, &pt,mvtx);
                                      break;

                                        case SDLK_q: //flech left
                                        if (scrol_left(&b, screen , &p2 , mvtx))
                                        mvt_perso_gauche(&p2,&pt,mvtx);
                                          break;
                                        case SDLK_z: //flech fou9
                                          p2.perso_pos.y -= mvty;
                                        break;
                                        case SDLK_x: //flech 
                                       p2.perso_pos.y += mvty;
                                                break;
                                                



                                }


                        } //fin switch

                } //fin if








//collision parfaite avec background
      update_perfect_collision(&p,&b);
    update_perfect_collision(&p2,&b);

//mise a jour entite
  mise_a_jour_entite(&e,p.perso_pos.x);

//gestion vie et score apres collision avec entite
  e.col=0;
          if(detect_collision(&p, &e))
                a=gestion_vie_score(&p,&pt,&e,&b);
 e.col=0;
          if(detect_collision(&p2, &e))
                a2=gestion_vie_score(&p2,&pt,&e,&b);

//animation stable perso
if (p.stable==1)
    anim_stable(&p);

if (p2.stable==1)
    anim_stable(&p2);


  affiche_back(&b, screen);
afficher_map(screen ) ;
  if(a) //meme que if (a==1)
     afficher_entite(&e,screen);

afficher_vie_score(&p,screen,&val_score,&val_vie,1);
afficher_vie_score(&p2,screen,&val_score2,&val_vie2,2);

                afficher_perso(&p,&pt, screen);
        afficher_perso(&p2, &pt, screen   );

                SDL_BlitSurface(texte, NULL, screen, &texte_pos);
                SDL_Flip(screen);



if (gameover(&p))
                 done=0;
if (gameover(&p2))
                done=0;


        } //fin while

        SDL_FreeSurface(b.back);
        SDL_FreeSurface(p.perso);
        SDL_FreeSurface(p2.perso);
        SDL_FreeSurface(texte);
        TTF_CloseFont(police);
        TTF_Quit();

} //fin fct
