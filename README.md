# TSP Greedy Heuristics

| algorithm/test                                                   | 5 | 51      | 100     | 400     | 9432    | 85900       |
|------------------------------------------------------------------|---|---------|---------|---------|---------|-------------|
| tsp lowerbound (MST)                                             | 3 | 376.491 | 6963.27 | 13631.7 | 53178   | -           |
| tsp nearest neighbor starting from 0                             | 4 | 506.363 | 10235.4 | 19196   | 66999.4 | 1.63796e+08 |
| tsp nearest neighbor starting from random, best of several tries | 4 | 490.398 | 9766.2  | 18154   | 66169   | -           |
| tsp greedy multi-fragment                                        | 4 | 481.519 | 9254.01 | 17894.4 | 62883.4 | -           |

1. Yes, it does depend heavily on the starting vertex.
2. Greedy multi-fragmenting does the best so far.
3. They produce a better result than the worst case expected.
