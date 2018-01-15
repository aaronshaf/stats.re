Statistics module written in Reason. Inspired by [simple-statistics](https://github.com/simple-statistics/simple-statistics). Help me add more functions :-)

## Usage

```bash
yarn install stats.re
```

```javascript
// in bsconfig.json
"bs-dependencies": ["stats"]
```

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
ArrayStats.quantile(quantile: float, x: array(float)) => float;
ArrayStats.product(x: array(float)) => float;

/* sorted */
ArrayStats.sort(x: array(float)) => array(float);
ArrayStats.min_sorted(x: array(float)) => float;
ArrayStats.quantile_sorted(quantile: float, x: array(float)) => float;

/* measures of central tendency */
ArrayStats.mean(x: array(float)) => float;
ArrayStats.median(x: array(float)) => float;
ArrayStats.root_mean_squared(x: array(float)) => float;
```

### ListStats

```reason
/* basics */
ListStats.min(x: array(float)) => float;
ListStats.max(x: array(float)) => float;
ListStats.sum_simple(x: array(float)) => float;
ListStats.quantile(quantile: float, x: array(float)) => float;
ListStats.product(x: array(float)) => float;

/* sorted */
ListStats.sort(x: list(float)) => array(float);
ListStats.min_sorted(x: list(float)) => float;
ListStats.quantile_sorted(quantile: float, x: list(float)) => float;

/* measures of central tendency */
ListStats.mean(x: list(float)) => float;
ListStats.median(x: list(float)) => float;
ListStats.root_mean_squared(x: list(float)) => float;
```

## Dev

```bash
yarn start
# open http://localhost:1234
# edit src/Stats.re
```

## See also

* [owl](https://github.com/ryanrhymes/owl) - "numerical library: dense and sparse matrix, linear algebra, regressions, maths and stats functions"
