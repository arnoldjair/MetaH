/*
 * Ackley.h
 *
 *  Created on: 11/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#ifndef ACKLEY_H_
#define ACKLEY_H_

#include "Function.h"
#include "Record.h"

class Ackley : public Function {
 public:
  Ackley();
  virtual ~Ackley();
  virtual double evaluate(Record& record);
  virtual int getEvaluationCount();
  virtual double compare(Record* record1, Record* record2);
  virtual double getLower();
  virtual double getUpper();

 private:
  int evaluationCount;
};

#endif /* ACKLEY_H_ */
