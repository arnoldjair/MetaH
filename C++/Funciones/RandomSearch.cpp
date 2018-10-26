/*
 * RandomSearch.cpp
 *
 *  Created on: 25/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#include "RandomSearch.h"

RandomSearch::RandomSearch() {
  // TODO Auto-generated constructor stub

}

RandomSearch::~RandomSearch() {
  // TODO Auto-generated destructor stub
}

Record* RandomSearch::process(int dimensionality, double lower, double upper,
                              double tweak, int funcEvaluations,
                              Function* function) {

  std::unique_ptr<Record> s(
      Record::randomRecord(dimensionality, lower, upper, tweak));
  std::unique_ptr<Record> best = std::make_unique<Record>();
  s->setFitness(function->evaluate(*s));
  best->copy(s.get());
  function->resetEvaluationCount();
  do {
    s->copy(Record::randomRecord(dimensionality, lower, upper, tweak));
    s->setFitness(function->evaluate(*s));
    if (s->getFitness() < best->getFitness()) {
      best->copy(s.get());
    }
  } while (function->getEvaluationCount() < funcEvaluations);
  return best.get();
}
