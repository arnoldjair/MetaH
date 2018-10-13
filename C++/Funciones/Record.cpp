/*
 * Record.cpp
 *
 *  Created on: 8/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#include <iostream>
#include "Record.h"

Record::Record() {
  this->dimensionality = 0;
  this->lower = -1.0;
  this->upper = 1.0;
  this->r = 0.1;
  this->fitness = 0;
}

Record::Record(int dimentionality, double lower, double upper, double r) {
  this->dimensionality = dimentionality;
  this->lower = lower;
  this->upper = upper;
  this->r = r;
  this->fitness = 0;
}

Record::~Record() {
  std::cout << "Bye bye record" << std::endl;
}

Record* Record::randomRecord(int dimentionality, double lower, double upper,
                             double r) {
  if (dimentionality < 1) {
    return 0;
  }
  std::vector<double> data;
  for (int i = 0; i < dimentionality; ++i) {
    double value = Utils::doubleRandBetween(lower, upper);
    //((double) rand() * (upper - lower) / (double) RAND_MAX
    //- lower);
    data.push_back(value);
  }
  Record* record = new Record(dimentionality, lower, upper, r);
  record->setData(data);
  return record;
}

const std::vector<double>& Record::getData() const {
  return data;
}

void Record::setData(const std::vector<double>& data) {
  this->data = data;
}

int Record::getDimensionality() const {
  return dimensionality;
}

void Record::setDimensionality(int dimentionality) {
  this->dimensionality = dimentionality;
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

Record* Record::tweak() {
  std::vector<double> data;
  for (int i = 0; i < this->dimensionality; ++i) {
    double value = Utils::doubleRandBetween(lower, upper);
    data.push_back(value);
  }
  Record* ret = new Record(this->dimensionality, this->lower, this->upper,
                              this->r);
  ret->setData(data);
  return ret;
}

std::string Record::toString() {
  std::string ret = "";
  ret += "Dimentionality: " + std::to_string(this->dimensionality) + "\n";
  ret += "Lower: " + std::to_string(this->lower) + "\n";
  ret += "Upper: " + std::to_string(this->upper) + "\n";

  return ret;
}
