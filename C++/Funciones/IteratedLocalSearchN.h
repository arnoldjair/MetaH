/*
 * IteratedLocalSearch.h
 *
 *  Created on: 12/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#ifndef ITERATEDLOCALSEARCH_H_
#define ITERATEDLOCALSEARCH_H_

#include "Function.h"
#include "Record.h"
class IteratedLocalSearchN {
 public:
  IteratedLocalSearchN();
  virtual ~IteratedLocalSearchN();

  /**
   * Time in miliseconds
   */
  Record* process(int dimentionality, int neighbours, double lower,
                  double upper, double tweak, double perturbation,
                  int funcEvaluations, Function* function);

};

#endif /* ITERATEDLOCALSEARCH_H_ */
