Statistics module written in Reason. Inspired by [simple-statistics](https://github.com/simple-statistics/simple-statistics). Help me add more functions :-)

## Usage

```bash
yarn install stats.re
```

```javascript
// in bsconfig.json
"bs-dependencies": ["stats"]
```

```reason
let array = [|1.2, 2.3, 3.4, 4.5|];
let result = ArrayStats.mean(array); /* 2.85 */
```

The best docs are the tests. See [ArrayStatsTests.re](https://github.com/aaronshaf/stats.re/blob/master/src/ArrayStatsTests.re) and [ListStatsTests.re](https://github.com/aaronshaf/stats.re/blob/master/src/ListStatsTests.re).

### Stats

```reason
Stats.add_to_mean(mean: float, listLength: float, newValue: float) => float;
```

### ArrayStats

```reason
/* basics */
ArrayStats.min(x: array(float)) => float;
ArrayStats.max(x: array(float)) => float;
ArrayStats.sum_simple(x: array(float)) => float;
ArrayStats.mode(x: array(float)) => float;
ArrayStats.quantile(quantile: float, x: array(float)) => float;
ArrayStats.product(x: array(float)) => float;

/* sorted */
ArrayStats.sort(x: array(float)) => array(float);
ArrayStats.min_sorted(x: array(float)) => float;
ArrayStats.mode_sorted(x: array(float)) => float;
ArrayStats.quantile_sorted(quantile: float, x: array(float)) => float;

/* measures of central tendency */
ArrayStats.mean(x: array(float)) => float;
ArrayStats.median(x: array(float)) => float;
ArrayStats.root_mean_squared(x: array(float)) => float;
ArrayStats.variance(x: array(float)) => float;
ArrayStats.geometric_mean(x: array(float)) => float;
ArrayStats.harmonic_mean(x: array(float)) => float;
ArrayStats.sample_skewness(x: array(float)) => float;

/* measures of dispersion */
ArrayStats.interquartile_range(x: array(float)) => float
```

### ListStats

```reason
/* basics */
ListStats.min(x: list(float)) => float;
ListStats.max(x: list(float)) => float;
ListStats.sum_simple(x: list(float)) => float;
ListStats.mode(x: list(float)) => float;
ListStats.quantile(quantile: float, x: list(float)) => float;
ListStats.product(x: list(float)) => float;

/* sorted */
ListStats.sort(x: list(float)) => list(float);
ListStats.min_sorted(x: list(float)) => float;
ListStats.mode_sorted(x: list(float)) => float;
ListStats.quantile_sorted(quantile: float, x: list(float)) => float;

/* measures of central tendency */
ListStats.mean(x: list(float)) => float;
ListStats.median(x: list(float)) => float;
ListStats.root_mean_squared(x: list(float)) => float;
ListStats.variance(x: list(float)) => float;
ListStats.geometric_mean(x: list(float)) => float;
ListStats.harmonic_mean(x: list(float)) => float;
ListStats.sample_skewness(x: list(float)) => float;

/* measures of dispersion */
ListStats.interquartile_range(x: list(float)) => float
```

## Dev

```bash
yarn start
# open http://localhost:1234
# edit src/Stats.re
```

## Todo

* harmonicMean

See more [here](https://simplestatistics.org/docs/).

## See also

* [owl](https://github.com/ryanrhymes/owl) - "numerical library: dense and sparse matrix, linear algebra, regressions, maths and stats functions"
