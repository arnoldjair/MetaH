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
double Sphere::compare(Record* record1, Record* record2) {
  return record1->getFitness() <= record2->getFitness() ? -1 : 1;
}

double Sphere::getLower() {
  return -100;
}

void Sphere::resetEvaluationCount() {
  this->evaluationCount = 0;
}

double Sphere::getUpper() {
  return 100;
}
