/*
 * RandomSearch.h
 *
 *  Created on: 25/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#ifndef RANDOMSEARCH_H_
#define RANDOMSEARCH_H_

#include <iostream>
#include "Record.h"
#include "Function.h"

class RandomSearch {
 public:
  RandomSearch();
  virtual ~RandomSearch();
  Record* process(int dimensionality, double lower, double upper, double tweak,
                  int funcEvaluations, Function* function);
};

#endif /* RANDOMSEARCH_H_ */
