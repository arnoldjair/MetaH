#include <iostream>
#include <chrono>
#include "Ackley.h"
#include "Rastrigin.h"
#include "Record.h"
#include "Griewank.h"
#include "IteratedLocalSearchT.h"
#include "Sphere.h"
#include "Schwefel.h"

int main(int argc, char **argv) {

  IteratedLocalSearch* algorithm = new IteratedLocalSearch();
  Record* result = algorithm->process(100, 20, -1, 1, .001, .1, 100,
                                                      new Sphere());

  std::cout << result->toString() << std::endl;

  /*
  Record* record = Record::randomRecord(100, -32, 32, 0.1);
  std::cout << record->toString() << std::endl;
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
   */

  return 0;
}
