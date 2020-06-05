#include <iostream>
#include <string>
#include <cmath>
#include "Notas.h"
#include "Osc.h"

using namespace std;

int main(){
  char nota;
  int oct;
  cout << "Ingresa la nota(En mayusculas): ";
  cin >> nota;
  cout << "Ingrese la octava: ";
  cin >> oct;
  Notas n(nota,oct);
  bool f;
  char tf;
  float co;
  string w;
  cout << "agregar filtro? (1 si, 0 no): ";
  cin >> f;
  if(f){
    cout << "tipo de filtro: (L para lowpass, H para highpass): ";
    cin >> tf;
    cout << "Ingresa el cutoff del filtro: ";
    cin >> co;
  }
  else{
    tf = 'N';
    co = 22000;
  };
  Osc *o;
  cout << "tipo de onda? (sine, square, saw): ";
  cin >> w;
  if(w == "sine"){
    o = new sine(f, tf, co, 100);
    o->ImprimirFreqs(n);
  }
  else if(w == "square"){
    o = new square(f, tf, co, 100);
    o->ImprimirFreqs(n);
  }
  else if(w == "saw"){
    o = new saw(f, tf, co, 100);
    o->ImprimirFreqs(n);
  }
  else{
    cout << "error" << endl;
  }
  return 0;
}
