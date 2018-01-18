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

### ArrayStats (mirrors ListStats)

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

### Utils

```reason
Stats.Utils.add_to_mean(mean: float, listLength: float, newValue: float) => float;
```

## Dev

```bash
yarn start
# open http://localhost:1234
# edit src/Stats.re
```

See more [here](https://simplestatistics.org/docs/).

## See also

* [owl](https://github.com/ryanrhymes/owl) - "numerical library: dense and sparse matrix, linear algebra, regressions, maths and stats functions"
