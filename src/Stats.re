module Utils = {
  let add_to_mean = (mean, listLength, newValue) =>
    mean +. (newValue -. mean) /. (listLength +. 1.);
  /*
   Use Big_int? */
  let rec factorial = (x: int) =>
    if (x <= 1) {
      x;
    } else {
      x * factorial(x - 1);
    };
};
