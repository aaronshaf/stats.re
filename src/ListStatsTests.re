let max_result = {
  let list = [1.2, 2.3, 3.4, 4.5];
  let result = ListStats.max(list);
  let expectation = 4.5;
  ("ListStats.max", result === expectation, expectation, result);
};

let min_result = {
  let list = [1.2, 2.3, 3.4, 4.5];
  let result = ListStats.min(list);
  let expectation = 1.2;
  ("ListStats.min", result === expectation, expectation, result);
};

let product_result = {
  let list = [1.2, 2.3, 3.4, 4.5];
  let result = ListStats.product(list);
  let expectation = 42.227999999999994;
  ("ListStats.product", result === expectation, expectation, result);
};

let sum_result = {
  let list = [1.2, 2.3, 3.4, 4.5];
  let result = ListStats.sum(list);
  let expectation = 11.4;
  ("ListStats.sum", result === expectation, expectation, result);
};

let sum_simple_result = {
  let list = [1.2, 2.3, 3.4, 4.5];
  let result = ListStats.sum_simple(list);
  let expectation = 11.4;
  ("ListStats.sum_simple", result === expectation, expectation, result);
};

let mean_result1 = {
  let list = [1.2, 2.3, 3.4, 4.5];
  let result = ListStats.mean(list);
  let expectation = 2.85;
  ("ListStats.mean", result === expectation, expectation, result);
};

let quantile_sorted_result1 = {
  let list = [0., 1., 2., 3., 4.];
  let result = list |> ListStats.quantile_sorted(0.);
  let expectation = 0.;
  (
    "ListStats.quantile_sorted (0.)",
    result === expectation,
    expectation,
    result
  );
};

let quantile_sorted_result2 = {
  let list = [0., 1., 2., 3., 4.];
  let result = list |> ListStats.quantile_sorted(0.25);
  let expectation = 1.;
  (
    "ListStats.quantile_sorted (0.25)",
    result === expectation,
    expectation,
    result
  );
};

let quantile_sorted_result3 = {
  let list = [0., 1., 2., 3., 4.];
  let result = list |> ListStats.quantile_sorted(0.5);
  let expectation = 2.;
  (
    "ListStats.quantile_sorted (0.5)",
    result === expectation,
    expectation,
    result
  );
};

let quantile_sorted_result4 = {
  let list = [0., 1., 2., 3., 4.];
  let result = list |> ListStats.quantile_sorted(0.75);
  let expectation = 3.;
  (
    "ListStats.quantile_sorted (0.75)",
    result === expectation,
    expectation,
    result
  );
};

let quantile_sorted_result5 = {
  let list = [0., 1., 2., 3., 4.];
  let result = list |> ListStats.quantile_sorted(1.);
  let expectation = 4.;
  (
    "ListStats.quantile_sorted (1.)",
    result === expectation,
    expectation,
    result
  );
};

let quantile_result = {
  let list = [3., 0., 1., 2., 4.];
  let result = list |> ListStats.quantile(0.75);
  let expectation = 3.;
  ("ListStats.quantile", result === expectation, expectation, result);
};

let interquartile_range_result = {
  let array = [0., 1., 2., 4.];
  let result = array |> ListStats.interquartile_range;
  let expectation = 2.;
  (
    "ListStats.interquartile_range",
    result === expectation,
    expectation,
    result
  );
};

let median_result = {
  let list = [0., 1., 2., 3., 4.];
  let result = ListStats.median(list);
  let expectation = 2.;
  ("ListStats.median", result === expectation, expectation, result);
};

let root_mean_square_result = {
  let list = [(-1.), 1., (-1.), 1.];
  let result = ListStats.root_mean_square(list);
  let expectation = 1.;
  ("ListStats.root_mean_square", result === expectation, expectation, result);
};

let min_sorted_result = {
  let list = [0., 1., 2., 3., 4.];
  let result = ListStats.min_sorted(list);
  let expectation = 0.;
  ("ListStats.min_sorted", result === expectation, expectation, result);
};

let variance_result = {
  let list = [1., 2., 3., 4., 5., 6.];
  let result = ListStats.variance(list);
  let expectation = 2.9166666666666665;
  ("ListStats.min_sorted", result === expectation, expectation, result);
};

let geometric_mean_result = {
  let growthRates = [1.80, 1.166666, 1.428571];
  let expectation =
    growthRates |> List.fold_left((prev, rate) => prev *. rate, 1.);
  let averageGrowth = ListStats.geometric_mean(growthRates);
  let averageGrowthRates = [averageGrowth, averageGrowth, averageGrowth];
  let result =
    averageGrowthRates |> List.fold_left((prev, rate) => prev *. rate, 1.);
  ("ListStats.geometric_mean", result === expectation, expectation, result);
};

let mode_sorted_result = {
  let list = [1., 2., 2., 3., 3., 3., 5., 6.];
  let result = ListStats.mode_sorted(list);
  let expectation = 3.;
  ("ListStats.mode_sorted", result === expectation, expectation, result);
};

let mode_result = {
  let list = [5., 5., 5., 1., 2., 2., 3., 1., 3., 3., 5., 6.];
  let result = ListStats.mode_sorted(list);
  let expectation = 5.;
  ("ListStats.mode", result === expectation, expectation, result);
};

let harmonic_mean_result = {
  let list = [2., 3.];
  let result = ListStats.harmonic_mean(list);
  /* needs more precision (2.4) */
  let expectation = 2.4000000000000004;
  ("ListStats.harmonic_mean", result === expectation, expectation, result);
};

let sample_skewness_result = {
  let list = [2., 4., 6., 3., 1.];
  let result = ListStats.sample_skewness(list);
  /* needs more precision (2.4) */
  let expectation = 0.590128656384365;
  ("ListStats.sample_skewness", result === expectation, expectation, result);
};

let sum_nth_power_deviations_result = {
  let list = [1., 3., 5.];
  let n = 2.;
  let result = ListStats.sum_nth_power_deviations(list, n);
  let expectation = 8.;
  (
    "ListStats.sum_nth_power_deviations",
    result === expectation,
    expectation,
    result
  );
};

let sample_variance_result = {
  let list = [1., 2., 3., 4., 5.];
  let result = ListStats.sample_variance(list);
  let expectation = 2.5;
  ("ListStats.sample_variance", result === expectation, expectation, result);
};

let standard_deviation_result = {
  let list = [2., 4., 4., 4., 5., 5., 7., 9.];
  let result = ListStats.standard_deviation(list);
  let expectation = 2.;
  (
    "ListStats.standard_deviation",
    result === expectation,
    expectation,
    result
  );
};

let sample_standard_deviation_result = {
  let list = [2., 4., 4., 4., 5., 5., 7., 9.];
  let result = ListStats.sample_standard_deviation(list);
  let expectation = 2.138089935299395;
  (
    "ListStats.sample_standard_deviation",
    result === expectation,
    expectation,
    result
  );
};
