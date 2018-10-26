/*
 * Rastrigin.cpp
 *
 *  Created on: 12/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include "Rastrigin.h"

Rastrigin::Rastrigin() {
  this->evaluationCount = 0;
}

Rastrigin::~Rastrigin() {
  std::cout << "Bye bye rastrigin" << std::endl;
}

double Rastrigin::evaluate(Record& record) {
  double ret = 0;

  int i = 0;

  double sum = 0;

  for (i = 0; i < record.getDimensionality(); i++) {
    sum = sum + pow((double) record.getData()[i], 2)
        - 10 * cos(2 * M_PI * (double) record.getData()[i]);
  }

  ret = 10 * record.getDimensionality() + sum;

  this->evaluationCount++;
  return ret;
}

int Rastrigin::getEvaluationCount() {
  return this->evaluationCount;
}

double Rastrigin::compare(Record* record1, Record* record2) {
  return record1->getFitness() <= record2->getFitness() ? -1 : 1;
}

double Rastrigin::getLower() {
  return -5.12;
}

void Rastrigin::resetEvaluationCount() {
  this->evaluationCount = 0;
}

double Rastrigin::getUpper() {
  return 5.12;
}
