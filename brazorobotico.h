#ifndef BRAZOROBOTICO_H
#define BRAZOROBOTICO_H

#inlcude <iostream>

class brazorobotico{

 private:
  double x;
  double y;
  double z;
  bool sujeto= false;

 public:
  brazorobotico();
  double getx();
  double gety();
  double getz();
  bool getsujeto();
  void coger();
  void soltar();
  void mover(double x, double y, double z);

};

#endif
  
  
