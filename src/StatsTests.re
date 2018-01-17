let add_to_mean_result = {
  let mean = 14.;
  let listLength = 5.;
  let addedValue = 53.;
  let result = Stats.Utils.add_to_mean(mean, listLength, addedValue);
  let expectation = 20.5;
  ("Stats.add_to_mean", result === expectation, expectation, result);
};

let factorial_result = {
  let result = Stats.Utils.factorial(13);
  let expectation = 1932053504;
  ("Stats.Utils.factorial", result === expectation, expectation, result);
};
