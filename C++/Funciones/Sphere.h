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

class Sphere: public Function {
 public:
	Sphere();
  Sphere(bool minimizes);
	virtual ~Sphere();
  virtual double evaluate(Record& record);
  virtual int getEvaluationCount();
 private:
  int evaluationCount;
  virtual double compare(Record* record1, Record* record2);

  bool isMinimizes() const {
    return minimizes;
  }

  void setMinimizes(bool minimizes) {
    this->minimizes = minimizes;
  }

 private:
  bool minimizes;
};

#endif /* SPHERE_H_ */
