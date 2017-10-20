//
//  main.cpp
//  Stan(ly)
//
//  Created by Lilly Fiorino on 6/15/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "SDL_Init.h"


int main( int argc, char* args[] )
{
    if( !init() ){ printf( "Failed to initialize!\n" ); }
    else
    {
        if( !loadMedia() ){ printf( "Failed to load media!\n" ); }
        else
        {
            //Main loop flag
            bool quit = false;
            
            //Event handler
            SDL_Event e;
            
            while( !quit ) // : GAME LOOP {
            {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    //User presses a key
                    else if( e.type == SDL_KEYDOWN )
                    {
                        //Select surfaces based on key press
                        switch( e.key.keysym.sym )
                        {
                            case SDLK_ESCAPE:
                                quit = true;
                                break;
                            case SDLK_UP:
                                break;
                        }
                        
                    }
                }
                
                //Clear screen
                SDL_RenderClear( gRenderer );
                
                //Render texture to screen
                SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
                
                //Update screen
                SDL_RenderPresent( gRenderer );
                
            }
        }
        close();
    }
    return 0;
}
