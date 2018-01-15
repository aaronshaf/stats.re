// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var List       = require("bs-platform/lib/js/list.js");
var ListLabels = require("bs-platform/lib/js/listLabels.js");
var Pervasives = require("bs-platform/lib/js/pervasives.js");

function max(x) {
  return ListLabels.fold_left(Pervasives.max, List.hd(x), x);
}

function min(x) {
  return ListLabels.fold_left(Pervasives.min, List.hd(x), x);
}

function product(x) {
  return ListLabels.fold_left((function (a, b) {
                return a * b;
              }), 1, x);
}

function sum_simple(x) {
  return ListLabels.fold_left((function (a, b) {
                return a + b;
              }), 0, x);
}

function mean(x) {
  return sum_simple(x) / List.length(x);
}

function sort(x) {
  return ListLabels.fast_sort((function (a, b) {
                if (a > b) {
                  return 1;
                } else if (a < b) {
                  return -1;
                } else {
                  return 0;
                }
              }), x);
}

function quantile_sorted(quantile, x) {
  var length = List.length(x);
  var is_quantile_integer = +((quantile | 0) === quantile);
  var index = length * quantile;
  if (quantile === 1) {
    return List.nth(x, length - 1 | 0);
  } else if (quantile === 0) {
    return List.hd(x);
  } else if (is_quantile_integer) {
    if (length % 2) {
      return List.nth(x, index | 0);
    } else {
      return (List.nth(x, (index | 0) - 1 | 0) + List.nth(x, index | 0)) / 2;
    }
  } else {
    return List.nth(x, Math.ceil(index) - 1 | 0);
  }
}

function quantile(quantile$1, x) {
  var sorted_list = sort(x);
  return quantile_sorted(quantile$1, sorted_list);
}

function median(x) {
  return quantile(0.5, x);
}

function root_mean_square(x) {
  var sumOfSquares = ListLabels.fold_left((function (prev, b) {
          return prev + Math.pow(b, 2);
        }), 0, x);
  return Math.sqrt(sumOfSquares / List.length(x));
}

var min_sorted = List.hd;

exports.max              = max;
exports.min              = min;
exports.product          = product;
exports.sum_simple       = sum_simple;
exports.mean             = mean;
exports.sort             = sort;
exports.quantile_sorted  = quantile_sorted;
exports.quantile         = quantile;
exports.median           = median;
exports.root_mean_square = root_mean_square;
exports.min_sorted       = min_sorted;
/* No side effect */