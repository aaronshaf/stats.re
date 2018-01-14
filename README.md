Statistics module in Reason. Inspired by [simple-statistics](https://github.com/simple-statistics/simple-statistics). Help me add more functions :-)

## Usage

```bash
yarn install stats.re
```

```javascript
// in bsconfig.json
"bs-dependencies": ["stats"]
```

```reason
/* basics */
list(float) |> Stats.min;
list(float) |> Stats.max;
list(float) |> Stats.sum_simple;
list(float) |> Stats.quantile(quantile: float)
list(float) |> Stats.product;

/* sorted */
list(float) |> Stats.sort;
list(float) |> Stats.min_sorted;
list(float) |> Stats.quantile_sorted(quantile: float);

/* measures of central tendency */
list(float) |> Stats.mean;
list(float) |> Stats.median;
list(float) |> Stats.root_mean_squared;
```

## Dev

```bash
yarn start
# open http://localhost:1234
# edit src/Stats.re
```
