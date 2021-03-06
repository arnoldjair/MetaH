/*
 * Sphere.h
 *
 *  Created on: 30/09/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include "Function.h"
#include "Record.h"

class Sphere : public Function {
 public:
  Sphere();
  virtual ~Sphere();
  virtual double evaluate(Record& record);
  virtual int getEvaluationCount();
  virtual void resetEvaluationCount();
  virtual double compare(Record* record1, Record* record2);
  virtual double getLower();
  virtual double getUpper();
 private:
  int evaluationCount;

};

#endif /* SPHERE_H_ */
