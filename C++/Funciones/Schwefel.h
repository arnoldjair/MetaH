/*
 * Schwefel.h
 *
 *  Created on: 12/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#ifndef SCHWEFEL_H_
#define SCHWEFEL_H_

#include "Function.h"

class Schwefel : public Function {
 public:
  Schwefel();
  virtual ~Schwefel();
  virtual double evaluate(Record& record);
  virtual int getEvaluationCount();
  virtual void resetEvaluationCount();
  virtual double compare(Record* record1, Record* record2);
  virtual double getLower();
  virtual double getUpper();
 private:
  int evaluationCount;
};

#endif /* SCHWEFEL_H_ */
