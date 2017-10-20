//
//  ListRenderer.cpp
//  SFML_Testing
//
//  Created by Lilly Fiorino on 8/24/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include "ListRenderer.hpp"
#include "List.hpp"

ListRenderer::ListRenderer(sf::RenderWindow &Window, StateMachine &S) {
    window = &Window;
    s = &S;
    listColor = sf::Color(0,0,0,0);
    showIndexMark = false;
    width = window->getSize().x; hight = window->getSize().y;
}

void ListRenderer::setIndex(int Index) {
    index = Index;
}

void ListRenderer::render(List &List)
{
    rectList.resize(List.Size());
    switch (s->state) {
        case IDLE : {
            listColor = sf::Color(204, 153, 0);
        }break;
        case SORT : {
            showIndexMark = true;
            listColor = sf::Color(204, 153, 0);
        }break;
        case SUCCSESS : {
            showIndexMark = false;
            listColor = sf::Color::Cyan;
        }break;
        case START : {
            showIndexMark = false;
            listColor = sf::Color::Green;
        }break;
        default:
            break;
    }
    for (int i = 0; i < List.Size(); i++)
    {
        if (i == index && showIndexMark) {
            rectList[i].setFillColor(sf::Color::Red);
        } else {
            rectList[i].setFillColor(listColor);
        }
        
        int W = width - 20;
        int H = hight - 120;
        int cellWidth = W/List.Size();
        int cellHight = H/List.Max();
        rectList[i].setSize(sf::Vector2f(
                                         cellWidth * 0.8,
                                         (cellHight * List.get(i)) + 10
                                         )); // Rect Size - |
        
        rectList[i].setPosition((( W/List.Size() )*i )+20, (H)-((H/List.Max())*List.get(i))+100 ); // Pos of Left Top - |
        
        rectList[i].setOutlineColor(sf::Color::Red);
        rectList[i].setOutlineThickness(0);
        window->draw(rectList[i]);
    }
}


