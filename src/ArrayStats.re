let max = (x: array(float)) =>
  ArrayLabels.fold_left(~f=(a, b) => max(a, b), ~init=x[0], x);

let min = (x: array(float)) =>
  ArrayLabels.fold_left(~f=(a, b) => min(a, b), ~init=x[0], x);

let product = (x: array(float)) =>
  ArrayLabels.fold_left(~f=(a, b) => a *. b, ~init=1., x);

let sum_simple = (x: array(float)) =>
  ArrayLabels.fold_left(~f=(a, b) => a +. b, ~init=0., x);

/* TODO: refactor with Lost.fold_left */
let mean = (x: array(float)) => sum_simple(x) /. float_of_int(Array.length(x));

let sort = (x: array(float)) => {
  let clonedArray = ArrayLabels.copy(x);
  ArrayLabels.fast_sort(
    ~cmp=
      (a, b) =>
        if (a > b) {
          1;
        } else if (a < b) {
          (-1);
        } else {
          0;
        },
    clonedArray
  );
  clonedArray;
};

/* probably did unnecessary float <-> int stuff. needs review. */
let quantile_sorted = (quantile: float, x: array(float)) => {
  let length = Array.length(x);
  let is_quantile_integer = float_of_int(int_of_float(quantile)) === quantile;
  let index = float_of_int(length) *. quantile;
  if (quantile === 1.) {
    x[length - 1];
  } else if (quantile === 0.) {
    x[0];
  } else if (is_quantile_integer === false) {
    x[int_of_float(ceil(index) -. 1.)];
  } else if (length mod 2 === 0) {
    (x[int_of_float(index) - 1] +. x[int_of_float(index)]) /. 2.;
  } else {
    x[int_of_float(index)];
  };
};

let quantile = (quantile: float, x: array(float)) => {
  let sorted_array = sort(x);
  quantile_sorted(quantile, sorted_array);
};

let median = (x: array(float)) => quantile(0.5, x);

let root_mean_square = (x: array(float)) => {
  let sumOfSquares =
    ArrayLabels.fold_left(~f=(prev, b) => prev +. b ** 2., ~init=0., x);
  sumOfSquares /. float_of_int(Array.length(x)) |> sqrt;
};

let min_sorted = (x: array(float)) => x[0];
