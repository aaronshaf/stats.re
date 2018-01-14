let max_result = {
  let list = [1.2, 2.3, 3.4, 4.5];
  let result = Stats.max(list);
  let expectation = 4.5;
  ("Stats.max", result === expectation, expectation, result);
};

let product_result = {
  let list = [1.2, 2.3, 3.4, 4.5];
  let result = Stats.product(list);
  let expectation = 42.227999999999994;
  ("Stats.product", result === expectation, expectation, result);
};

let sum_simple_result = {
  let list = [1.2, 2.3, 3.4, 4.5];
  let result = Stats.sum_simple(list);
  let expectation = 11.4;
  ("Stats.sum_simple", result === expectation, expectation, result);
};

let mean_result1 = {
  let list = [1.2, 2.3, 3.4, 4.5];
  let result = Stats.mean(list);
  let expectation = 2.85;
  ("Stats.mean", result === expectation, expectation, result);
};

let quantile_sorted_result1 = {
  let list = [0., 1., 2., 3., 4.];
  let result = Stats.quantile_sorted(list, 0.);
  let expectation = 0.;
  ("Stats.quantile_sorted (0.)", result === expectation, expectation, result);
};

let quantile_sorted_result2 = {
  let list = [0., 1., 2., 3., 4.];
  let result = Stats.quantile_sorted(list, 0.25);
  let expectation = 1.;
  (
    "Stats.quantile_sorted (0.25)",
    result === expectation,
    expectation,
    result
  );
};

let quantile_sorted_result3 = {
  let list = [0., 1., 2., 3., 4.];
  let result = Stats.quantile_sorted(list, 0.5);
  let expectation = 2.;
  ("Stats.quantile_sorted (0.5)", result === expectation, expectation, result);
};

let quantile_sorted_result4 = {
  let list = [0., 1., 2., 3., 4.];
  let result = Stats.quantile_sorted(list, 0.75);
  let expectation = 3.;
  (
    "Stats.quantile_sorted (0.75)",
    result === expectation,
    expectation,
    result
  );
};

let quantile_sorted_result5 = {
  let list = [0., 1., 2., 3., 4.];
  let result = Stats.quantile_sorted(list, 1.);
  let expectation = 4.;
  ("Stats.quantile_sorted (1.)", result === expectation, expectation, result);
};

let root_mean_squared_result = {
  let list = [(-1.), 1., (-1.), 1.];
  let result = Stats.root_mean_squared(list);
  let expectation = 1.;
  ("Stats.root_mean_squared", result === expectation, expectation, result);
};

let min_sorted = {
  let list = [0., 1., 2., 3., 4.];
  let result = Stats.min_sorted(list);
  let expectation = 0.;
  ("Stats.min_sorted", result === expectation, expectation, result);
};
