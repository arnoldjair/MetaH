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
}

Schwefel::~Schwefel() {
  std::cout << "Bye bye schwefel" << std::endl;
}

double Schwefel::evaluate(Record& record) {
  double ret = 0;
  double sum;

  int i = 0;

  for (i = 0; i < record.getDimentionality(); i++) {
    sum = sum + record.getData()[i] * sin(sqrt(fabs(record.getData()[i])));
  }

  ret = 418.9829 * record.getDimentionality() - sum;

  return ret;
}
