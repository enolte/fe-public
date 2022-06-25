
# Vertices of the m-cube

Subcase for *k* = simplex dimension = *m*

## Contents

- [Parameters](#parameters)
- [Summary results](#summary-results)
  - [*Simple* strategy](#simple-strategy)
  - [*Proximity* strategy](#proximity-strategy)
- [Timing changes](#timing-changes)
  - [*Simple* strategy](#simple-strategy-timings)
  - [*Proximity* strategy](#proximity-strategy-timings)

## Parameters

### Inputs

* *n* = embedding dimension = 5, 6, 7, 9, 10, 11, 14, 17, 23, ..., as listed below
* *m* = cube spanning dimension = 5, 6, 7, 9, 11, 12, 13, 14, ..., as listed below
* *k* = simplex dimension = *m*
* *strategy* : one of *simple* or *proximity*


### Internal

* *num points* = number of data points = 2<sup>*m*</sup> for the *m*-cube
* Subsets
  * ...in data set : 2<sup>2<sup>*m*</sup></sup>
  * ...in search space : C(2<sup>*m*</sup>, *m*) (binomial coefficient)
* *simplex dim* = dimension of each simplex constructed
* *embedding dim* = the dimension of the linear space in which the mesh representation is embedded

### Outputs

* *num simplices* = number of simplices in the constructed mesh
  * For *proximity* strategy, *num simplices* = 2<sup>*m*-1</sup>
  * For *simple* strategy, *num simplices* = 2<sup>*m*</sup> - *m*
* *construction time* = mesh construction time for the given parameters
  * measured in nanoseconds, shown in seconds below
  * This includes logging time
  * This does not include verification time
* *max systems / point* = the max number of systems solved to adjoin a single point
  * For *proximity* strategy, this value's distribution across the point cloud is *m*+1, constant.
  * For *simple* strategy, it is bimodal and asymmetric.

## Summary results

Windows 7, g++.exe (Rev2, Built by MSYS2 project) 11.2.0

* `g++ --std=c++2a -Wall -Werror -O3`

Mesh construction test results with full algorithm log outputs are in the  [`logs`](./logs) directory.

### *simple* strategy

|simplex dim|embedding dim|num points|num simplices| |construction time (s)|max systems / point
|:---------:|:-----------:|:--------:|:-----------:|-|-------------------:|:-----------------:|
| 2         |   2         |     4    |     2       | | *   0.0010001      |      3
|           |   3         |          |             | | *   0.0000000      |
|           |   7         |          |             | | *   0.0000000      |
| 3         |   3         |     8    |     5       | | *   0.0000000      |     20
|           |   8         |          |             | | *   0.0000000      |     20
|           |  24         |          |             | | *   0.0010001      |     20
| 4         |   7         |    16    |    12       | | *   0.0000000      |    126
|           |  17         |          |             | | *   0.0000000      |
|           |  35         |          |             | | *   0.0100005      |
| 5         |   7         |    32    |    27       | |     0.0400012      |   4844
|           |   8         |          |             | | *   0.0630019      |
|           |   9         |          |             | |     0.0570021      |
|           |  20         |          |             | |     0.0620036      |
|           |  40         |          |             | |     0.1100001      |
|           |  50         |          |             | |     0.1730071      |
|           |  70         |          |             | |     0.2500003      |
|           | 100         |          |             | |     0.1730071      |
|           | 300         |          |             | |     4.7400614      |
| 6         |   6         |    64    |    58       | |     6.0642135      | 910686
|           |   9         |          |             | |     6.6732388      |
|           |  10         |          |             | |     6.9142482      |
|           |  11         |          |             | |     7.2782869      |
|           |  31         |          |             | |    12.3564540      |
|           |  50         |          |             | |    18.2626668      |
|           | 131         |          |             | |    41.2275189      |

### *proximity* strategy

|simplex dim|embedding dim|num points|num simplices| |construction time (s)|max systems / point
|:---------:|:-----------:|:--------:|:-----------:|-|--------------------:|:-----------------:|
| 6         |   6         |    64    |    32       | | *         0.0080005 |      7
|           |   9         |          |             | | *         0.0020001 |
|           |  10         |          |             | | *         0.0050003 |
|           |  11         |          |             | | *         0.0080005 |
|           |  31         |          |             | |           0.0300006 |
|           |  50         |          |             | |           0.0600023 |
|           | 131         |          |             | |           0.2340078 |
| 7         |   7         |   128    |    64       | |           0.0340014 |      8
|           |  45         |          |             | |           0.2020082 |
|           |  93         |          |             | |           0.5850240 |
|           | 202         |          |             | |           3.0481079 |
| 9         |  14         |   512    |   256       | |           1.3730562 |     10
|           |  23         |          |             | |           1.7610628 |
|           |  98         |          |             | |          13.9475082 |
|           | 145         |          |             | |          29.5180757 |
|           | 200         |          |             | |          65.7254106 |
|11         |  11         |  2048    |  1024       | |          24.4848983 |     12
|           |  14         |          |             | |          28.0710248 |
|           |  35         |          |             | |          63.3333257 |
|           |  70         |          |             | |         170.9893123 |
|12         |  12         |  4096    |  2048       | |         122.1094991 |     13
|           |  17         |          |             | |         152.9596102 |
|           |  30         |          |             | |         251.7382480 |
|13         |  13         |  8192    |  4096       | |         572.5070226 |     14
|           |  16         |          |             | |         679.6979798 |
|14         |  14         | 16384    |  8192       | |        2887.5150570 |     15



## Timing changes

Timings are measured in nanoseconds and displayed in seconds. Blank cells in timing columns indicate no data.

Timings are listed in chronological order left to right, most recent = leftmost.

### *simple* strategy timings

|simplex dim|embedding dim|current|05 Dec 2021     |10 August 2021|~Jan 2021 |
|:---------:|:-----------:|------:|---------------:|-------------:|---------:|
| 2         |   2         |       | *    0.0010001 | *  0.0000000 | *  0.050 |
|           |   3         |       | *    0.0000000 | *  0.0000000 | *  0.042 |
|           |   7         |       | *    0.0000000 |              |          |
| 3         |   3         |       | *    0.0000000 | *  0.0010000 | *  0.052 |
|           |   8         |       | *    0.0000000 |              |          |
|           |  24         |       | *    0.0010001 | *  0.0010000 | *  0.052 |
| 4         |   7         |       | *    0.0000000 |              |          |
|           |  17         |       | *    0.0000000 |              |          |
|           |  35         |       | *    0.0100005 |              |          |
| 5         |   7         |       |      0.0400012 |              |          |
|           |   8         |       | *    0.0630019 |              |          |
|           |   9         |       |      0.0570021 |    0.0840048 |    0.315 |
|           |  20         |       |      0.0620036 |              |          |
|           |  40         |       |      0.1100001 |              |          |
|           |  50         |       |      0.1730071 |              |          |
|           |  70         |       |      0.2500003 |              |          |
|           | 100         |       |      0.1730071 |    0.4710269 |    2.532 |
|           | 300         |       |      4.7400614 |   10.3105897 |   63.453 |
| 6         |   6         |       |      6.0642135 |    8.0364597 |   19.964 |
|           |   9         |       |      6.6732388 |              |          |
|           |  10         |       |      6.9142482 |              |          |
|           |  11         |       |      7.2782869 |    8.9625126 |   22.230 |
|           |  31         |       |     12.3564540 |   14.3210053 |   28.070 |
|           |  50         |       |     18.2626668 |   19.8091331 |   42.580 |
|           | 131         |       |     41.2275189 |              |          |


### *proximity* strategy timings

|simplex dim|embedding dim|current|05 Dec 2021     |10 August 2021|~Jan 2021
|:---------:|:-----------:|------:|---------------:|-------------:|---------:|
| 6         |   6         |       | *    0.0080005 | *  0.0260015 | *  0.070 |
|           |   9         |       | *    0.0020001 |              |          |
|           |  10         |       | *    0.0050003 |              |          |
|           |  11         |       | *    0.0080005 | *  0.0250004 | *  0.112 |
|           |  31         |       |      0.0300006 |    0.0475007 |    0.111 |
|           |  50         |       | *    0.0600023 |              |          |
|           | 131         |       |      0.2340078 |    0.2430139 |    0.498 |
| 7         |   7         |       |      0.0340014 |    0.0712511 |    0.182 |
|           |  45         |       |      0.2020082 |    0.1940111 |    0.363 |
|           |  93         |       |      0.5850240 |    0.6100094 |    0.934 |
|           | 202         |       |      3.0481079 |    7.3044178 |    4.595 |
| 9         |  14         |       |      1.3730562 |    1.5640894 |    1.951 |
|           |  23         |       |      1.7610628 |    2.0160316 |    2.448 |
|           |  98         |       |     13.9475082 |   14.2278137 |   18.850 |
|           | 145         |       |     29.5180757 |   29.7297005 |   41.101 |
|           | 200         |       |     65.7254106 |  152.9186335 |   82.800 |
|11         |  11         |       |     24.4848983 |   30.5517474 |   35.641 |
|           |  14         |       |     28.0710248 |   34.2589595 |   37.103 |
|           |  35         |       |     63.3333257 |   71.3640818 |   75.326 |
|           |  70         |       |    170.9893123 |  169.3526864 |  203.921 |
|12         |  12         |       |    122.1094991 |  151.0918859 |  222.134 |
|           |  17         |       |    152.9596102 |  180.3243131 |  238.969 |
|           |  30         |       |    251.7382480 |  277.5564812 |  270.456 |
|13         |  13         |       |    572.5070226 |  685.4306396 |  757.612 |
|           |  16         |       |    679.6979798 |  782.5215029 |  939.730 |
|14         |  14         |       |   2887.5150570 | 3425.7124905 | 3550.577 |


