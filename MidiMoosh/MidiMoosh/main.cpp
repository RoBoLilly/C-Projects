//
//  main.cpp
//  MidiMoosh
//
//  Created by Lilly Fiorino on 7/25/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "RtMidi.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "SDL_Init.h"
#include "Map.hpp"
#include "Area.hpp"
#include "Player.hpp"
#include "RtMidi.h"
#include "BlockManager.hpp"

struct Command {
    int b0, b1, b2;
    double stamp;
    bool queued;
} command;

void mycallback( double deltatime, std::vector< unsigned char > *message, void *userData)
{
    command.b0 = (int)message->at(0);
    command.b1 = (int)message->at(1);
    command.b2 = (int)message->at(2);
    command.stamp = deltatime;
    command.queued = true;
}

int main( int argc, char* args[] )
{
    RtMidiIn *midiin = new RtMidiIn();
    // Check available ports.
    unsigned int nPorts = midiin->getPortCount();
    if ( nPorts == 0 ) {
        std::cout << "No ports available!\n";
        goto cleanup;
    }
    midiin->openPort( 0 );
    // Set our callback function.  This should be done immediately after
    // opening the port to avoid having incoming messages written to the
    // queue.
    midiin->setCallback( &mycallback );
    // Don't ignore sysex, timing, or active sensing messages.
    midiin->ignoreTypes( false, false, false );
    

    
    if( !init() ){ printf( "Failed to initialize!\n" ); }
    else
    {
        if( !loadMedia() ){ printf( "Failed to load media!\n" ); }
        else
        {
            bool quit = false;
            
            SDL_Event e;
            
            Uint32 MIDIPress = SDL_RegisterEvents(1);
            if (MIDIPress != ((Uint32)-1)) {
                SDL_Event event;
                SDL_memset(&event, 0, sizeof(event)); /* or SDL_zero(event) */
                event.type = MIDIPress;
                event.user.code = 0;
                event.user.data1 = 0;
                event.user.data2 = 0;
                SDL_PushEvent(&event);
            }
            
            Map map;
            Player player(EndArea, 2, 3);
            map.loadArea( player.getMapLocation() );
            
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
                    if( e.type == MIDIPress )
                    {
                        if (e.user.code == 46) {
                            player.move(UP, map);
                        }
                        if (e.user.code == 43) {
                            player.move(RIGHT, map);
                        }
                        if (e.user.code == 42) {
                            player.move(DOWN, map);
                        }
                        if (e.user.code == 41) {
                            player.move(LEFT, map);
                        }
                    }
                }
                if (command.queued) {
                    command.queued = false;
                    if (command.b0 == 149) {
                        SDL_Event sdlevent;
                        sdlevent.type = MIDIPress;
                        sdlevent.user.code = command.b1;
                        SDL_PushEvent(&sdlevent);
                    }
                }
                SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );
                SDL_RenderClear( gRenderer );
                
                
                for (int y=0; y<16; y++) {
                    for (int x=0; x<16; x++) {
                        
                        switch ( map.getGridID(x, y) ) {
                            case Grass:
                                SDL_SetRenderDrawColor(gRenderer, 149, 211, 0, 255);
                                break;
                                
                            case Stone:
                                SDL_SetRenderDrawColor(gRenderer, 200, 200, 200, 255);
                                break;
                                
                            case Wood:
                                SDL_SetRenderDrawColor(gRenderer, 126, 80, 20, 255);
                                break;
                                
                            default:
                                break;
                        }
                        SDL_Rect outlineRect = { x * 38 + 15, y * 38 + 80, 36, 36 };
                        SDL_RenderFillRect( gRenderer, &outlineRect );
                        if ( map.getGridRaised(x, y) == 1 ) {
                            SDL_SetRenderDrawColor(gRenderer, 0, 0, 200, 255);
                            outlineRect = { x * 38 + 23, y * 38 + 86, 20, 20 };
                            SDL_RenderFillRect( gRenderer, &outlineRect );
                        }
                        if ( player.getGridLocation(0) == x && player.getGridLocation(1) == y ) {
                            SDL_SetRenderDrawColor(gRenderer, 255, 0, 200, 255);
                            outlineRect = { x * 38 + 23, y * 38 + 86, 20, 20 };
                            SDL_RenderFillRect( gRenderer, &outlineRect );
                        }
                    }
                }
                SDL_RenderPresent( gRenderer );
            }
        }
        
    cleanup:
        delete midiin;
        close();
        return 0;
    }
}

//void mycallback( double deltatime, std::vector< unsigned char > *message, void *userData )
//{
//    unsigned int nBytes = (unsigned int)message->size();
//    
//    for ( unsigned int i=0; i<nBytes; i++ ) {
//        std::cout << "Byte " << i << " = " << (int)message->at(i) << ", ";
//        
//    }
//    if ( nBytes > 0 ) {
//        std::cout << "stamp = " << deltatime << std::endl;
//    }
//}
