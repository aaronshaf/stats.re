let max = (x: list(float)) =>
  ListLabels.fold_left(~f=(a, b) => max(a, b), ~init=List.hd(x), x);

let min = (x: list(float)) =>
  ListLabels.fold_left(~f=(a, b) => min(a, b), ~init=List.hd(x), x);

let product = (x: list(float)) =>
  ListLabels.fold_left(~f=(a, b) => a *. b, ~init=1., x);

let sum_simple = (x: list(float)) =>
  ListLabels.fold_left(~f=(a, b) => a +. b, ~init=0., x);

let mean = (x: list(float)) => {
  let (mean, _length) =
    List.fold_left(
      ((previousMean, previousLength), valueToAdd) => (
        Stats.Utils.add_to_mean(previousMean, previousLength, valueToAdd),
        previousLength +. 1.
      ),
      (0., 0.),
      x
    );
  mean;
};

/*
 for each:
   x |> List.fold_left((prev, current) => , (0, 0) /* mean, length */,
   add_to_mean(mean, listLength, newValue)
 */
let sort = (x: list(float)) =>
  ListLabels.fast_sort(
    ~cmp=
      (a, b) =>
        if (a > b) {
          1;
        } else if (a < b) {
          (-1);
        } else {
          0;
        },
    x
  );

/* probably did unnecessary float <-> int stuff. needs review. */
let quantile_sorted = (quantile: float, x: list(float)) => {
  let length = List.length(x);
  let is_quantile_integer = float_of_int(int_of_float(quantile)) === quantile;
  let index = float_of_int(length) *. quantile;
  if (quantile === 1.) {
    List.nth(x, length - 1);
  } else if (quantile === 0.) {
    List.hd(x);
  } else if (is_quantile_integer === false) {
    List.nth(x, int_of_float(ceil(index) -. 1.));
  } else if (length mod 2 === 0) {
    (List.nth(x, int_of_float(index) - 1) +. List.nth(x, int_of_float(index)))
    /. 2.;
  } else {
    List.nth(x, int_of_float(index));
  };
};

let quantile = (quantile: float, x: list(float)) => {
  let sorted_list = sort(x);
  quantile_sorted(quantile, sorted_list);
};

let interquartile_range = (x: list(float)) =>
  quantile(0.75, x) -. quantile(0.25, x);

let median = (x: list(float)) => quantile(0.5, x);

let root_mean_square = (x: list(float)) => {
  let sumOfSquares =
    ListLabels.fold_left(~f=(prev, b) => prev +. b ** 2., ~init=0., x);
  sumOfSquares /. float_of_int(List.length(x)) |> sqrt;
};

let min_sorted = (x: list(float)) => List.hd(x);

let sum_nth_power_deviations = (x: list(float), n: float) => {
  let meanValue = mean(x);
  List.fold_left(
    (prev, current) => prev +. (current -. meanValue) ** n,
    0.,
    x
  );
};

let variance = (x: list(float)) =>
  sum_nth_power_deviations(x, 2.) /. float_of_int(List.length(x));

let geometric_mean = (growthRates: list(float)) => {
  let (growthRate, length) =
    growthRates
    |> List.fold_left(
         ((growthRate, length), current) => (
           growthRate *. current,
           length +. 1.
         ),
         (1., 0.)
       );
  growthRate ** (1. /. length);
};
