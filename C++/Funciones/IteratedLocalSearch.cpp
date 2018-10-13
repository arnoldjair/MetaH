/*
 * IteratedLocalSearch.cpp
 *
 *  Created on: 12/10/2018
 *      Author: Arnold Jair Jiménez Vargas <arnoldjair at gmail dot com>
 */

#include <iostream>
#include <random>
#include <chrono>

#include "IteratedLocalSearch.h"

IteratedLocalSearch::IteratedLocalSearch() {
}

IteratedLocalSearch::~IteratedLocalSearch() {
  std::cout << "Bye bye iterated local search" << std::endl;
}

Record* IteratedLocalSearch::process(int dimentionlity, double lower,
                                     double upper, double r,
                                     double perturbation,
                                     unsigned long long int totalTime,
                                     unsigned long long int maxTime,
                                     Function* function) {

  Record* s = Record::randomRecord(dimentionlity, lower, upper, r);
  s->setFitness(function->evaluate(*s));
  Record* h = s;
  Record* best = s;

  bool cont = true;
  unsigned long long elapsed = 0;
  while (cont) {
    double time = maxTime * ((rand() / ( RAND_MAX + 1.)));
    //TODO: Revisar pe.
    auto begin = std::chrono::high_resolution_clock::now();
  do {
      Record* r = s->tweak();
      r->setFitness(function->evaluate(*s));
      if (r->getFitness() > s->getFitness()) {
        delete s;
        s = r;
      }
      auto end = std::chrono::high_resolution_clock::now();
      auto dur = end - begin;
      auto ms =
          std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
      if (ms <= time) {

      }
    } while (elapsed < totalTime);
  }

  return 0;
}
