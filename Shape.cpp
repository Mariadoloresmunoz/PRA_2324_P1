#include "Shape.h"
#include "Point2D.h"
#include <stdexcept>  
#include <iostream>
#include <cmath>


Shape::Shape(std::string color){
	if(color=='red' || color=='green' || color =='blue'){
		this-> color =color;
	}
	else{
		throw std::invalid_argument("Color no v�lido. Solo 'red', 'green', o 'blue' son permitidos.");
	}
	
}
std::string Shape:: get_color() const{
	return color;
}

void Shape::set_color(std::string c){
	if(color=='red' || color=='green' || color =='blue'){
		this-> color =c;
	}
	else{
		throw std::invalid_argument("Color no v�lido. Solo 'red', 'green', o 'blue' son permitidos.");
	}
}

double Shape::area() const {
    return M_PI * radius * radius;  // F�rmula del �rea de un c�rculo
}


double Shape::perimeter() const {
    return 2 * M_PI * radius;  // F�rmula del per�metro de un c�rculo
}


void Shape::translate(double incX, double incY) {
    center.distancia(incX, incY); 
}

void Shape::print() {
    std::cout << "C�rculo de color " << get_color() << ", centro en (" << center.get_x() << ", " << center.get_y() 
              << ") y radio " << radius << "." << std::endl;
}
