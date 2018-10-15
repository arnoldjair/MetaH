/*
 * Utils.cpp
 *
 *  Created on: 13/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#include "Utils.h"

Utils::Utils() {
  // TODO Auto-generated constructor stub

}

Utils::~Utils() {
  // TODO Auto-generated destructor stub
}

double Utils::doubleRandBetween(double lower, double upper) {
  std::uniform_real_distribution<double> distribution(lower, upper);
  std::random_device rd;
  std::default_random_engine generator(rd());

  return distribution(generator);
}
