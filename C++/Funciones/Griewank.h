/*
 * Griewank.h
 *
 *  Created on: 11/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#ifndef GRIEWANK_H_
#define GRIEWANK_H_

#include "Function.h"

class Griewank : public Function {
 public:
  Griewank();
  virtual ~Griewank();
  virtual double evaluate(Record& record);
};

#endif /* GRIEWANK_H_ */
