let add_to_mean = (mean, listLength, newValue) =>
  mean +. (newValue -. mean) /. (float_of_int(listLength) +. 1.);
