## Usage

```bash
yarn install stats.re
```

```javascript
// in bsconfig.json
"bs-dependencies": ["stats"]
```

```reason
Stats.max(x: list(float));
Stats.min(x: list(float));
Stats.min_sorted(x: list(float));
Stats.product(x: list(float));
Stats.sum_simple(x: list(float));
Stats.mean(x: list(float));
Stats.median(x: list(float));
Stats.quantile(x: list(float), quantile: float)
Stats.quantile_sorted(x: list(float), quantile: float);
Stats.root_mean_squared(x: list(float));
Stats.sort(x: list(float));
```

## Dev

```bash
yarn start
# open http://localhost:1234
# edit src/Stats.re
```

Inspired by [simple-statistics](https://github.com/simple-statistics/simple-statistics).
Help me add more functions :-)
