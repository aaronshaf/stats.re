// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';


function add_to_mean(mean, listLength, newValue) {
  return mean + (newValue - mean) / (listLength + 1);
}

exports.add_to_mean = add_to_mean;
/* No side effect */
