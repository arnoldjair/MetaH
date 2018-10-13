/*
 * Utils.h
 *
 *  Created on: 13/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <random>

class Utils {
 public:
  Utils();
  virtual ~Utils();
  static double doubleRandBetween(double lower, double upper);
};

#endif /* UTILS_H_ */
