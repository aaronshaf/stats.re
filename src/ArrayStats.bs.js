// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var $$Array     = require("bs-platform/lib/js/array.js");
var Caml_array  = require("bs-platform/lib/js/caml_array.js");
var Pervasives  = require("bs-platform/lib/js/pervasives.js");
var ArrayLabels = require("bs-platform/lib/js/arrayLabels.js");

function max(x) {
  return ArrayLabels.fold_left(Pervasives.max, Caml_array.caml_array_get(x, 0), x);
}

function min(x) {
  return ArrayLabels.fold_left(Pervasives.min, Caml_array.caml_array_get(x, 0), x);
}

function product(x) {
  return ArrayLabels.fold_left((function (a, b) {
                return a * b;
              }), 1, x);
}

function sum_simple(x) {
  return ArrayLabels.fold_left((function (a, b) {
                return a + b;
              }), 0, x);
}

function mean(x) {
  return sum_simple(x) / x.length;
}

function sort(x) {
  var clonedArray = ArrayLabels.copy(x);
  ArrayLabels.fast_sort((function (a, b) {
          if (a > b) {
            return 1;
          } else if (a < b) {
            return -1;
          } else {
            return 0;
          }
        }), clonedArray);
  return clonedArray;
}

function quantile_sorted(quantile, x) {
  var length = x.length;
  var is_quantile_integer = +((quantile | 0) === quantile);
  var index = length * quantile;
  if (quantile === 1) {
    return Caml_array.caml_array_get(x, length - 1 | 0);
  } else if (quantile === 0) {
    return Caml_array.caml_array_get(x, 0);
  } else if (is_quantile_integer) {
    if (length % 2) {
      return Caml_array.caml_array_get(x, index | 0);
    } else {
      return (Caml_array.caml_array_get(x, (index | 0) - 1 | 0) + Caml_array.caml_array_get(x, index | 0)) / 2;
    }
  } else {
    return Caml_array.caml_array_get(x, Math.ceil(index) - 1 | 0);
  }
}

function quantile(quantile$1, x) {
  var sorted_array = sort(x);
  return quantile_sorted(quantile$1, sorted_array);
}

function median(x) {
  return quantile(0.5, x);
}

function root_mean_square(x) {
  var sumOfSquares = ArrayLabels.fold_left((function (prev, b) {
          return prev + Math.pow(b, 2);
        }), 0, x);
  return Math.sqrt(sumOfSquares / x.length);
}

function min_sorted(x) {
  return Caml_array.caml_array_get(x, 0);
}

function sum_nth_power_deviations(x, n) {
  var meanValue = mean(x);
  return $$Array.fold_left((function (prev, current) {
                return prev + Math.pow(current - meanValue, n);
              }), 0, x);
}

function variance(x) {
  return sum_nth_power_deviations(x, 2) / x.length;
}

exports.max                      = max;
exports.min                      = min;
exports.product                  = product;
exports.sum_simple               = sum_simple;
exports.mean                     = mean;
exports.sort                     = sort;
exports.quantile_sorted          = quantile_sorted;
exports.quantile                 = quantile;
exports.median                   = median;
exports.root_mean_square         = root_mean_square;
exports.min_sorted               = min_sorted;
exports.sum_nth_power_deviations = sum_nth_power_deviations;
exports.variance                 = variance;
/* No side effect */
