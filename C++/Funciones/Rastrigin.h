/*
 * Rastrigin.h
 *
 *  Created on: 12/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#ifndef RASTRIGIN_H_
#define RASTRIGIN_H_

#include "Function.h"

class Rastrigin : public Function {
 public:
  Rastrigin();
  virtual ~Rastrigin();
  virtual double evaluate(Record& record);
};

#endif /* RASTRIGIN_H_ */
