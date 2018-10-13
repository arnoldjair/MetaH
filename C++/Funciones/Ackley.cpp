/*
 * Ackley.cpp
 *
 *  Created on: 11/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include "Ackley.h"

Ackley::Ackley() {
}

Ackley::~Ackley() {
  std::cout << "Bye bye ackley" << std::endl;
}

double Ackley::evaluate(Record& record) {
  double ret = 0;

  double sum_x = 0;
  double sum_cos = 0;

  int i = 0;

  for (i = 0; i < record.getDimensionality(); i++) {
    sum_x = sum_x + pow(record.getData()[i], 2);
    sum_cos = sum_cos + cos(2 * M_PI * record.getData()[i]);
  }

  ret = -20 * exp(-0.2 * sqrt(sum_x / record.getDimensionality()))
      - exp(sum_cos / record.getDimensionality()) + 20 + exp(1);

  return ret;
}
