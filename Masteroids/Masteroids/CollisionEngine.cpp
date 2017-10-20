//
//  CollisionEngine.cpp
//  Masteroids
//
//  Created by Lilly Fiorino on 6/9/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#include "CollisionEngine.hpp"
#include "Point.hpp"
#include "Ship.hpp"
//#include <vector>

const double Pi = 3.14159;

double sqr(double i){ return i*i; }

CollisionEngine::CollisionEngine()
{
    sqr(3);
}
bool CollisionEngine::checkAsteroids(std::vector<Asteroid*> asteroids, int nAsteroids, Ship ship, SDL_Renderer* gRenderer)
{
    bool collision = false;
    int deadNode = -1;
    for(int i=0; i<nAsteroids; i++){
        for(int j=0; j<nAsteroids; j++){
            if(j!=i && j!=deadNode){
                deadNode = j;
                AsteroidCollision astCol(asteroids[i], asteroids[j]);
                //SDL_RenderDrawLine(gRenderer, asteroids[i]->getLocation(0), asteroids[i]->getLocation(1), asteroids[j]->getLocation(0), asteroids[j]->getLocation(1)); // Draw Line on Check;
                if(astCol.checkForCollision(-1)){
                    astCol.seperate(asteroids[i], asteroids[j]);
                }
//                else if(astCol.checkForCollision()){
//                    collision = true;
//                    astCol.exicuteCollision(asteroids[i], asteroids[j], gRenderer);
//                    //printf("Node Collision: Node[%i], Node[%i]\n", i, j);
//                }
            }
        }
        //if(sqrt(sqr(node[j].X-node[i].X)+sqr(node[j].Y-node[i].Y))<(node[i].R+node[j].R)){}
    }
    return collision;
}


AsteroidCollision::AsteroidCollision(Asteroid* aster0, Asteroid* aster1)
{
    i.X = aster0->getLocation(0);
    i.Y = aster0->getLocation(1);
    i.R = aster0->radius;
    j.X = aster1->getLocation(0);
    j.Y = aster1->getLocation(1);
    j.R = aster1->radius;
    Moment.X = aster0->getMoment(0);
    Moment.Y = aster0->getMoment(1);
    _j.setPoint(j.rotatePointAround(i, Pi/2));
    theta0 = calcAngle(i, j, Moment);
    theta1 = calcAngle(i,_j, Moment);
}

bool AsteroidCollision::checkForCollision()
{
    if(sqrt(sqr(j.X-i.X)+sqr(j.Y-i.Y))<( i.R+j.R )){
        return true;
    }else{
        return false;
    }
}

bool AsteroidCollision::checkForCollision(int offset)
{
    if(sqrt(sqr(j.X-i.X)+sqr(j.Y-i.Y))<( i.R+j.R+offset)){
        return true;
    }else{
        return false;
    }
}

void AsteroidCollision::exicuteCollision(Asteroid* aster0, Asteroid* aster1, SDL_Renderer* gRenderer)
{
//    aster0->setMoment(0, aster1->getMoment(1));
//    aster0->setMoment(1, aster1->getMoment(0));
//    aster1->setMoment(0, aster0->getMoment(1));
//    aster1->setMoment(1, aster0->getMoment(0));
//}
    Point i;
    Point j;
    Point _j;
    i.X = aster0->getLocation(0);
    i.Y = aster0->getLocation(1);
    j.X = aster1->getLocation(0);
    j.X = aster1->getLocation(1);
    _j.setPoint(_j.rotatePoint(Pi/2));
    Moment.setPoint(aster0->getMoment(0), aster0->getMoment(1));
    double theta0 = calcAngle(i, j, Moment);
    double theta1 = calcAngle(i,_j, Moment);
    
    if(theta0 < Pi/2){
        if(theta1 < Pi/2){
            Moment.setPoint(Moment.rotatePoint((Pi/2-theta0)*2));
        }else{
            Moment.setPoint(Moment.rotatePoint((Pi/2-theta0)*-2));
        }
    }
        
    aster0->setMoment(0, Moment.X);
    aster0->setMoment(1, Moment.Y);
//    if(theta0>Pi/2){
//        if(theta1<Pi/2){
//            Moment.setPoint(Moment.rotatePoint((theta0-Pi/2)*2));
//        }else{
//            Moment.setPoint(Moment.rotatePoint(((Pi/2)-theta1)*-2));
//        }
//    }else{
//        if(theta1>Pi/2){
//            Moment.setPoint(Moment.rotatePoint(theta1*2));
//        }else{
//            Moment.setPoint(Moment.rotatePoint(-2*theta1));
//        }
//    }
    
    //printf("Moment After : %f, %f;\n", Moment.X, Moment.Y);

//    } while( sqrt(sqr(aster1->getLocation(0)-aster0->getLocation(1))+sqr(aster1->getLocation(1)-aster0->getLocation(1)))<( aster1->radius+aster0->radius) );
}

double AsteroidCollision::calcAngle(Point C, Point P0, Point P1)
{
    double a = sqr(C.X-P0.X) + sqr(C.Y-P0.Y);
    double b = sqr(C.X-P1.X) + sqr(C.Y-P1.Y);
    double c = sqr(P1.X-P0.X) + sqr(P1.Y-P0.Y);
    return acos( (a+b-c) / sqrt(4*a*b) );
}

void AsteroidCollision::seperate(Asteroid* aster0, Asteroid* aster1)
{
    Point i;
    Point j;
    //double D = sqrt(sqr(j.X-i.X)+sqr(j.Y-i.Y));
    i.setPoint(aster0->getLocation(0), aster0->getLocation(1));
    j.setPoint(aster1->getLocation(0), aster1->getLocation(1));
    Point temp; temp.setPoint(i);
    i.scaleLine(j, i, 1.025);
    j.scaleLine(temp, j, 1.025);
    aster0->setLocation(0, i.X);
    aster0->setLocation(1, i.Y);
    aster1->setLocation(0, j.X);
    aster1->setLocation(1, j.Y);
}






