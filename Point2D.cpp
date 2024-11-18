#include "Point2D.h"  // Incluir el archivo de encabezado
#include <cmath>  


Point2D::Point2D(double x, double y) : x(x), y(y) {}

/*---------------------Point2D----------------------*/
Point2D(double x=0, double y=0){
}
    	
/*---------------------DISTANCE----------------------*/
double Point2D::distance(const Point2D &a, const Point2D &b){
    double dx= a.x - b.x;
    double dy= a.y - b.y;
    		
    return std::sqrt (dx*dx +dy*dy);
}
		
/*---------------------OPERATOR==----------------------*/
bool operator==(const Point2D &a, const Point2D &b){
			
	return (a.x ==b.x) && (a.y ==b.y);	
}
		
/*---------------------OPERATOR!=----------------------*/
bool operator!=(const Point2D &a, const Point2D &b){
			
		return !(a==b);
}
		
/*---------------------OPERATOR<<----------------------*/
std::ostream& operator<<(std::ostream &out, const Point2D &p){
			
	out << "(" << p.x << ", " << p.y << ")";
    return out;	
}
    	
