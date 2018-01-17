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
