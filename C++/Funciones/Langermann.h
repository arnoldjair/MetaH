/*
 * Langerman.h
 *
 *  Created on: 24/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#ifndef LANGERMANN_H_
#define LANGERMANN_H_

#include "Function.h"

class Langermann : public Function {
 public:
  Langermann();
  virtual ~Langermann();
  virtual double evaluate(Record& record);
  virtual int getEvaluationCount();
  virtual double compare(Record* record1, Record* record2);
  virtual double getLower();
  virtual double getUpper();

 private:
  int evaluationCount;
};

#endif /* LANGERMANN_H_ */
