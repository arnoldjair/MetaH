#include <iostream>
#include <fstream>
#include <chrono>
#include <nlohmann/json.hpp>
#include "Ackley.h"
#include "Rastrigin.h"
#include "Record.h"
#include "Griewank.h"
#include "IteratedLocalSearchT.h"
#include "IteratedLocalSearchN.h"
#include "Sphere.h"
#include "Schwefel.h"
#include "FunctionFactory.h"

using json = nlohmann::json;

int main(int argc, char *argv[]) {

  std::ifstream i(argv[1]);
  json j;
  i >> j;

  //TODO: Falta validar que el json esté bien formado pe.
  int dimensionality = j["dimensionality"];
  int neighbours = j["neighbours"];
  double tweak = j["tweak"];
  double perturbation = j["perturbation"];
  int funcEvaluations = j["funcEvaluations"];
  std::string functionName = j["functionName"];
  int runs = j["runs"];

  Function* function = FunctionFactory::getFunction(functionName);

  if (function == NULL) {
    return -1;
  }

  IteratedLocalSearchN* algorithmN = new IteratedLocalSearchN();

  double eval = 0;

  for (int i = 0; i < runs; i++) {
    Record* resultN = algorithmN->process(dimensionality, neighbours,
                                          function->getLower(),
                                          function->getUpper(), tweak,
                                          perturbation, funcEvaluations,
                                          function);
    eval += resultN->getFitness();
    std::cout << resultN->toString() << std::endl;
  }

  eval /= runs;
  std::cout << eval << std::endl;
  return 0;
}
