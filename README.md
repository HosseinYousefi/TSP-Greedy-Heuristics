# TSP Greedy Heuristics

| algorithm/test                                              | 5 | 51      | 100     | 400     | 9432    | 85900       |
|-------------------------------------------------------------|---|---------|---------|---------|---------|-------------|
| tsp lowerbound (MST - Prim)                                 | 3 | 376.491 | 6963.27 | 13631.7 | 53178   | 1.39675e+08 |
| tsp nearest neighbor starting from 0                        | 4 | 506.363 | 10235.4 | 19196   | 66999.4 | 1.63796e+08 |
| tsp nearest neighbor starting from random, best of several  | 4 | 490.398 | 9766.2  | 18154   | 66169   | 1.63505e+08 |
| tsp nearest insertion starting from 0                       | 4 | 483.445 | 9250.9  | 18630   | 59133.5 |             |
| tsp nearest insertion starting from random, best of several | 4 | 474.003 | 8892.47 | 17795.5 | 59062.4 |             |
| tsp greedy multi-fragment                                   | 4 | 481.519 | 9254.01 | 17894.4 | 62883.4 |             |

1. Yes, it does depend heavily on the starting vertex.
2. Nearest Insertion (random start, several runs) does best.
3. They produce a better result than the worst case expected.
