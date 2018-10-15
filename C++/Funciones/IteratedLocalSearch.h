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
  std::unique_ptr<Record> process(int dimentionality, double lower,
                                  double upper, double radius,
                                  double perturbation,
                                  unsigned long maxRandTime,
                                  unsigned long totalTime, Function* function);

  std::unique_ptr<Record> newHomeBase(auto s,
                                      auto h);
};

#endif /* ITERATEDLOCALSEARCH_H_ */
