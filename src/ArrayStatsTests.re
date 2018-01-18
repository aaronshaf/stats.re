let max_result = {
  let array = [|1.2, 2.3, 3.4, 4.5|];
  let result = ArrayStats.max(array);
  let expectation = 4.5;
  ("ArrayStats.max", result === expectation, expectation, result);
};

let min_result = {
  let array = [|1.2, 2.3, 3.4, 4.5|];
  let result = ArrayStats.min(array);
  let expectation = 1.2;
  ("ArrayStats.min", result === expectation, expectation, result);
};

let product_result = {
  let array = [|1.2, 2.3, 3.4, 4.5|];
  let result = ArrayStats.product(array);
  let expectation = 42.227999999999994;
  ("ArrayStats.product", result === expectation, expectation, result);
};

let sum_result = {
  let array = [|1.2, 2.3, 3.4, 4.5|];
  let result = ArrayStats.sum(array);
  let expectation = 11.4;
  ("ArrayStats.sum", result === expectation, expectation, result);
};

let sum_simple_result = {
  let array = [|1.2, 2.3, 3.4, 4.5|];
  let result = ArrayStats.sum_simple(array);
  let expectation = 11.4;
  ("ArrayStats.sum_simple", result === expectation, expectation, result);
};

let mean_result1 = {
  let array = [|1.2, 2.3, 3.4, 4.5|];
  let result = ArrayStats.mean(array);
  let expectation = 2.85;
  ("ArrayStats.mean", result === expectation, expectation, result);
};

let quantile_sorted_result1 = {
  let array = [|0., 1., 2., 3., 4.|];
  let result = array |> ArrayStats.quantile_sorted(0.);
  let expectation = 0.;
  (
    "ArrayStats.quantile_sorted (0.)",
    result === expectation,
    expectation,
    result
  );
};

let quantile_sorted_result2 = {
  let array = [|0., 1., 2., 3., 4.|];
  let result = array |> ArrayStats.quantile_sorted(0.25);
  let expectation = 1.;
  (
    "ArrayStats.quantile_sorted (0.25)",
    result === expectation,
    expectation,
    result
  );
};

let quantile_sorted_result3 = {
  let array = [|0., 1., 2., 3., 4.|];
  let result = array |> ArrayStats.quantile_sorted(0.5);
  let expectation = 2.;
  (
    "ArrayStats.quantile_sorted (0.5)",
    result === expectation,
    expectation,
    result
  );
};

let quantile_sorted_result4 = {
  let array = [|0., 1., 2., 3., 4.|];
  let result = array |> ArrayStats.quantile_sorted(0.75);
  let expectation = 3.;
  (
    "ArrayStats.quantile_sorted (0.75)",
    result === expectation,
    expectation,
    result
  );
};

let quantile_sorted_result5 = {
  let array = [|0., 1., 2., 3., 4.|];
  let result = array |> ArrayStats.quantile_sorted(1.);
  let expectation = 4.;
  (
    "ArrayStats.quantile_sorted (1.)",
    result === expectation,
    expectation,
    result
  );
};

let quantile_result = {
  let array = [|3., 0., 1., 2., 4.|];
  let result = array |> ArrayStats.quantile(0.75);
  let expectation = 3.;
  ("ArrayStats.quantile", result === expectation, expectation, result);
};

let interquartile_range_result = {
  let array = [|0., 1., 2., 4.|];
  let result = array |> ArrayStats.interquartile_range;
  let expectation = 2.;
  (
    "ArrayStats.interquartile_range",
    result === expectation,
    expectation,
    result
  );
};

let median_result = {
  let array = [|0., 1., 2., 3., 4.|];
  let result = ArrayStats.median(array);
  let expectation = 2.;
  ("ArrayStats.median", result === expectation, expectation, result);
};

let root_mean_square_result = {
  let array = [|(-1.), 1., (-1.), 1.|];
  let result = ArrayStats.root_mean_square(array);
  let expectation = 1.;
  ("ArrayStats.root_mean_square", result === expectation, expectation, result);
};

let min_sorted_result = {
  let array = [|0., 1., 2., 3., 4.|];
  let result = ArrayStats.min_sorted(array);
  let expectation = 0.;
  ("ArrayStats.min_sorted", result === expectation, expectation, result);
};

let variance_result = {
  let array = [|1., 2., 3., 4., 5., 6.|];
  let result = ArrayStats.variance(array);
  let expectation = 2.9166666666666665;
  ("ArrayStats.variance", result === expectation, expectation, result);
};

let geometric_mean_result = {
  let growthRates = [|1.80, 1.166666, 1.428571|];
  let expectation =
    growthRates |> Array.fold_left((prev, rate) => prev *. rate, 1.);
  let averageGrowth = ArrayStats.geometric_mean(growthRates);
  let averageGrowthRates = [|averageGrowth, averageGrowth, averageGrowth|];
  let result =
    averageGrowthRates |> Array.fold_left((prev, rate) => prev *. rate, 1.);
  ("ArrayStats.geometric_mean", result === expectation, expectation, result);
};

let mode_sorted_result = {
  let array = [|1., 2., 2., 3., 3., 3., 5., 6.|];
  let result = ArrayStats.mode_sorted(array);
  let expectation = 3.;
  ("ArrayStats.mode_sorted", result === expectation, expectation, result);
};

let mode_result = {
  let array = [|5., 5., 5., 1., 2., 2., 3., 1., 3., 3., 5., 6.|];
  let result = ArrayStats.mode_sorted(array);
  let expectation = 5.;
  ("ArrayStats.mode", result === expectation, expectation, result);
};

let harmonic_mean_result = {
  let array = [|2., 3.|];
  let result = ArrayStats.harmonic_mean(array);
  /* needs more precision (2.4) */
  let expectation = 2.4000000000000004;
  ("ArrayStats.harmonic_mean", result === expectation, expectation, result);
};

let sample_skewness_result = {
  let array = [|2., 4., 6., 3., 1.|];
  let result = ArrayStats.sample_skewness(array);
  /* needs more precision (2.4) */
  let expectation = 0.590128656384365;
  ("ArrayStats.sample_skewness", result === expectation, expectation, result);
};

let sum_nth_power_deviations_result = {
  let array = [|1., 3., 5.|];
  let n = 2.;
  let result = ArrayStats.sum_nth_power_deviations(array, n);
  let expectation = 8.;
  (
    "ArrayStats.sum_nth_power_deviations",
    result === expectation,
    expectation,
    result
  );
};
