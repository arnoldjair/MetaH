/*
 * Sphere.cpp
 *
 *  Created on: 30/09/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include "Sphere.h"

Sphere::Sphere() {
  this->evaluationCount = 0;
}

Sphere::~Sphere() {
  std::cout << "Bye bye sphere" << std::endl;
}

double Sphere::evaluate(Record& record) {
  double ret = 0;
  for (int i = 0; i < record.getDimensionality(); ++i) {
    ret += pow(record.getData()[i], 2);
  }
  this->evaluationCount++;
  return sqrt(ret);
}

int Sphere::getEvaluationCount() {
  return this->evaluationCount;
}
