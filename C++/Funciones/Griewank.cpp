/*
 * Griewank.cpp
 *
 *  Created on: 11/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include "Griewank.h"

Griewank::Griewank() {
}

Griewank::~Griewank() {
  std::cout << "Bye bye griewank" << std::endl;
}

double Griewank::evaluate(Record& record) {
  double ret = 0;
  double sum_squares = 0;
  double product = 1;

  int i = 0;

  for (i = 0; i < record.getDimensionality(); i++) {
    sum_squares = sum_squares + pow(record.getData()[i], 2);
    product = product * cos(record.getData()[i] / sqrt(i + 1));
  }

  sum_squares = sum_squares / 4000;
  ret = sum_squares - product + 1;

  return ret;
}
