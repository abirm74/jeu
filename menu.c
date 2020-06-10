#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "option.h"

int sort (SDL_Surface *ecran)
{
	SDL_Surface *bg,*exit[5];
	int n=0,t,done=1;
	SDL_Rect pos;
	SDL_Event event;
	pos.x=0;
	pos.y=0;
	bg=IMG_Load("graphic/menubnp.jpg");
	exit[4]=IMG_Load("graphic/menu/exit_msg.png");
    exit[0]=IMG_Load("graphic/menu/exit_msg_yes_selected.png");
	exit[1]=IMG_Load("graphic/menu/exit_msg_no_selected.png");
	exit[2]=IMG_Load("graphic/menu/exit_msg_yes_clicked.png");
	exit[3]=IMG_Load("graphic/menu/exit_msg_no_clicked.png");

    while(done)
    {
    	SDL_BlitSurface(bg,NULL,ecran,&pos);
    	SDL_BlitSurface(exit[n],NULL,ecran,&pos);
    	SDL_Flip(ecran);
    	SDL_WaitEvent(&event);
    	t=0;
    	switch(event.type)
    	{
			//avec clavier
    		case SDL_KEYDOWN:

    			switch(event.key.keysym.sym)
    			{
    				case SDLK_LEFT:
    				if (n==4) n=0;
						if (n==0 && t==0)
						{
							n++;
							t=1;
						}
						else if (n==1 && t==0)
						{
							n--;
							t=1;
						}
					break;

					case SDLK_RIGHT:
					if (n==4) n=0;
						if (n==0 && t==0)
						{
							n++;
							t=1;
						}
						else if (n==1 && t==0)
						{
							n--;
							t=1;
						}
					break;

					case SDLK_RETURN:
						if (n==0)
						{SDL_BlitSurface(exit[2],NULL,ecran,&pos);
    						SDL_Flip(ecran);
    				SDL_Delay (200);
							SDL_FreeSurface(bg);
							SDL_FreeSurface(exit[n]);
							return 1;
						}
						else if (n==1)
						{SDL_BlitSurface(exit[3],NULL,ecran,&pos);
    						SDL_Flip(ecran);
    				SDL_Delay (200);
							SDL_FreeSurface(bg);
							SDL_FreeSurface(exit[n]);
							return 0;
						}
					break;

    			}
    		break;
// avec souris

    		case SDL_MOUSEMOTION:
			n=4;
				if (event.motion.x>317 && event.motion.y>312 && event.motion.x<488 && event.motion.y<392)
				{
					n=0;
				}
				else if (event.motion.x>521 && event.motion.y>312 && event.motion.x<699 && event.motion.y<392)
				{
					n=1;
				}
			break;

			case SDL_MOUSEBUTTONDOWN:
				if (event.motion.x>317 && event.motion.y>312 && event.motion.x<488 && event.motion.y<392)
				{
					SDL_BlitSurface(exit[2],NULL,ecran,&pos);
    						SDL_Flip(ecran);
    				SDL_Delay (200);
					return 1;
				}
				else if (event.motion.x>521 && event.motion.y>312 && event.motion.x<699 && event.motion.y<392 )
				{
					SDL_BlitSurface(exit[3],NULL,ecran,&pos);
    						SDL_Flip(ecran);
    				SDL_Delay (200);
					return 0;
				}
			break;

    	}
    }

}


int afficher_menu(SDL_Surface *screen , int *action )
{
int volume=get_volume();
    int hb = 100, //3olw boutton
        lb = 300, //3orth boutton
        bs = 30;  // espace bin les bouttons
    int f = 0;
int g=-1 ; 
    Mix_Chunk  *music1;
    Mix_AllocateChannels(1);
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
        printf("%s", Mix_GetError());
    }
    music1 = Mix_LoadWAV("graphic/ClicDeSouris.wav");
Mix_Music *music;
music= Mix_LoadMUS("graphic/music.mp3");
Mix_VolumeMusic(volume);
Mix_PlayMusic(music,-1);

    int tmp = 0, m = 0;

    //creation background
    SDL_Surface *background = NULL;
    background = IMG_Load("graphic/menubnp.jpg");
    // detreminerr pos de back
    SDL_Rect background_pos;
    background_pos.x = 0;
    background_pos.y = 0;

    
    //creation bouton start
    SDL_Surface *start[3];
    start[0] = IMG_Load("graphic/button_start.png");
    start[1] = IMG_Load("graphic/button_start2.png");
    start[2] = IMG_Load("graphic/button_start1.png");
    int ng = 0;
    //pos buton start
    SDL_Rect start_pos;
    start_pos.x = 100;
    start_pos.y = 50;

    //creation bouton credit
    SDL_Surface *credit[3];
    credit[0] = IMG_Load("graphic/button_credit.png");
    credit[1] = IMG_Load("graphic/button_credit2.png");
    credit[2] = IMG_Load("graphic/button_credit1.png");
    int cr = 0;
    //pos buton credit
    SDL_Rect credit_pos;
    credit_pos.x = 100;
    credit_pos.y = start_pos.y + hb + bs;

    //creation bouton option
    SDL_Surface *setting[3];
    setting[0] = IMG_Load("graphic/button_settings.png");
    setting[1] = IMG_Load("graphic/button_settings2.png");
    setting[2] = IMG_Load("graphic/button_settings1.png");
    int op = 0;
    //pos buton option
    SDL_Rect setting_pos;
    setting_pos.x = 100;
    setting_pos.y = credit_pos.y + hb + bs;

    //creation bouton quit
    SDL_Surface *quit[3];
    quit[0] = IMG_Load("graphic/button_quit.png");
    quit[1] = IMG_Load("graphic/button_quit2.png");
    quit[2] = IMG_Load("graphic/button_quit1.png");
    int ex = 0;
    //pos buton quit
    SDL_Rect quit_pos;
    quit_pos.x = 100;
    quit_pos.y = setting_pos.y + hb + bs;

        int t1 = 0, t2 = 0, r = 0;

   

    int t = 0;
    SDL_Event event;
    int done = 1;
    while (done)
    {
      
        t = 0;
        if (SDL_PollEvent(&event)) // ki ninzel ala ay haja
        {
            switch (event.type) //tal9a type el 7aja
            {
            ////////////////////////////////////////////////////////////////////////////////////////////////////////
            ////////////////////////////////////////////////////////////////////////////////////////////////////////
            case SDL_QUIT: //nenzel 3al (X) el 7amra
                done = 0;
                break;
            ////////////////////////////////////////////////////////////////////////////////////////////////////////
            ////////////////////////////////////////////////////////////////////////////////////////////////////////
            //avec clavier
            case SDL_KEYDOWN:                 // ay haja fil clav
                switch (event.key.keysym.sym) // taref type l haja l nzalt alaha fil clav
                {
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                case SDLK_q: //q
                    done = 0;
                    break;
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                case SDLK_UP: //flech fou9ani
                    if (ng == 0 && cr == 0 && op == 0 && ex == 0)
                    {
                        ng = 1;
                    }
                    else if (ng == 1 && t == 0)
                    {
                        ex = 1;
                        ng = 0;
                        cr = 0;
                        op = 0;
                        t = 1;
                    }
                    else if (cr == 1 && t == 0)
                    {
                        ng = 1;
                        cr = 0;
                        op = 0;
                        ex = 0;
                        t = 1;
                    }
                    else if (op == 1 && t == 0)
                    {
                        ng = 0;
                        cr = 1;
                        op = 0;
                        ex = 0;
                        t = 1;
                    }
                    else if (ex == 1 && t == 0)
                    {
                        op = 1;
                        cr = 0;
                        ex = 0;
                        ng = 0;
                        t = 1;
                    }
                    break;
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                case SDLK_DOWN: //flech loutani
                    if (ng == 0 && cr == 0 && op == 0 && ex == 0)
                    {
                        ng = 1;
                    }
                    else if (ng == 1 && t == 0)
                    {
                        ex = 0;
                        ng = 0;
                        cr = 1;
                        op = 0;
                        t = 1;
                    }
                    else if (cr == 1 && t == 0)
                    {
                        ng = 0;
                        cr = 0;
                        op = 1;
                        ex = 0;
                        t = 1;
                    }
                    else if (op == 1 && t == 0)
                    {
                        ng = 0;
                        cr = 0;
                        op = 0;
                        ex = 1;
                        t = 1;
                    }
                    else if (ex == 1 && t == 0)
                    {
                        op = 0;
                        cr = 0;
                        ex = 0;
                        ng = 1;
                        t = 1;
                    }
                    break;
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                case SDLK_RETURN: //entree
                    if (ng == 1)
                    {
                        SDL_BlitSurface(start[2], NULL, screen, &start_pos);
                        SDL_Flip(screen);
                        Mix_PlayChannel(1, music1, 0);
                        SDL_Delay(100);
                       (*action)=1;
                       g=0; 
                    }
                    else if (cr == 1)
                    {
                        SDL_BlitSurface(credit[2], NULL, screen, &credit_pos);
                        SDL_Flip(screen);
                        Mix_PlayChannel(1, music1, 0);
                        SDL_Delay(100);
                        (*action)=3;
                        g=0; 
                    }
                    else if (op == 1)
                    {
                        SDL_BlitSurface(setting[2], NULL, screen, &setting_pos);
                        SDL_Flip(screen);
                        Mix_PlayChannel(1, music1, 0);
                        SDL_Delay(100);
                       (*action)=2;
                       g=0 ;
                    }
                    else if (ex == 1)
                    {
                        SDL_BlitSurface(quit[2], NULL, screen, &quit_pos);
                        SDL_Flip(screen);
                        Mix_PlayChannel(1, music1, 0);
                        SDL_Delay(100);
                       if (sort(screen)==1)
                        {


								(*action)=0 ;
                                g=0 ; 
                                }
                     
                    }
                    break;
               
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
                ////////////////////////////////////////////////////////////////////////////////////////////////////////
              
                case SDLK_F8: //full screen
                    if (f == 0)
                    {
                        screen = SDL_SetVideoMode(1000, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
                        f = 1;
                    }
                    else if (f == 1)
                    {
                        screen = SDL_SetVideoMode(1100, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                        f = 0;
                    }
                    break;
                }
                break;
            ////////////////////////////////////////////////////////////////////////////////////////////////////////
            ////////////////////////////////////////////////////////////////////////////////////////////////////////
            //avec souris
            case SDL_MOUSEMOTION:
                ex = 0;
                ng = 0;
                cr = 0;
                op = 0;
                if (event.motion.x > start_pos.x && event.motion.y > start_pos.y && event.motion.x < start_pos.x + lb && event.motion.y < start_pos.y + hb)
                {
                    ng = 1;
                }
                else if (event.motion.x > credit_pos.x && event.motion.y > credit_pos.y && event.motion.x < credit_pos.x + lb && event.motion.y < credit_pos.y + hb)
                {
                    cr = 1;
                }
                else if (event.motion.x > setting_pos.x && event.motion.y > setting_pos.y && event.motion.x < setting_pos.x + lb && event.motion.y < setting_pos.y + hb)
                {
                    op = 1;
                }
                else if (event.motion.x > quit_pos.x && event.motion.y > quit_pos.y && event.motion.x < quit_pos.x + lb && event.motion.y < quit_pos.y + hb)
                {
                    ex = 1;
                }
                break;

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (ng == 1)
                    {
                        ng = 2;
                        Mix_PlayChannel(1, music1, 0);
                        SDL_Delay(500);
                       (*action)=1;
                       g=0 ; 
                    }
                    else if (cr == 1)
                    {
                        cr = 2;
                        Mix_PlayChannel(1, music1, 0);
                        SDL_Delay(500);
                       (*action)=3;
                       g=0 ; 
                    }
                    else if (op == 1)
                    {
                        op = 2;
                        Mix_PlayChannel(1, music1, 0);
                        SDL_Delay(500);
                       (*action)=2;
                       g=0 ; 
                    }
                    else if (ex == 1)
                    {
                        SDL_BlitSurface(quit[2], NULL, screen, &quit_pos);
                        SDL_Flip(screen);
                        SDL_Delay(600);
                        if (sort(screen)==1){
								(*action)=0;
                                g=0; }
                     
                    }
                   
                }
                break;

            } //fin switch event
        }     //fin pollevent

        //afficher back
        SDL_BlitSurface(background, NULL, screen, &background_pos);
        SDL_BlitSurface(quit[ex], NULL, screen, &quit_pos);
        SDL_BlitSurface(start[ng], NULL, screen, &start_pos);
        SDL_BlitSurface(credit[cr], NULL, screen, &credit_pos);
        SDL_BlitSurface(setting[op], NULL, screen, &setting_pos);
  //boucle animate

       
         /*   SDL_BlitSurface(animation[r], NULL, screen, NULL);
                r++;
                if (r==9) r=0;*/
    
        SDL_Flip(screen);
if (g==0) break;
    } //fin while


Mix_FreeChunk(music1);
    SDL_FreeSurface(background);
    SDL_FreeSurface(start[2]);
    SDL_FreeSurface(setting[2]);
    SDL_FreeSurface(quit[2]);
    SDL_FreeSurface(start[0]);
    SDL_FreeSurface(start[1]);
    SDL_FreeSurface(setting[0]);
    SDL_FreeSurface(setting[1]);
    SDL_FreeSurface(credit[0]);
    SDL_FreeSurface(credit[1]);
    SDL_FreeSurface(credit[2]);
    SDL_FreeSurface(quit[0]);
    SDL_FreeSurface(quit[1]);
}


