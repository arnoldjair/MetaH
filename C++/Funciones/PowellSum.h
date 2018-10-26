/*
 * PowellSum.h
 *
 *  Created on: 25/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#ifndef POWELLSUM_H_
#define POWELLSUM_H_

#include "Function.h"

/**
 * Unimodal separable
 */
class PowellSum : public Function {
 public:
  PowellSum();
  virtual ~PowellSum();
  virtual double evaluate(Record& record);
  virtual int getEvaluationCount();
  virtual void resetEvaluationCount();
  virtual double compare(Record* record1, Record* record2);
  virtual double getLower();
  virtual double getUpper();
 private:
  int evaluationCount;
};

#endif /* POWELLSUM_H_ */
