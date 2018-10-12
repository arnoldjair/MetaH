#include <iostream>
#include "Ackley.h"
#include "Record.h"
#include "Griewank.h"
#include "Sphere.h"

using namespace std;

int main(int argc, char **argv) {
  Record* record = Record::randomRecord(100, -32, 32);
  Function* sphere = new Sphere();
  Function* ackley = new Ackley();
  Function* griewank = new Griewank();
  record->setFitness(griewank->evaluate(*record));
  cout << record->getFitness() << endl;
  delete record;
  delete sphere;
  delete ackley;
  delete griewank;
  return 0;
}
