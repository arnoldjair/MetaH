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
  ~Rastrigin();
  virtual double evaluate(Record& record);
  virtual int getEvaluationCount();
  virtual void resetEvaluationCount();
  virtual double compare(Record* record1, Record* record2);
  virtual double getLower();
  virtual double getUpper();
 private:
  int evaluationCount;
};

#endif /* RASTRIGIN_H_ */
