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

#include "IteratedLocalSearch.h"

IteratedLocalSearch::IteratedLocalSearch() {
}

IteratedLocalSearch::~IteratedLocalSearch() {
}

Record* IteratedLocalSearch::process(int dimentionlity,
                                                     double lower, double upper,
                                                     double radius,
                                                     double perturbation,
                                                     unsigned long maxRandTime,
                                                     unsigned long totalTime,
                                                     Function* function) {

  std::unique_ptr<Record> s(
      Record::randomRecord(dimentionlity, lower, upper, radius));

  s->setFitness(function->evaluate(*s));
  std::unique_ptr<Record> h = std::make_unique<Record>();
  std::unique_ptr<Record> best = std::make_unique<Record>();
  std::unique_ptr<Record> r = std::make_unique<Record>();
  h->copy(s.get());
  best->copy(s.get());

  bool cont = true;
  unsigned long long elapsed = 0;
  unsigned long long totalElapsed = 0;

  do {
    double time = Utils::doubleRandBetween(0, maxRandTime);
    elapsed = 0;
    do {
      auto begin = std::chrono::high_resolution_clock::now();
      s->tweak(r.get());
      r->setFitness(function->evaluate(*r));
      if (r->getFitness() < s->getFitness()) {
        s->copy(r.get());
      }
      auto end = std::chrono::high_resolution_clock::now();
      auto ms =
          std::chrono::duration_cast<std::chrono::microseconds>(
          end - begin);
      elapsed += ms.count();
    } while (elapsed <= (time * 1000));

    totalElapsed += (elapsed / 1000);

    if (s->getFitness() < best->getFitness()) {
      best->copy(s.get());
    }

    if (s->getFitness() < h->getFitness()) {
      h->copy(s.get());
    }

    h->perturb(perturbation, s.get());
    s->setFitness(function->evaluate(*s));
  } while (totalElapsed <= totalTime);
  return best.get();
}
