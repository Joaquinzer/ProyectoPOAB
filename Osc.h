#ifndef OSC_H
#define OSC_H

#include <iostream>
#include <cmath>
#include <string>
#include "Notas.h"

using namespace std;

class Osc{
public:
  bool filtro;
  char Tipo;
  float cutoff;
  string wave;
  int amplitud;
  Osc(bool f, char t, float c, string w, int a);
  Osc();
  char GetTipo(){return Tipo;};
  float GetCutoff(){return cutoff;};
  string GetWave(){return wave;};
  int GetAmp(){return amplitud;};
  void SetAmp(int aa);
  void ImprimirFreqs(Notas &n);
};
Osc::Osc(bool f, char t, float c, string w, int a){
  filtro = f;
  Tipo = t;
  cutoff = c;
  wave = w;
  amplitud = a;
}
Osc::Osc(){
  filtro = 0;
  Tipo = 'L';
  cutoff = 24000;
  wave = "Sine";
  amplitud = 100;
}
void Osc::SetAmp(int aa){
  amplitud = aa;
}
void Osc::ImprimirFreqs(Notas &n){
  float f;
  f = n.encontrarfreq();
  if(filtro && (Tipo == 'L')){
    if(cutoff < f){
      cout << "No hay frecuencias" << endl;
    }
  }
  else if (filtro && (Tipo == 'H')){
    if(cutoff > f){
      cout << "No hay frecuencias" << endl;
    }
  }
  else{
    cout << "Frecuencia en Hz:" << endl;
    cout << f << endl;
  }
}

class square : public Osc{
public:
  square(bool f, char t, float c, int a): Osc(f, t, c, "Square", a){}
  void ImprimirFreqs(Notas &n);
};
void square::ImprimirFreqs(Notas &n){
  float f;
  f = n.encontrarfreq();
  if(filtro && (Tipo == 'L')){
    if(cutoff < f){
      cout << "No hay frecuencias" << endl;
    }
    else{
      float fr = f;
      int od = 3;
      cout << "Frecuencias en Hz:" << endl;
      while(fr < cutoff){
        cout << fr << "  ";
        fr = f*od;
        od = od + 2;
      }
    }
  }
  else if (filtro && (Tipo == 'H')){
    if(cutoff > f){
      cout << "No hay frecuencias" << endl;
    }
    else{
      float fr = f;
      int od = 3;
      cout << "Frecuencias en HZ:" << endl;
      while(true){
        fr = f*od;
        od = od + 2;
        if(fr > cutoff){
          cout << fr << "  ";
        }
        if(fr > 20000){
          break;
        }
      }
    }
  }
  else{
    float fr = f;
    int od = 3;
    cout << "Frecuencias en Hz:" << endl;
    while(fr < 20000){
      cout << fr << "  ";
      fr = f*od;
      od = od + 2;
    }
  }
  cout << "" << endl;
}

class saw : public Osc{
public:
  saw(bool f, char t, float c, int a): Osc(f, t, c, "Saw", a){}
  void ImprimirFreqs(Notas &n);
};
void saw::ImprimirFreqs(Notas &n){
  float f;
  f = n.encontrarfreq();
  if(filtro && (Tipo == 'L')){
    if(cutoff < f){
      cout << "No hay frecuencias" << endl;
    }
    else{
      float fr = f;
      int od = 2;
      cout << "Frecuencias en Hz:" << endl;
      while(fr < cutoff){
        cout << fr << "  ";
        fr = f*od;
        od = od + 1;
      }
    }
  }
  else if (filtro && (Tipo == 'H')){
    if(cutoff > f){
      cout << "No hay frecuencias" << endl;
    }
    else{
      float fr = f;
      int od = 2;
      cout << "Frecuencias en HZ:" << endl;
      while(true){
        fr = f*od;
        od = od + 1;
        if(fr > cutoff){
          cout << fr << "  ";
        }
        if(fr > 20000){
          break;
        }
      }
    }
  }
  else{
    float fr = f;
    int od = 2;
    cout << "Frecuencias en Hz:" << endl;
    while(fr < 20000){
      cout << fr << "  ";
      fr = f*od;
      od = od + 1;
    }
  }
  cout << "" << endl;
}

#endif
