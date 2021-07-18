#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include "Rectangle.hh"

// Rectangle constructor
Rectangle::Rectangle(int p1_x, int p1_y, int p2_x, int p2_y){

    this->p1.x = std::min(p1_x, p2_x);
    this->p1.y = std::min(p1_y, p2_y);

    this->p2.x = std::max(p1_x, p2_x);
    this->p2.y = std::max(p1_y, p2_y);

}

int Rectangle::area(){

    int distx = this->p2.x - this->p1.x;
    int disty = this->p2.y - this->p1.y;

    // Add one to each distance to account for the points in the borders of the rectangle
    return (distx + 1) * (disty + 1);

}

bool intersects(Rectangle Rect1, Rectangle Rect2){

    if(Rect2.p1.x > Rect1.p2.x || Rect1.p1.x > Rect2.p2.x)
        return false;
    
    if(Rect2.p1.y > Rect1.p2.y || Rect1.p1.y > Rect2.p2.y)
        return false;

    else
        return true;

}