#include "Rectangle.h"
#include <cmath>
#include <stdexcept>
#include <iostream>


Rectangle::Rectangle() : Shape(), vs(new Point2D[N_VERTICES]) {
    // Inicializa los vértices por defecto
    vs[0] = Point2D(-1, 0.5);
    vs[1] = Point2D(1, 0.5);
    vs[2] = Point2D(1, -0.5);
    vs[3] = Point2D(-1, -0.5);
}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color), vs(new Point2D[N_VERTICES]) {
	if (check(vertices)) {
        for (int i = 0; i < N_VERTICES; i++) {
            vs[i] = vertices[i];
        }
    } else {
        throw std::invalid_argument("Los vértices no forman un rectángulo válido.");
    }
}

// funcion que comprueba si entre los vertices se forma un rectangulo 
bool Rectangle::check(Point2D* vertices) {
    // Comprobamos las longitudes de los lados opuestos
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d32 = Point2D::distance(vertices[2], vertices[3]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d03 = Point2D::distance(vertices[0], vertices[3]);

    // Si las longitudes de los lados opuestos son iguales, es un rectángulo válido
    return (d01 == d32 && d12 == d03);
}
Rectangle::Rectangle(const Rectangle& r) : Shape(r), vs(new Point2D[N_VERTICES]) {
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = r.vs[i];
    }
}

Rectangle::~Rectangle(){
	delete[] vs;
}
Point2D Rectangle::get_vertex(int ind) const{
	if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Índice fuera de rango.");
    }
    return vs[ind];
}
Point2D Rectangle::operator[](int ind) const{
	if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Índice fuera de rango.");
    }
    return vs[ind];
}
void Rectangle::set_vertices(Point2D* vertices){
	if (check(vertices)) {
        for (int i = 0; i < N_VERTICES; i++) {
            vs[i] = vertices[i];
        }
    } else {
        throw std::invalid_argument("Los vértices no forman un rectángulo válido.");
    }
}
Rectangle& Rectangle::operator=(const Rectangle &r){
	if (this != &r) {
        // Liberamos memoria antes de reasignar
        delete[] vs;

        // Asignamos los  nuevos valores
        vs = new Point2D[N_VERTICES];
        for (int i = 0; i < N_VERTICES; i++) {
            vs[i] = r.vs[i];
        }
        Shape::operator=(r);  
    }
    return *this;
}
std::ostream& operator<<(ostream &out, const Rectangle &r){
	out << "Rectángulo de color " << r.get_color() << " con vértices: ";
    for (int i = 0; i < Rectangle::N_VERTICES; i++) {
        out << "(" << r.vs[i].get_x() << ", " << r.vs[i].get_y() << ") ";
    }
    return out;
}
		
// Implementación de los métodos virtuales heredados de Shape
double Rectangle::area() const{
	
	double width = Point2D::distance(vs[0], vs[1]);
    double height = Point2D::distance(vs[1], vs[2]);
    return width * height; 
}
double Rectangle::perimeter() const{
	
	double width = Point2D::distance(vs[0], vs[1]);
    double height = Point2D::distance(vs[1], vs[2]);
    return 2 * (width + height);
}
void Rectangle::translate(double incX, double incY){
	
	for (int i = 0; i < N_VERTICES; i++) {
        vs[i].translate(incX, incY);  // Traslada cada vértice
    }
}
void Rectangle::print(){
	
	std::cout << "Rectángulo de color " << get_color() << " con vértices: ";
    for (int i = 0; i < N_VERTICES; i++) {
        std::cout << "(" << vs[i].get_x() << ", " << vs[i].get_y() << ") ";
    }
    std::cout << std::endl;
}
