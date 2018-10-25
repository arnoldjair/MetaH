/*
 * FunctionFactory.cpp
 *
 *  Created on: 24/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#include "FunctionFactory.h"
#include "Ackley.h"
#include "Griewank.h"
#include "Rastrigin.h"
#include "Schwefel.h"
#include "Sphere.h"

FunctionFactory::FunctionFactory() {
  // TODO Auto-generated constructor stub

}

FunctionFactory::~FunctionFactory() {
  // TODO Auto-generated destructor stub
}

Function* FunctionFactory::getFunction(std::string functionName) {
  if (functionName == "Ackley") {
    return new Ackley();
  }

  if (functionName == "Griewank") {
    return new Griewank();
  }

  if (functionName == "Rastrigin") {
    return new Rastrigin();
  }

  if (functionName == "Schwefel") {
    return new Schwefel();
  }

  if (functionName == "Sphere") {
    return new Sphere();
}


  return NULL;
}
