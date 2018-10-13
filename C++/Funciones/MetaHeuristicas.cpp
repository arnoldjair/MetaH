#include <iostream>
#include <chrono>
#include "Ackley.h"
#include "Rastrigin.h"
#include "Record.h"
#include "Griewank.h"
#include "Sphere.h"
#include "Schwefel.h"

using namespace std;

int main(int argc, char **argv) {
  /*auto begin = chrono::high_resolution_clock::now();
  int x;
  cin >> x;      // wait for user input
  auto end = chrono::high_resolution_clock::now();
  auto dur = end - begin;
  auto ms = std::chrono::duration_cast < std::chrono::milliseconds
      > (dur).count();
  cout << ms << endl;
   */
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
  return 0;
}
