# Basis polynomials of the m-cube (*pending*)

Basis induction tests. Subcase for *k* = simplex dimension = *m*

## Contents

- [Parameters](#parameters)
- [Summary results](#summary-results)
- [Timing changes](#timing-changes)

## Parameters

### Inputs

* simplex mesh consisting of *k*-simplices embedded in an *n*-dimensional Euclidean space
* *degree* = max degree of any basis component polynomial

### Internal

* *num simplex knots* = num knot points per simplex

### Outputs

* *num polys* = number of polynomial functions constructed for the entire mesh
* *num splines* = number of basis functions constructed for the entire mesh
* *construction time* = basis construction time for the given parameters
  * measured in nanoseconds, shown in seconds below
  * This includes logging time
  * This does not include verification time

## Summary results

Windows 7, g++.exe (Rev2, Built by MSYS2 project) 11.2.0

* `g++ --std=c++23 -Wall -Werror -O3`

Mesh construction test results with full algorithm log outputs are in the  [`logs`](./logs) directory. An arrow (↓) indicates
a construction time value which is greater than the value below, where it is unexpected.

### *C<sup>0</sup> isometric*

|simplex dim|embedding dim|num simplices|degree| |num polys|num splines|construction time (s)|
|:---------:|:-----------:|:-----------:|:----:|-|:-------:|:---------:|:-------------------:|
| 2         |   2         |     4       |    1 | |         |           |                     |
|           |             |             |    2 | |         |           |                     |
|           |             |             |    3 | |         |           |                     |
|           |             |             |    4 | |         |           |                     |
|           |             |             |    5 | |         |           |                     |
|           |   3         |             |    1 | |         |           |                     |
|           |             |             |    2 | |         |           |                     |
|           |             |             |    3 | |         |           |                     |
|           |             |             |    4 | |         |           |                     |
|           |             |             |    6 | |         |           |                     |
|           |   7         |             |    2 | |         |           |                     |
|           |             |             |    4 | |         |           |                     |
|           |             |             |    6 | |         |           |                     |
|           |             |             |    7 | |         |           |                     |
|           |             |             |    8 | |         |           |                     |
| 3         |   3         |     8       |    2 | |         |           |                     |
|           |             |             |    3 | |         |           |                     |
|           |             |             |    5 | |         |           |                     |
|           |             |             |    7 | |         |           |                     |
|           |   8         |             |    2 | |         |           |                     |
|           |             |             |    3 | |         |           |                     |
|           |             |             |    5 | |         |           |                     |
|           |             |             |    7 | |         |           |                     |
|           |  24         |             |    2 | |         |           |                     |
|           |             |             |    3 | |         |           |                     |
|           |             |             |    5 | |         |           |                     |
|           |             |             |    7 | |         |           |                     |
|           |             |             |    7 | |         |           |                     |
| 4         |   7         |    16       |    2 | |         |           |                     |
|           |             |             |    3 | |         |           |                     |
|           |             |             |    5 | |         |           |                     |
|           |             |             |    7 | |         |           |                     |
|           |             |             |    8 | |         |           |                     |
|           |  17         |             |    2 | |         |           |                     |
|           |             |             |    3 | |         |           |                     |
|           |             |             |    5 | |         |           |                     |
|           |             |             |    7 | |         |           |                     |
|           |  35         |             |    2 | |         |           |                     |
|           |             |             |    3 | |         |           |                     |
|           |             |             |    5 | |         |           |                     |
|           |             |             |    7 | |         |           |                     |
| 5         |   7         |    32       |    1 | |         |           |                     |
|           |             |             |    2 | |         |           |                     |
|           |             |             |    3 | |         |           |                     |
|           |  20         |             |    1 | |         |           |                     |
|           |             |             |    2 | |         |           |                     |
|           |             |             |    3 | |         |           |                     |
| 6         |   6         |    32       |    1 | |         |           |                     |
|           |             |             |    2 | |         |           |                     |
|           |             |             |    3 | |         |           |                     |
|           |             |             |    4 | |         |           |                     |
|           |             |             |    6 | |         |           |                     |
|           |  11         |             |    1 | |         |           |                     |
|           |             |             |    2 | |         |           |                     |
|           |             |             |    3 | |         |           |                     |
|           |             |             |    5 | |         |           |                     |

## Timing changes

Timings are measured in nanoseconds and displayed in seconds. Blank cells in timing columns indicate no data.

Timings are listed in chronological order left to right, most recent = leftmost. An arrow (→) denotes an increase
over the previous timing value for that test case.

### *C<sup>0</sup> isometric*

|simplex dim|embedding dim|num simplices|degree| |current (s)          |
|:---------:|:-----------:|:-----------:|:----:|-|--------------------:|
| 2         |   2         |     4       |    1 | |                     |
|           |             |             |    2 | |                     |
|           |             |             |    3 | |                     |
|           |             |             |    4 | |                     |
|           |             |             |    5 | |                     |
|           |   3         |             |    1 | |                     |
|           |             |             |    2 | |                     |
|           |             |             |    3 | |                     |
|           |             |             |    4 | |                     |
|           |             |             |    6 | |                     |
|           |   7         |             |    2 | |                     |
|           |             |             |    4 | |                     |
|           |             |             |    6 | |                     |
|           |             |             |    7 | |                     |
|           |             |             |    8 | |                     |
| 3         |   3         |     8       |    2 | |                     |
|           |             |             |    3 | |                     |
|           |             |             |    5 | |                     |
|           |             |             |    7 | |                     |
|           |   8         |             |    2 | |                     |
|           |             |             |    3 | |                     |
|           |             |             |    5 | |                     |
|           |             |             |    7 | |                     |
|           |  24         |             |    2 | |                     |
|           |             |             |    3 | |                     |
|           |             |             |    5 | |                     |
|           |             |             |    7 | |                     |
|           |             |             |    7 | |                     |
| 4         |   7         |    16       |    2 | |                     |
|           |             |             |    3 | |                     |
|           |             |             |    5 | |                     |
|           |             |             |    7 | |                     |
|           |             |             |    8 | |                     |
|           |  17         |             |    2 | |                     |
|           |             |             |    3 | |                     |
|           |             |             |    5 | |                     |
|           |             |             |    7 | |                     |
|           |  35         |             |    2 | |                     |
|           |             |             |    3 | |                     |
|           |             |             |    5 | |                     |
|           |             |             |    7 | |                     |
| 5         |   7         |    32       |    1 | |                     |
|           |             |             |    2 | |                     |
|           |             |             |    3 | |                     |
|           |  20         |             |    1 | |                     |
|           |             |             |    2 | |                     |
|           |             |             |    3 | |                     |
| 6         |   6         |    32       |    1 | |                     |
|           |             |             |    2 | |                     |
|           |             |             |    3 | |                     |
|           |             |             |    4 | |                     |
|           |             |             |    6 | |                     |
|           |  11         |             |    1 | |                     |
|           |             |             |    2 | |                     |
|           |             |             |    3 | |                     |
|           |             |             |    5 | |                     |



