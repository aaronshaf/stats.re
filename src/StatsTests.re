let add_to_mean_result = {
  let mean = 14.;
  let listLength = 5;
  let addedValue = 53.;
  let result = Stats.add_to_mean(mean, listLength, addedValue);
  let expectation = 20.5;
  ("Stats.add_to_mean", result === expectation, expectation, result);
};