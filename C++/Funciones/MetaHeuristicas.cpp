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
#include "RandomSearch.h"

int main(int argc, char *argv[]) {

  std::ifstream i(argv[1]);
  nlohmann::json j;  // @suppress("Type cannot be resolved")
  i >> j;

  //TODO: Falta validar que el json esté bien formado pe.

  int funcEvaluations = j["funcEvaluations"];
  std::string functionName = j["functionName"];
  std::string algorithm = j["algorithm"];
  int runs = j["runs"];
  Function* function = FunctionFactory::getFunction(functionName);

  if (function == NULL) {
    return -1;
  }

  for (auto& perturbation : j["perturbation"]) {  // @suppress("Symbol is not resolved")
    for (auto& tweak : j["tweak"]) {  // @suppress("Symbol is not resolved")
      for (auto& neighbours : j["neighbours"]) {  // @suppress("Symbol is not resolved")
        for (auto& dimensionality : j["dimensionality"]) {  // @suppress("Symbol is not resolved")
          double eval = 0;

          if (algorithm == "RandomSearch") {

            RandomSearch* algorithmRS = new RandomSearch();
            for (int i = 0; i < runs; i++) {
              Record* resultRS = algorithmRS->process(dimensionality,
                                                      function->getLower(),
                                                      function->getUpper(),
                                                      tweak, funcEvaluations,
                                                      function);
              std::string a = resultRS->toString();
              eval += resultRS->getFitness();
              //      std::cout << i << std::endl;
            }

          } else {

            IteratedLocalSearchN* algorithmN = new IteratedLocalSearchN();

            for (int i = 0; i < runs; i++) {
              Record* resultN = algorithmN->process(dimensionality, neighbours,
                                                    function->getLower(),
                                                    function->getUpper(), tweak,
                                                    perturbation,
                                                    funcEvaluations, function);
              eval += resultN->getFitness();
              //      std::cout << resultN->toString() << std::endl;
            }

          }
          eval /= runs;
          std::cout << eval << "\t";
        }
        std::cout << std::endl;
      }
    }
  }

  return 0;
}
