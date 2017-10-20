//
//  CollisionEngine.hpp
//  Masteroids
//
//  Created by Lilly Fiorino on 6/9/17.
//  Copyright © 2017 Cibo. All rights reserved.
//

#ifndef CollisionEngine_hpp
#define CollisionEngine_hpp

#include <stdio.h>
#include "Asteroid.hpp"
#include <vector>
#include "Point.hpp"
#include "Ship.hpp"

class Node {
public:
    Node();
    double X;
    double Y;
    double R;
};

class CollisionEngine {
public:
    CollisionEngine();
    bool checkAsteroids(std::vector<Asteroid*> asteroids, int nAsteroids, Ship ship, SDL_Renderer* gRenderer);
private:
};

class AsteroidCollision: private CollisionEngine
{
public:
    AsteroidCollision(Asteroid* aster0, Asteroid* aster1);
    bool checkForCollision();
    bool checkForCollision(int offSet);
    void exicuteCollision(Asteroid* aster0, Asteroid* aster1, SDL_Renderer* gRenderer);
    void seperate(Asteroid* aster0, Asteroid* aster1);
    double calcAngle(Point C, Point P0, Point P1);
private:
    Point i;
    Point j;
    Point _j;
    double theta0;
    double theta1;
    Point Moment;
};

#endif /* CollisionEngine_hpp */
