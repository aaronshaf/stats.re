let max = (x: list(float)) =>
  ListLabels.fold_left(~f=(a, b) => max(a, b), ~init=List.hd(x), x);

let min = (x: list(float)) =>
  ListLabels.fold_left(~f=(a, b) => min(a, b), ~init=List.hd(x), x);

let product = (x: list(float)) =>
  ListLabels.fold_left(~f=(a, b) => a *. b, ~init=1., x);

let sum_simple = (x: list(float)) =>
  ListLabels.fold_left(~f=(a, b) => a +. b, ~init=0., x);

let mean = (x: list(float)) => sum_simple(x) /. float_of_int(List.length(x));

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
let quantile_sorted = (x: list(float), quantile: float) => {
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
