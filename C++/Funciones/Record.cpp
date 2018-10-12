/*
 * Record.cpp
 *
 *  Created on: 8/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#include <iostream>
#include "Record.h"

Record::Record() {
  this->dimentionality = 0;
  this->lower = -1.0;
  this->upper = 1.0;
}

Record::Record(int dimentionality, double lower, double upper) {
  this->dimentionality = dimentionality;
  this->lower = lower;
  this->upper = upper;
}

Record::~Record() {
  std::cout << "Bye bye record" << std::endl;
}

Record* Record::randomRecord(int dimentionality, double lower, double upper) {
  if (dimentionality < 1) {
    return 0;
  }
  std::vector<double> data;
  for (int i = 0; i < dimentionality; ++i) {
    double value = ((double) rand() * (upper - lower) / (double) RAND_MAX
        - lower);
    data.push_back(value);
  }
  Record* record = new Record(dimentionality, lower, upper);
  record->setData(data);
  return record;
}

const std::vector<double>& Record::getData() const {
  return data;
}

void Record::setData(const std::vector<double>& data) {
  this->data = data;
}

int Record::getDimentionality() const {
  return dimentionality;
}

void Record::setDimentionality(int dimentionality) {
  this->dimentionality = dimentionality;
}

double Record::getLower() const {
  return lower;
}

void Record::setLower(double lower) {
  this->lower = lower;
}

double Record::getUpper() const {
  return upper;
}

void Record::setUpper(double upper) {
  this->upper = upper;
}

double Record::getFitness() const {
  return fitness;
}

void Record::setFitness(double fitness) {
  this->fitness = fitness;
}
