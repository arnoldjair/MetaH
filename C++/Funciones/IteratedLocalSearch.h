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
class IteratedLocalSearch {
 public:
  IteratedLocalSearch();
  virtual ~IteratedLocalSearch();

  /**
   * Time in miliseconds
   */
  Record* process(int dimentionality, double lower,
                                  double upper, double radius,
                                  double perturbation,
                                  unsigned long maxRandTime,
                                  unsigned long totalTime, Function* function);

};

#endif /* ITERATEDLOCALSEARCH_H_ */
