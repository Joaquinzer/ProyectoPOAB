#include <iostream>
#include <string>
#include <cmath>
#include "Notas.h"
#include "Osc.h"

using namespace std;

int main(){
  bool f;
  char tf;
  float co;
  string w;
  cout <<  "Simula la frecuencias de un oscilador" << endl;
  cout << "" << endl;
  cout << "agregar filtro? (1 si, 0 no): ";
  cin >> f;
  cout << "" << endl;
  if(f){
    cout << "tipo de filtro: (L para lowpass, H para highpass): ";
    cin >> tf;
    cout << "" << endl;
    cout << "Ingresa el cutoff del filtro: ";
    cin >> co;
    cout << "" << endl;
  }
  else{
    tf = 'N';
    co = 22000;
  };
  Osc *o;
  cout << "tipo de onda? (sine, square, saw): ";
  cin >> w;
  cout << "" << endl;
  if(w == "sine"){
    o = new sine(f, tf, co, 100);
  }
  else if(w == "square"){
    o = new square(f, tf, co, 100);
  }
  else if(w == "saw"){
    o = new saw(f, tf, co, 100);
  }
  else{
    cout << "error" << endl;
  }
  char nota;
  int oct;
  Notas *n[100];
  while (true){
    int i = 1;
    cout << "Ingresa la nota(En mayusculas): ";
    cin >> nota;
    cout << "" << endl;
    cout << "Ingrese la octava: ";
    cin >> oct;
    cout << "" << endl;
    n[i] = new Notas(nota,oct);
    o->ImprimirFreqs(*n[i]);
    i = i+1;
    string sn;
    cout << "Desea ingresar otra nota?(si/no) ";
    cin >> sn;
    cout << "" << endl;
    if (sn == "no"){
      break;
    }
    if (i == 101){
      break;
    }
  }
  return 0;
}
