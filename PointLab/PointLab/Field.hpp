//
//  Field.hpp
//  PointLab
//
//  Created by Lilly Fiorino on 10/14/17.
//  Copyright © 2017 Cibo-Lilly. All rights reserved.
//

#ifndef Field_hpp
#define Field_hpp

#include <stdio.h>
#include "Point2f.hpp"
#include "Partical.hpp"
#include "LinkedList.hpp"

class Field {
private:
    Point2f fieldSize;
public:
    Field(Point2f size);
    void bounderyCheck(Partical &partical);
    void addAttraction(Partical &partical, LinkedList<Partical> &ll);
};

#endif /* Field_hpp */
