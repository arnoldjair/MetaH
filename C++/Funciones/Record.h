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

class Record {
 public:
  Record();
  Record(int dimentionality, double lower, double upper);
  virtual ~Record();

  static Record* randomRecord(int dimentionality, double lower,
                                    double upper);

  const std::vector<double>& getData() const;
  void setData(const std::vector<double>& data);
  int getDimentionality() const;
  void setDimentionality(int dimentionality);
  double getLower() const;
  void setLower(double lower);
  double getUpper() const;
  void setUpper(double upper);
  double getFitness() const;
  void setFitness(double fitness);

 private:
  int dimentionality;
  double lower;
  double upper;
  double fitness;
  std::vector<double> data;
};

#endif /* RECORD_H_ */
