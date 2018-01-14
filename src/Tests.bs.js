// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var Stats = require("./Stats.bs.js");

var result = Stats.max(/* :: */[
      1.2,
      /* :: */[
        2.3,
        /* :: */[
          3.4,
          /* :: */[
            4.5,
            /* [] */0
          ]
        ]
      ]
    ]);

var max_result_001 = +(result === 4.5);

var max_result = /* tuple */[
  "Stats.max",
  max_result_001,
  4.5,
  result
];

var result$1 = Stats.product(/* :: */[
      1.2,
      /* :: */[
        2.3,
        /* :: */[
          3.4,
          /* :: */[
            4.5,
            /* [] */0
          ]
        ]
      ]
    ]);

var product_result_001 = +(result$1 === 42.227999999999994);

var product_result = /* tuple */[
  "Stats.product",
  product_result_001,
  42.227999999999994,
  result$1
];

var result$2 = Stats.sum_simple(/* :: */[
      1.2,
      /* :: */[
        2.3,
        /* :: */[
          3.4,
          /* :: */[
            4.5,
            /* [] */0
          ]
        ]
      ]
    ]);

var sum_simple_result_001 = +(result$2 === 11.4);

var sum_simple_result = /* tuple */[
  "Stats.sum_simple",
  sum_simple_result_001,
  11.4,
  result$2
];

var result$3 = Stats.mean(/* :: */[
      1.2,
      /* :: */[
        2.3,
        /* :: */[
          3.4,
          /* :: */[
            4.5,
            /* [] */0
          ]
        ]
      ]
    ]);

var mean_result1_001 = +(result$3 === 2.85);

var mean_result1 = /* tuple */[
  "Stats.mean",
  mean_result1_001,
  2.85,
  result$3
];

var result$4 = Stats.quantile_sorted(/* :: */[
      0,
      /* :: */[
        1,
        /* :: */[
          2,
          /* :: */[
            3,
            /* :: */[
              4,
              /* [] */0
            ]
          ]
        ]
      ]
    ], 0);

var quantile_sorted_result1_001 = +(result$4 === 0);

var quantile_sorted_result1 = /* tuple */[
  "Stats.quantile_sorted (0.)",
  quantile_sorted_result1_001,
  0,
  result$4
];

var result$5 = Stats.quantile_sorted(/* :: */[
      0,
      /* :: */[
        1,
        /* :: */[
          2,
          /* :: */[
            3,
            /* :: */[
              4,
              /* [] */0
            ]
          ]
        ]
      ]
    ], 0.25);

var quantile_sorted_result2_001 = +(result$5 === 1);

var quantile_sorted_result2 = /* tuple */[
  "Stats.quantile_sorted (0.25)",
  quantile_sorted_result2_001,
  1,
  result$5
];

var result$6 = Stats.quantile_sorted(/* :: */[
      0,
      /* :: */[
        1,
        /* :: */[
          2,
          /* :: */[
            3,
            /* :: */[
              4,
              /* [] */0
            ]
          ]
        ]
      ]
    ], 0.5);

var quantile_sorted_result3_001 = +(result$6 === 2);

var quantile_sorted_result3 = /* tuple */[
  "Stats.quantile_sorted (0.5)",
  quantile_sorted_result3_001,
  2,
  result$6
];

var result$7 = Stats.quantile_sorted(/* :: */[
      0,
      /* :: */[
        1,
        /* :: */[
          2,
          /* :: */[
            3,
            /* :: */[
              4,
              /* [] */0
            ]
          ]
        ]
      ]
    ], 0.75);

var quantile_sorted_result4_001 = +(result$7 === 3);

var quantile_sorted_result4 = /* tuple */[
  "Stats.quantile_sorted (0.75)",
  quantile_sorted_result4_001,
  3,
  result$7
];

var result$8 = Stats.quantile_sorted(/* :: */[
      0,
      /* :: */[
        1,
        /* :: */[
          2,
          /* :: */[
            3,
            /* :: */[
              4,
              /* [] */0
            ]
          ]
        ]
      ]
    ], 1);

var quantile_sorted_result5_001 = +(result$8 === 4);

var quantile_sorted_result5 = /* tuple */[
  "Stats.quantile_sorted (1.)",
  quantile_sorted_result5_001,
  4,
  result$8
];

var result$9 = Stats.root_mean_squared(/* :: */[
      -1,
      /* :: */[
        1,
        /* :: */[
          -1,
          /* :: */[
            1,
            /* [] */0
          ]
        ]
      ]
    ]);

var root_mean_squared_result_001 = +(result$9 === 1);

var root_mean_squared_result = /* tuple */[
  "Stats.root_mean_squared",
  root_mean_squared_result_001,
  1,
  result$9
];

exports.max_result               = max_result;
exports.product_result           = product_result;
exports.sum_simple_result        = sum_simple_result;
exports.mean_result1             = mean_result1;
exports.quantile_sorted_result1  = quantile_sorted_result1;
exports.quantile_sorted_result2  = quantile_sorted_result2;
exports.quantile_sorted_result3  = quantile_sorted_result3;
exports.quantile_sorted_result4  = quantile_sorted_result4;
exports.quantile_sorted_result5  = quantile_sorted_result5;
exports.root_mean_squared_result = root_mean_squared_result;
/* result Not a pure module */
