/*
 * PowellSum.cpp
 *
 *  Created on: 25/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */
#define _USE_MATH_DEFINES

#include <cmath>
#include "PowellSum.h"

PowellSum::PowellSum() {
  this->evaluationCount = 0;

}

PowellSum::~PowellSum() {
  // TODO Auto-generated destructor stub
}

double PowellSum::evaluate(Record& record) {
  double ret = 0;

  for (int i = 0; i < record.getDimensionality(); ++i) {
    ret += pow(fabs(record.getData()[i]), i + 2);
  }

  this->evaluationCount++;
  return ret;
}

int PowellSum::getEvaluationCount() {
  return this->evaluationCount;
}

void PowellSum::resetEvaluationCount() {
  this->evaluationCount = 0;
}

double PowellSum::compare(Record* record1, Record* record2) {
  return record1->getFitness() <= record2->getFitness() ? -1 : 1;
}

double PowellSum::getLower() {
  return -10;
}

double PowellSum::getUpper() {
  return 10;
}
