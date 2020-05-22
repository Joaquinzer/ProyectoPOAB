#include <iostream>
#include <string>
#include <cmath>
#include "Notas.h"
#include "Osc.h"

using namespace std;

int main(){
  // Ejemplo prueba
  Notas n('C',3);
  saw s(true, 'L', 16000, 100);
  s.ImprimirFreqs(n);
  return 0;
}
