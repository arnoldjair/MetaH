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
  Record* process(int dimensionality, double lower, double upper, double radius,
                  double perturbation, unsigned long maxRandTime,
                  unsigned long totalTime, Function* function);

};

#endif /* ITERATEDLOCALSEARCHT_H_ */
