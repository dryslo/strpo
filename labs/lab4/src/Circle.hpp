#ifndef CIRCLE_HPP
#define CIRCLE_HPP

struct Point
{
    double x,y;
    Point();
    Point(double x, double y);
    
    bool operator==(const Point& other);
    bool operator!=(const Point& other);
};


class Circle{
    Point centre;
    double radius;

public:
    Circle();
    Circle(double x,double y, double raduis);
    Circle(Point centre, double radius);

    double get_radius() const;
    Point get_centre() const;

    void set_radius(double radius);
    void set_centre(Point centre);

    bool operator==(const Circle& other);
    bool operator!=(const Circle& other);

    double get_area() const;
};


#endif