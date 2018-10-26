/*
 * Function.h
 *
 *  Created on: 30/09/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_

#include "Record.h"

class Function {
public:
	Function();
	virtual ~Function();
  virtual double evaluate(Record& record) = 0;
  virtual int getEvaluationCount() = 0;
  virtual void resetEvaluationCount() = 0;
  virtual double compare(Record* record1, Record* record2) = 0;
  virtual double getLower() = 0;
  virtual double getUpper() = 0;
};

#endif /* FUNCTION_H_ */
