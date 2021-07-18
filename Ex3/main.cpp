#include <iostream>
#include <algorithm>

#include "../Ex2/Rectangle.hh"

int areaOfIntersection(Rectangle Rect1, Rectangle Rect2){

    int p1_x;
    int p2_x;
    int p1_y;
    int p2_y;

    // If no intersection, area is zero
    if(!intersects(Rect1, Rect2))
        return 0;

    else{
        p1_x = std::max(Rect1.p1.x, Rect2.p1.x);
        p2_x = std::min(Rect1.p2.x, Rect2.p2.x);

        p1_y = std::max(Rect1.p1.y, Rect2.p1.y);
        p2_y = std::min(Rect1.p2.y, Rect2.p2.y);

        Rectangle Rect3(p1_x, p1_y, p2_x, p2_y);

        return Rect3.area();
    }

}


int main(){

    int p1_x, p1_y, p2_x, p2_y;

    std::cout << "Defining first rectangle\n";
    std::cout << "First point x: ";
    std::cin >> p1_x;
    std::cout << "First point y: ";
    std::cin >> p1_y;

    std::cout << "Second point x: ";
    std::cin >> p2_x;
    std::cout << "Second point y: ";
    std::cin >> p2_y;

    std::cout << "\n---------------------\n";
    Rectangle Rectangle1(p1_x, p1_y, p2_x, p2_y);

    std::cout << "First point x: ";
    std::cin >> p1_x;
    std::cout << "First point y: ";
    std::cin >> p1_y;

    std::cout << "Second point x: ";
    std::cin >> p2_x;
    std::cout << "Second point y: ";
    std::cin >> p2_y;

    std::cout << "\n---------------------\n";
    Rectangle Rectangle2(p1_x, p1_y, p2_x, p2_y);

    std::cout << "Intersection area: " << areaOfIntersection(Rectangle1, Rectangle2) << std::endl;

    return 0;
}
