#include "../Rectangle/Rectangle.hh"
#include <iostream>

int main(){
    // Reading input to create rectangles

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

    // std::cout << "\nRectangle 1: (" << p1_x << ", " << p1_y << "; " << p2_x << ", " << p2_y << ")\n";
    Rectangle Rectangle1(p1_x, p1_y, p2_x, p2_y);
    // std::cout << "Created Rectangle 1: (" << Rectangle1.p1.x << ", " << Rectangle1.p1.y << "; " << Rectangle1.p2.x << ", " << Rectangle1.p2.y << ")\n";

    // std::cout << "\n---------------------\n";

    std::cout << "First point x: ";
    std::cin >> p1_x;
    std::cout << "First point y: ";
    std::cin >> p1_y;

    std::cout << "Second point x: ";
    std::cin >> p2_x;
    std::cout << "Second point y: ";
    std::cin >> p2_y;

    std::cout << "\n---------------------\n";

    // std::cout << "\nRectangle 2: (" << p1_x << ", " << p1_y << "; " << p2_x << ", " << p2_y << ")\n";
    Rectangle Rectangle2(p1_x, p1_y, p2_x, p2_y);
    // std::cout << "Created Rectangle 2: (" << Rectangle2.p1.x << ", " << Rectangle2.p1.y << "; " << Rectangle2.p2.x << ", " << Rectangle2.p2.y << ")\n";
    // std::cout << "\n---------------------\n";

    // Checking intersection
    if(intersects(Rectangle1, Rectangle2))
        std::cout << "\nIntersection detected\n";
    else
        std::cout << "\nNo intersection detected\n";

    return 0;
}