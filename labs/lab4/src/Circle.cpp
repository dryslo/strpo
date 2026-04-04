#include "Circle.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

inline static double abs(double x){ return (x>=0.)?x:-x;}

Point::Point():x(0.0),y(0.0){}

Point::Point(double x, double y):x(x),y(y){}


bool Point::operator==(const Point& other){
    return (x == other.x && y == other.y);
}

bool Point::operator!=(const Point& other){
    return !(*this == other);
}


Circle::Circle():centre(), radius(0){}

Circle::Circle(double x,double y, double radius):centre(x,y), radius(abs(radius)){}

Circle::Circle(Point centre, double radius):centre(centre), radius(abs(radius)){}

double Circle::get_radius() const {
    return radius;
}

Point Circle::get_centre() const {
    return centre;
}

void Circle::set_radius(double radius){
    this->radius = abs(radius);
}

void Circle::set_centre(Point centre){
    this->centre = centre;
}

bool Circle::operator==(const Circle& other){
    return (centre == other.centre && radius == other.radius);
}

bool Circle::operator!=(const Circle& other){
    return !(*this == other);
}

double Circle::get_area() const {
    return M_PI * radius * radius;
}