/*
 * Record.h
 *
 *  Created on: 8/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#ifndef RECORD_H_
#define RECORD_H_

#include <vector>
#include <cstdlib>
#include <string>
#include <memory>
#include "Utils.h"

class Record {
 public:
  Record();
  Record(int dimensionality, double lower, double upper, double r);
  virtual ~Record();

  static std::unique_ptr<Record> randomRecord(int dimensionality, double lower,
                                              double upper, double r);

  const std::vector<double>& getData() const;
  void setData(const std::vector<double>& data);
  int getDimensionality() const;
  void setDimensionality(int dimensionality);
  double getLower() const;
  void setLower(double lower);
  double getUpper() const;
  void setUpper(double upper);
  double getFitness() const;
  void setFitness(double fitness);

  std::unique_ptr<Record> tweak();
  std::unique_ptr<Record> perturb(double perturbation);
  std::unique_ptr<Record> clone();
  std::string toString();

 private:
  int dimensionality;
  double lower;
  double upper;
  double r;
  double fitness;
  std::vector<double> data;
};

#endif /* RECORD_H_ */
