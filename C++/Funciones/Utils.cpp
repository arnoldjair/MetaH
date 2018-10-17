/*
 * Utils.cpp
 *
 *  Created on: 13/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#include <iostream>
#include "Utils.h"

std::random_device Utils::rd;
std::uniform_real_distribution<double> Utils::distribution(0, 1.);

Utils::Utils() {
  // TODO Auto-generated constructor stub

}

Utils::~Utils() {
  // TODO Auto-generated destructor stub
}

double Utils::doubleRandBetween(double lower, double upper) {
  //std::uniform_real_distribution<double> distribution(lower, upper);
//  std::random_device rd;
  std::default_random_engine generator(Utils::rd());
  return lower + ((upper - lower) * Utils::distribution(generator));
}
