class Rectangle{
    public:
        Rectangle(int p1_x, int p1_y, int p2_x, int p2_y);
        int area();
        struct Point{
            int x;
            int y;
        } p1, p2;
};

bool intersects(Rectangle Rect1, Rectangle Rect2);