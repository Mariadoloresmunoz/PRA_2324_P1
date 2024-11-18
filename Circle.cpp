#include "Circle.h"
#include <iostream>
#include <cmath>

Circle::Circle() : Shape(), center(0, 0), radius(1) {}

Circle::Circle(std::string color, Point2D center, double radius) : Shape(color), center(center), radius(radius) {}
Point2D Circle::get_center() const{
	retrun center;
}
void Circle:: set_center(Point2D p){
	center =p;
}
double Circle:: get_radius() const{
	retrun radius;
	
}

void Circle::set_radius(double r){
	if(r>0){
		radius= r
	}
	else{
		throw std::invalid_argument("radio tiene que ser positivo");
	}	
}
 // Implementación de los métodos virtuales heredados de Shape
double Circle::area() const {
    return M_PI * radius * radius;  // Fórmula del área de un círculo
}


double Circle::perimeter() const {
    return 2 * M_PI * radius;  // Fórmula del perímetro de un círculo
}


void Circle::translate(double incX, double incY) {
    center.distancia(incX, incY); 
}

void Circle::print() {
    std::cout << "Círculo de color " << get_color() << ", centro en (" << center.get_x() << ", " << center.get_y() 
              << ") y radio " << radius << "." << std::endl;
}

ostream& operator<<(std::ostream &out, const Circle &c){
	  out << "Círculo de color " << c.get_color() << ", centro en (" << c.center.get_x() << ", " << c.center.get_y() 
        << ") y radio " << c.radius;
    return out;
}
