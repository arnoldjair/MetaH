/*
 * FunctionFactory.h
 *
 *  Created on: 24/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#ifndef FUNCTIONFACTORY_H_
#define FUNCTIONFACTORY_H_

#include <iostream>
#include "Function.h"

class FunctionFactory {
 public:
  FunctionFactory();
  virtual ~FunctionFactory();
  static Function* getFunction(std::string functionName);
};

#endif /* FUNCTIONFACTORY_H_ */
