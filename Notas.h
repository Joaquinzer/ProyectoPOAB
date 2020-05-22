#ifndef NOTAS_H
#define NOTAS_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Notas{
private:
  char nota;
  int octava;
public:
  Notas(char n, int o){
    nota = n;
    octava = o;
  };
  Notas(){
    nota = 'C';
    octava = 1;
  };
  char getnota(){return nota;};
  int getoctava(){return octava;};
  float encontrarfreq(){
    float f;
    switch(nota){
      case 'C':
        f = 16.35;
        break;
      case 'D':
        f = 18.35;
        break;
      case 'E':
        f = 20.60;
        break;
      case 'F':
        f = 21.83;
        break;
      case 'G':
        f = 24.50;
        break;
      case 'A':
        f = 27.50;
        break;
      case 'B':
        f = 30.87;
        break;
    };
    int o = octava;
    f = f*(pow(2,o));
    return f;
  };
};
#endif
