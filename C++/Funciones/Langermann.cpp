/*
 * Langerman.cpp
 *
 *  Created on: 24/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#include "Langermann.h"

Langermann::Langermann() {
  this->evaluationCount = 0;

}

Langermann::~Langermann() {
  // TODO Auto-generated destructor stub
}

double Langermann::evaluate(Record& record) {
  double ret = 0;
  return ret;
}

int Langermann::getEvaluationCount() {
  return this->evaluationCount;
}

double Langermann::compare(Record* record1, Record* record2) {
  return record1->getFitness() <= record2->getFitness() ? -1 : 1;
}

double Langermann::getLower() {
  return 0;
}

double Langermann::getUpper() {
  return 10;
}
