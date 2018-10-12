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
};

#endif /* FUNCTION_H_ */
