#include <iostream>
#include <algorithm>

#include "../Rectangle/Rectangle.hh"

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
