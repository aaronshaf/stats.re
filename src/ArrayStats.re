let max = (x: array(float)) =>
  ArrayLabels.fold_left(~f=(a, b) => max(a, b), ~init=x[0], x);

let min = (x: array(float)) =>
  ArrayLabels.fold_left(~f=(a, b) => min(a, b), ~init=x[0], x);

let product = (x: array(float)) =>
  ArrayLabels.fold_left(~f=(a, b) => a *. b, ~init=1., x);

let sum = (x: array(float)) => {
  let (sum, _correction) = {
    let initial = (x[0], 0.);
    Array.fold_left(
      ((sum, correction), current) => {
        let newSum = sum +. current;
        if (abs_float(sum) >= abs_float(current)) {
          let newCorrection = correction +. (sum -. newSum +. current);
          (newSum, newCorrection);
        } else {
          let newCorrection = correction +. (current -. newSum +. sum);
          (newSum, newCorrection);
        };
      },
      initial,
      Array.sub(x, 1, Array.length(x) - 1)
    );
  };
  sum;
};

let sum_simple = (x: array(float)) =>
  ArrayLabels.fold_left(~f=(a, b) => a +. b, ~init=0., x);

let mean = (x: array(float)) => sum(x) /. float_of_int(Array.length(x));

let mean_fold = (x: array(float)) => {
  let (mean, _length) =
    Array.fold_left(
      ((previousMean, previousLength), valueToAdd) => (
        Stats.Utils.add_to_mean(previousMean, previousLength, valueToAdd),
        previousLength +. 1.
      ),
      (0., 0.),
      x
    );
  mean;
};

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

let interquartile_range = (x: array(float)) =>
  quantile(0.75, x) -. quantile(0.25, x);

let median = (x: array(float)) => quantile(0.5, x);

let root_mean_square = (x: array(float)) => {
  let sumOfSquares =
    ArrayLabels.fold_left(~f=(prev, b) => prev +. b ** 2., ~init=0., x);
  sumOfSquares /. float_of_int(Array.length(x)) |> sqrt;
};

let min_sorted = (x: array(float)) => x[0];

let sum_nth_power_deviations = (x: array(float), n: float) => {
  let meanValue = mean(x);
  Array.fold_left((sum, current) => sum +. (current -. meanValue) ** n, 0., x);
};

let variance = (x: array(float)) =>
  sum_nth_power_deviations(x, 2.) /. float_of_int(Array.length(x));

let geometric_mean = (growthRates: array(float)) => {
  let (growthRate, length) =
    growthRates
    |> Array.fold_left(
         ((growthRate, length), current) => (
           growthRate *. current,
           length +. 1.
         ),
         (1., 0.)
       );
  growthRate ** (1. /. length);
};

let mode_sorted = (x: array(float)) => {
  let (defender, _defenderScore, _contender, _contenderScore) =
    Array.fold_left(
      ((defender, defenderScore, contender, contenderScore), current) =>
        if (contender === current) {
          if (contenderScore >= defenderScore) {
            (
              /* new winner */
              contender,
              contenderScore + 1,
              contender,
              contenderScore + 1
            );
          } else {
            (
              /* defender reigns */
              defender,
              defenderScore,
              contender,
              contenderScore + 1
            );
          };
        } else {
          (
            /* new contender */
            defender,
            defenderScore,
            current,
            1
          );
        },
      (x[0], 1, x[0], 1),
      Array.sub(x, 1, Array.length(x) - 1)
    );
  defender;
};

let mode = (x: array(float)) => sort(x) |> mode_sorted;

let harmonic_mean = (x: array(float)) => {
  let (reciprocal_sum, length) =
    Array.fold_left(
      ((reciprocal_sum, length), current) => (
        reciprocal_sum +. 1. /. current,
        length +. 1.
      ),
      (0., 0.),
      x
    );
  length /. reciprocal_sum;
};

let sample_skewness = (x: array(float)) => {
  let mean_value = mean(x);
  let (sum_squared_deviations, sum_cubed_deviations, length) =
    x
    |> Array.fold_left(
         ((sum_squared_deviations, sum_cubed_deviations, length), current) => {
           let deviation = current -. mean_value;
           (
             sum_squared_deviations +. deviation *. deviation,
             sum_cubed_deviations +. deviation *. deviation *. deviation,
             length +. 1.
           );
         },
         (0., 0., 0.)
       );
  let bessels_correction = length -. 1.;
  let theSampleStandardDeviation =
    sqrt(sum_squared_deviations /. bessels_correction);
  let cubedS = theSampleStandardDeviation ** 3.;
  length
  *. sum_cubed_deviations
  /. ((length -. 1.) *. (length -. 2.) *. cubedS);
};

let sample_variance = (x: array(float)) => {
  let sumSquaredDeviationsValue = sum_nth_power_deviations(x, 2.);
  let besselsCorrection = float_of_int(Array.length(x)) -. 1.;
  sumSquaredDeviationsValue /. besselsCorrection;
};

let standard_deviation = (x: array(float)) => sample_variance(x) |> sqrt;
