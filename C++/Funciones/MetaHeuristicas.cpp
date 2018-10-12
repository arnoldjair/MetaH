#include <iostream>
#include "Sphere.h"
#include "Record.h"

using namespace std;

int main(int argc, char **argv) {
  Record* record = Record::randomRecord(100, -1, 1);
  Function* sphere = new Sphere();
  record->setFitness(sphere->evaluate(*record));
  delete record;
  delete sphere;
  return 0;
}
