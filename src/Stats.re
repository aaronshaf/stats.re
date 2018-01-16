let add_to_mean = (mean, listLength, newValue) =>
  mean +. (newValue -. mean) /. (float_of_int(listLength) +. 1.);

module Utils = {
  /* Use Big_int? */
  let rec factorial = (x: int) =>
    if (x <= 1) {
      x;
    } else {
      x * factorial(x - 1);
    };
};
