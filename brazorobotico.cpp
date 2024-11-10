#include "brazorobotico.h"

using namespace std;

brazorobotico::brazorobotico(){
  x=0;
  y=0;
  z=0;
}

double brazorobotico::getx(){
  return  x;
}

double brazorobotico:: gety(){
  return y;
}

double brazorobotico::getz(){
  return z;
}

bool brazorobotico::getsujeto(){
  return sujeto;
}
