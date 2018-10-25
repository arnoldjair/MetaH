/*
 * IteratedLocalSearch.cpp
 *
 *  Created on: 12/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#include <iostream>
#include <random>
#include <chrono>
#include <thread>

#include "IteratedLocalSearchN.h"

IteratedLocalSearchN::IteratedLocalSearchN() {
}

IteratedLocalSearchN::~IteratedLocalSearchN() {
}

Record* IteratedLocalSearchN::process(int dimensionality, int neighbours,
                                     double lower, double upper, double tweak,
                                     double perturbation, int funcEvaluations,
                                     Function* function) {

  std::unique_ptr<Record> s(
      Record::randomRecord(dimensionality, lower, upper, tweak));

  s->setFitness(function->evaluate(*s));
  std::unique_ptr<Record> h = std::make_unique<Record>();
  std::unique_ptr<Record> best = std::make_unique<Record>();
  std::unique_ptr<Record> r = std::make_unique<Record>();
  h->copy(s.get());
  best->copy(s.get());

  bool cont = true;
  int currNeighbours = 0;

  do {
    currNeighbours = 0;

    do {
      currNeighbours++;
      s->tweak(r.get());
      r->setFitness(function->evaluate(*r));
      if (r->getFitness() < s->getFitness()) {
        s->copy(r.get());
      }
    } while (currNeighbours < neighbours);

    if (s->getFitness() < best->getFitness()) {
      best->copy(s.get());
    }

    if (s->getFitness() < h->getFitness()) {
      h->copy(s.get());
    }

    h->perturb(perturbation, s.get());
    s->setFitness(function->evaluate(*s));
  } while (function->getEvaluationCount() < funcEvaluations);
  return best.get();
}
