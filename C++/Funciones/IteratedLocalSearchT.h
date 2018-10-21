/*
 * IteratedLocalSearch.h
 *
 *  Created on: 12/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#ifndef ITERATEDLOCALSEARCHT_H_
#define ITERATEDLOCALSEARCHT_H_

#include "Function.h"
#include "Record.h"
class IteratedLocalSearchT {
 public:
  IteratedLocalSearchT();
  virtual ~IteratedLocalSearchT();

  /**
   * Time in miliseconds
   */
  Record* process(int dimentionality, int neighbours, double lower,
                  double upper, double tweak, double perturbation,
                  int funcEvaluations, Function* function);

};

#endif /* ITERATEDLOCALSEARCHT_H_ */
