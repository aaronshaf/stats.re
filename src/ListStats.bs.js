// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var List       = require("bs-platform/lib/js/list.js");
var Stats      = require("./Stats.bs.js");
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

function sum(x) {
  var initial_000 = List.hd(x);
  var initial = /* tuple */[
    initial_000,
    0
  ];
  return List.fold_left((function (param, current) {
                  var correction = param[1];
                  var sum = param[0];
                  var newSum = sum + current;
                  if (Math.abs(sum) >= Math.abs(current)) {
                    var newCorrection = correction + (sum - newSum + current);
                    return /* tuple */[
                            newSum,
                            newCorrection
                          ];
                  } else {
                    var newCorrection$1 = correction + (current - newSum + sum);
                    return /* tuple */[
                            newSum,
                            newCorrection$1
                          ];
                  }
                }), initial, List.tl(x))[0];
}

function sum_simple(x) {
  return ListLabels.fold_left((function (a, b) {
                return a + b;
              }), 0, x);
}

function mean(x) {
  return sum(x) / List.length(x);
}

function mean_fold(x) {
  return List.fold_left((function (param, valueToAdd) {
                  var previousLength = param[1];
                  return /* tuple */[
                          Stats.Utils[/* add_to_mean */0](param[0], previousLength, valueToAdd),
                          previousLength + 1
                        ];
                }), /* tuple */[
                0,
                0
              ], x)[0];
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

function interquartile_range(x) {
  return quantile(0.75, x) - quantile(0.25, x);
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

function sum_nth_power_deviations(x, n) {
  var meanValue = mean(x);
  return List.fold_left((function (sum, current) {
                return sum + Math.pow(current - meanValue, n);
              }), 0, x);
}

function variance(x) {
  return sum_nth_power_deviations(x, 2) / List.length(x);
}

function geometric_mean(growthRates) {
  var match = List.fold_left((function (param, current) {
          return /* tuple */[
                  param[0] * current,
                  param[1] + 1
                ];
        }), /* tuple */[
        1,
        0
      ], growthRates);
  return Math.pow(match[0], 1 / match[1]);
}

function mode_sorted(x) {
  return List.fold_left((function (param, current) {
                  var contender = param[2];
                  var defenderScore = param[1];
                  var defender = param[0];
                  if (contender === current) {
                    var contenderScore = param[3];
                    if (contenderScore >= defenderScore) {
                      return /* tuple */[
                              contender,
                              contenderScore + 1 | 0,
                              contender,
                              contenderScore + 1 | 0
                            ];
                    } else {
                      return /* tuple */[
                              defender,
                              defenderScore,
                              contender,
                              contenderScore + 1 | 0
                            ];
                    }
                  } else {
                    return /* tuple */[
                            defender,
                            defenderScore,
                            current,
                            1
                          ];
                  }
                }), /* tuple */[
                List.hd(x),
                1,
                List.hd(x),
                1
              ], List.tl(x))[0];
}

function mode(x) {
  return mode_sorted(sort(x));
}

function harmonic_mean(x) {
  var match = List.fold_left((function (param, current) {
          return /* tuple */[
                  param[0] + 1 / current,
                  param[1] + 1
                ];
        }), /* tuple */[
        0,
        0
      ], x);
  return match[1] / match[0];
}

function sample_skewness(x) {
  var mean_value = mean(x);
  var match = List.fold_left((function (param, current) {
          var deviation = current - mean_value;
          return /* tuple */[
                  param[0] + deviation * deviation,
                  param[1] + deviation * deviation * deviation,
                  param[2] + 1
                ];
        }), /* tuple */[
        0,
        0,
        0
      ], x);
  var length = match[2];
  var bessels_correction = length - 1;
  var theSampleStandardDeviation = Math.sqrt(match[0] / bessels_correction);
  var cubedS = Math.pow(theSampleStandardDeviation, 3);
  return length * match[1] / ((length - 1) * (length - 2) * cubedS);
}

function sample_variance(x) {
  var sumSquaredDeviationsValue = sum_nth_power_deviations(x, 2);
  var besselsCorrection = List.length(x) - 1;
  return sumSquaredDeviationsValue / besselsCorrection;
}

function standard_deviation(x) {
  return Math.sqrt(sample_variance(x));
}

exports.max                      = max;
exports.min                      = min;
exports.product                  = product;
exports.sum                      = sum;
exports.sum_simple               = sum_simple;
exports.mean                     = mean;
exports.mean_fold                = mean_fold;
exports.sort                     = sort;
exports.quantile_sorted          = quantile_sorted;
exports.quantile                 = quantile;
exports.interquartile_range      = interquartile_range;
exports.median                   = median;
exports.root_mean_square         = root_mean_square;
exports.min_sorted               = min_sorted;
exports.sum_nth_power_deviations = sum_nth_power_deviations;
exports.variance                 = variance;
exports.geometric_mean           = geometric_mean;
exports.mode_sorted              = mode_sorted;
exports.mode                     = mode;
exports.harmonic_mean            = harmonic_mean;
exports.sample_skewness          = sample_skewness;
exports.sample_variance          = sample_variance;
exports.standard_deviation       = standard_deviation;
/* No side effect */
