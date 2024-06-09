// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cmath>

double pown(double value, uint16_t n) {
    double result = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        result *= value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  int cnt = count;
  double result = 0;
  while (cnt > 0) {
    result += calcItem(x, cnt);
      cnt--;
  }
  return ++result;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    for (uint16_t i = 0; i < count; ++i) {
        double term = calcItem(x, 2 * i + 1);
        if (i % 2 == 0) {
            sum += term;
        } else {
            sum -= term;
        }
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 1.0;
    for (uint16_t i = 1; i < count; ++i) {
        double term = calcItem(x, 2 * i);
        if (i % 2 == 0) {
            sum += term;
        } else {
            sum -= term;
        }
    }
    return sum;
}
