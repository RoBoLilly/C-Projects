//
//  Field.cpp
//  PointLab
//
//  Created by Lilly Fiorino on 10/14/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#include "Field.hpp"
#include "Point2f.hpp"
#include "Partical.hpp"
#include <iostream>
#include <math.h>
Field::Field(Point2f size) {
    fieldSize = size;
}

void Field::bounderyCheck(Partical &partical)
{
    if(partical.getPos().x >= fieldSize.x) {
        partical.setPos(Point2f(fieldSize.x, partical.getPos().y));
        partical.flipMomentX();
    }
    if(partical.getPos().x < 0) {
        partical.setPos(Point2f(0, partical.getPos().y));
        partical.flipMomentX();
    }
    if(partical.getPos().y >= fieldSize.y) {
        partical.setPos(Point2f(partical.getPos().x, fieldSize.y));
        partical.flipMomentY();
    }
    if(partical.getPos().y < 0) {
        partical.setPos(Point2f(partical.getPos().x, 0));
        partical.flipMomentY();
    }
}

void Field::addAttraction(Partical &partical, LinkedList<Partical> &ll) {
    const float deadZone = 0.25;
    Point2f d;
    Point2f a;
    int c = 0;
    bool happening = true;
    for(Node<Partical>* n = ll.head; n != nullptr; n = n->next) {
        if(partical.ID != n->data.ID){
            d.x = n->data.getPos().x - partical.getPos().x;
            d.y = n->data.getPos().y - partical.getPos().y;
            float m = sqrt(d.x*d.x + d.y*d.y);
            if(m > deadZone){
                d = d/m;
                if(m < partical.getRepulsiveR()){
                    d = d * -1;
                }else{
                    
                }
                a = a+d;
                c++;
                happening = true;
            } else { happening = false; }
        }
    }
    if(happening){
        a = a/c;
        partical.setPos(Point2f(partical.getPos().x + a.x, partical.getPos().y + a.y));
    }
}







