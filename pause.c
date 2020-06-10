#include "pause.h"


int quit_pause (SDL_Surface *ecran)
{
	SDL_Surface *exit[5];
	int n=0,t;
	SDL_Rect pos;
	SDL_Event event;
	pos.x=0;
	pos.y=0;
	exit[4]=IMG_Load("graphic/menu/exit_msg.png");
    exit[0]=IMG_Load("graphic/menu/exit_msg_yes_selected.png");
	exit[1]=IMG_Load("graphic/menu/exit_msg_no_selected.png");
	exit[2]=IMG_Load("graphic/menu/exit_msg_yes_clicked.png");
	exit[3]=IMG_Load("graphic/menu/exit_msg_no_clicked.png");

    while(1)
    {
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
							SDL_FreeSurface(exit[n]);
							return 1;
						}
						else if (n==1)
						{SDL_BlitSurface(exit[3],NULL,ecran,&pos);
    						SDL_Flip(ecran);
    				SDL_Delay (200);
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
void pause(SDL_Surface *screen, int *action) // blit background then call pause
{

SDL_Surface *resume[2],*option[2],*exit[2],*window,*stage[3];
	int r=1,o=0,e=0,t;
	SDL_Rect pos;
	SDL_Event event;
	pos.x=0;
	pos.y=0;
	resume[0]=IMG_Load("graphic/pause/resume-normal.png");
	resume[1]=IMG_Load("graphic/pause/resume-selected.png");
	option[0]=IMG_Load("graphic/pause/option-normal.png");
	option[1]=IMG_Load("graphic/pause/option-selected.png");
window=IMG_Load("graphic/pause/window.png");
	exit[0]=IMG_Load("graphic/pause/exit-normal.png");
   exit[1]=IMG_Load("graphic/pause/exit-selected.png");

int done=1;
	while (done){
	//affichage des images
	
	SDL_BlitSurface(window,NULL,screen,&pos);
    SDL_BlitSurface(resume[r],NULL,screen,&pos);
    SDL_BlitSurface(option[o],NULL,screen,&pos);
    SDL_BlitSurface(exit[e],NULL,screen,&pos);
    SDL_Flip(screen);
SDL_Delay(16);
    	t=0;
    	if (SDL_WaitEvent(&event)){
    	switch(event.type)
{
	case SDL_QUIT :
(*action)=0;

	done=0;
	break;

    		//avec clavier
    		case SDL_KEYDOWN:
    			switch(event.key.keysym.sym)
    			{
case SDLK_ESCAPE :
done =0;
break;
    				case SDLK_UP:

						if (r==0 && o==0 && e==0)
    				{o=1;}
    					if (r==1 && t==0){

    						e=1;
    				o=0;
    						r=0;
    						t=1;

    					}
    					else if(o==1 && t==0){
									r=1;
    				o=0;
    						e=0;
    						t=1;}

    					else if (e==1 && t==0){
    						o=1;
    						r=0;
    					e=0;
    						t=1;
    					}
    				break;

    				case SDLK_DOWN:

    				if (r==0 && o==0 && e==0)
    				{e=1;}
    					if (r==1 && t==0){

                                r=0;
                                o=1;
                                e=0;
                                t=1;
	}
    					else if(o==1 && t==0){
    						r=0;
    						o=0;
    						e=1;
     						t=1;
    						}
    					else if (e==1 && t==0){
    						e=0;
    						o=0;
    						r=1;
      						t=1;
    						}


    				break;


    				case SDLK_RETURN:

    					if (r==1)
    					{
    						return;
    					}
                        else if (o==1)
                        { afficher_option(screen,action);
                         //call function option
                        }
 else if (e==1)
                        {
if (quit_pause(screen)==1)
{	
afficher_menu(screen, action );
done=0; 
}   //call function menu
                        }
    				break;
    			}
    		break;


//avec souris
   		case SDL_MOUSEMOTION:
	r=0; o=0; e=0;
    			if (event.motion.x>409 && event.motion.y>310 && event.motion.x<592 && event.motion.y<332)
    			{//pos resume
    			r=1;
    			}

    			else if (event.motion.x>409 && event.motion.y>385.5 && event.motion.x<592 && event.motion.y<411)
    			{//pos option
    				o=1;
    			}
    			else if (event.motion.x>409 && event.motion.y>456 && event.motion.x<607 && event.motion.y<478.5 )
    			{//pos exit
    				e=1;
    			}

    		break;

    		case SDL_MOUSEBUTTONDOWN:
    			if (event.button.button==SDL_BUTTON_LEFT)
    			{
    				if (r==1)
    				{
    		done=0;
    				}
    				else if (o==1)
    				{
    			//call function options
    				  afficher_option(screen, action);  				}
    				else if (e==1)
    				{
                     if (quit_pause(screen)==1)
                       
                done=0;
    			//call function menu
    				    				}
    			}
    		break;


    	}

    	}
 }

SDL_FreeSurface(window);
    	SDL_FreeSurface(resume[0]);
    	SDL_FreeSurface(resume[1]);
    	SDL_FreeSurface(option[0]);
    	SDL_FreeSurface(option[1]);
    	SDL_FreeSurface(exit[1]);
    	SDL_FreeSurface(exit[0]);
}
