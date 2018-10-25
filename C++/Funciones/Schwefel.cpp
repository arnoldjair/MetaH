/*
 * Schwefel.cpp
 *
 *  Created on: 12/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include "Schwefel.h"

Schwefel::Schwefel() {
  this->evaluationCount = 0;
}

Schwefel::~Schwefel() {
  std::cout << "Bye bye schwefel" << std::endl;
}

double Schwefel::evaluate(Record& record) {
  double ret = 0;
  double sum;

  int i = 0;

  for (i = 0; i < record.getDimensionality(); i++) {
    sum = sum + record.getData()[i] * sin(sqrt(fabs(record.getData()[i])));
  }

  ret = 418.9829 * record.getDimensionality() - sum;

  return ret;
}

int Schwefel::getEvaluationCount() {
  return this->evaluationCount;
}

double Schwefel::compare(Record* record1, Record* record2) {
  return record1->getFitness() <= record2->getFitness() ? -1 : 1;
}

double Schwefel::getLower() {
  return -500;
}

double Schwefel::getUpper() {
  return 500;
}
