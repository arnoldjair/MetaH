#include <iostream>
#include "Ackley.h"
#include "Rastrigin.h"
#include "Record.h"
#include "Griewank.h"
#include "Sphere.h"
#include "Schwefel.h"

using namespace std;

int main(int argc, char **argv) {
  Record* record = Record::randomRecord(100, -32, 32);
  Function* sphere = new Sphere();
  Function* ackley = new Ackley();
  Function* griewank = new Griewank();
  Function* rastrigin = new Rastrigin();
  Function* schwefel = new Schwefel();
  record->setFitness(schwefel->evaluate(*record));
  cout << record->getFitness() << endl;
  delete record;
  delete sphere;
  delete ackley;
  delete griewank;
  delete rastrigin;
  delete schwefel;
  return 0;
}
