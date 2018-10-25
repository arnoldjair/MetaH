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

using json = nlohmann::json;

int main(int argc, char *argv[]) {

  std::ifstream i(argv[1]);
  json j;
  i >> j;

  std::cout << j["message"] << std::endl;
//  IteratedLocalSearchT* algorithm = new IteratedLocalSearchT();
//  Record* result = algorithm->process(100, -1, 1, 0.01, 0.1, 1000, 10000,
//                                      new Sphere());
//
//  std::cout << result->toString() << std::endl;

  IteratedLocalSearchN* algorithmN = new IteratedLocalSearchN();
  Record* resultN = algorithmN->process(100, 20, -1, 1, 0.01, 0.1, 5000,
                                        new Sphere);
  std::cout << resultN->toString() << std::endl;
  return 0;
}
