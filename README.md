## Usage

```
yarn install stats.re
```

```
# in bsconfig.json
"bs-dependencies": ["stats"]
```

```reason
Stats.max(x: list(float))
Stats.min(x: list(float))
Stats.product(x: list(float))
Stats.sum_simple(x: list(float))
Stats.mean(x: list(float))
Stats.sort(x: list(float))
Stats.quantile_sorted(x: list(float), quantile: float)
```

## Dev

```
yarn start
parcel index.html
```

Inspired by [simple-statistics](https://github.com/simple-statistics/simple-statistics).
Help me add more functions :-)
