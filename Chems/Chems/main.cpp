//
//  main.cpp
//  Chems
//
//  Created by Lilly Fiorino on 6/26/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "SDL_Init.h"


int main( int argc, char* args[] )
{
    if( !init() ){ printf( "Failed to initialize!\n" ); }
    else
    {
        if( !loadMedia() ){ printf( "Failed to load media!\n" ); }
        else
        {
            bool quit = false;
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
                        }
                    }
                }
                SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );
                SDL_RenderClear( gRenderer );
                
                
                //Render current frame
                gTextTexture.render( ( SCREEN_WIDTH - gTextTexture.getWidth() ) / 2, ( SCREEN_HEIGHT - gTextTexture.getHeight() ) / 2 );

                
                SDL_RenderPresent( gRenderer );
            }
        }
        close();
        return 0;
    }
}
