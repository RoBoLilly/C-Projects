/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
 and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;

#include "SDL_Functions.h"

void SDL_RenderDrawTriangle(SDL_Renderer* &gRenderer, int a1, int a2 , int b1, int b2, int c1, int c2);
void rainbowColor(SDL_Renderer* &gRenderer, int  i);
void rainbowTriangle(SDL_Renderer* &gRenderer, int  i);

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Main loop flag
            bool quit = false;
            
            //Event handler
            SDL_Event e;
            
            //While application is running
            while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                }
                
                //Clear screen
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );

                SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF);
                
                SDL_RenderDrawTriangle( gRenderer, 345, 433, 217, 430, 470, 572);
                SDL_RenderDrawTriangle( gRenderer, 345, 433, 217, 430, 227, 382);
                
                //Update screen
                SDL_RenderPresent( gRenderer );
                
//                //Draw vertical line
//                SDL_SetRenderDrawColor( gRenderer, 0x)), 0xFF, 0x00, 0xFF );
//                for( int i = 0; i < SCREEN_HEIGHT; i += 4 )
//                {
//                    SDL_RenderDrawPoint( gRenderer, SCREEN_WIDTH / 2, i );
//                }
                
            }
        }
    }
    
    //Free resources and close SDL
    close();
    
    return 0;
}

void SDL_RenderDrawTriangle(SDL_Renderer* &gRenderer, int a1, int a2 , int b1, int b2, int c1, int c2)
{
    SDL_RenderDrawLine( gRenderer, a1, a2, b1, b2 );
    SDL_RenderDrawLine( gRenderer, b1, b2, c1, c2 );
    SDL_RenderDrawLine( gRenderer, c1, c2, a1, a2 );
}

int rainRed = 255;
int rainGreen = 0;
int rainBlue = 0;
int rainMode = 0;

void rainbowColor(SDL_Renderer* &gRenderer, int  i)
{
    switch (rainMode) {
        case 0:
            rainGreen += i;
            if(rainGreen >= 255){rainMode = 1;}
            break;
        case 1:
            rainRed -= i;
            if(rainRed <= 0){rainMode = 2;}
            break;
        case 2:
            rainBlue += i;
            if(rainBlue >= 255){rainMode = 3;}
            break;
        case 3:
            rainGreen -= i;
            if(rainGreen <= 0){rainMode = 4;}
            break;
        case 4:
            rainRed += i;
            if(rainRed >= 255){rainMode = 5;}
            break;
        case 5:
            rainBlue -= i;
            if(rainBlue <= 0){rainMode = 0;}
            break;
        default:
            rainMode = 0;
            break;
    }
    SDL_SetRenderDrawColor( gRenderer, rainRed, rainGreen, rainBlue, 255 );
}

int a1 = 144;
int a2 = 23;
int b1 = 234;
int b2 = 223;
int c1 = 155;
int c2 = 345;
int state = 0;

void rainbowTriangle(SDL_Renderer* &gRenderer, int  i)
{
//    switch (state) {
//        case 0:
//            a1 += i;
//            if(a1 >= 255){state = 1;}
//            break;
//        case 1:
//            a2 -= i;
//            if(a2 <= 0){state = 2;}
//            break;
//        case 2:
//            b1 += i;
//            if(b1 >= 255){state = 3;}
//            break;
//        case 3:
//            b2 -= i;
//            if(b2 <= 0){state = 4;}
//            break;
//        case 4:
//            c1 += i;
//            if(c1 >= 255){state = 5;}
//            break;
//        case 5:
//            c2 -= i;
//            if(c2 <= 0){state = 0;}
//            break;
//        default:
//            state = 0;
//            break;
//    }
}



