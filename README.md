## Usage

```bash
yarn install stats.re
```

```javascript
// in bsconfig.json
"bs-dependencies": ["stats"]
```

```reason
list(float) |> Stats.max;
list(float) |> Stats.min;
list(float) |> Stats.min_sorted;
list(float) |> Stats.product;
list(float) |> Stats.sum_simple;
list(float) |> Stats.mean;
list(float) |> Stats.median;
list(float) |> Stats.quantile(quantile: float)
list(float) |> Stats.quantile_sorted(quantile: float);
list(float) |> Stats.root_mean_squared;
list(float) |> Stats.sort;
```

## Dev

```bash
yarn start
# open http://localhost:1234
# edit src/Stats.re
```

Inspired by [simple-statistics](https://github.com/simple-statistics/simple-statistics).
Help me add more functions :-)
