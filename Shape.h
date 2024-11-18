#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "Point2D.h"

    class Shape{
    	protected:
    		std::string color;
    		
    	public:
    		Shape() : color("red") {}
    		Shape(std::string color);
    		std::string get_color() const;
    		void set_color(std::string c);
    		virtual double area() const;
    		virtual double perimeter() const;
    		virtual void translate(double incX, double incY);
    		virtual void print();
	};

#endif
