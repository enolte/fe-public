
# Vertices of the m-cube



## Parameters

### Inputs

* *m* = cell dimension = 5, 6, 7, 9, 11, 12, 13, 14
* *n* = embedding dimension = 6, 7, 9, 11, 14, 17, 23, ..., as listed below
* *strategy* : one of *simple* or *proximity*

### Internal

* *num points* = number of data points = 2 ** *m* for the *m*-cube
* Subsets
  * ...in data set : 2 ** (2 ** *m*)
  * ...in search space : C(2 ** *m*, *m*) (binomial coefficient)
* *simplex dim* = dimension of each simplex constructed
* *embedding dim* = the dimension of the linear space in which the mesh representation is embedded

### Outputs

* *num simplices* = number of simplices in the constructed mesh
  * For *proximity* strategy, *num simplices* = 2***m*
  * For *simple* strategy, *num simplices* = 2***m* - *m*
* *construction time* = mesh construction time for the given parameters
  * measured in nanoseconds, shown in seconds below
  * This does not include logging time or verification time
* *max systems / point* = the max number of systems solved to adjoin a single point
  * For *proximity* strategy, this value's distribution across the point cloud is *m*+1, constant.
  * For *simple* strategy, it is bimodal and asymmetric.

## Summary results

Windows 7, g++.exe (Rev2, Built by MSYS2 project) 11.2.0

* `g++ --std=c++2a -Wall -Werror -O3`

Mesh construction test results with full algorithm log outputs are in directory `./test`.

### *simple* strategy

simplex dim|embedding dim|num points|num simplices|construction time (s)|max systems / point
:-:|:--:|:----:|:----:|-----------------:|:-:
 2 |   2|     4|     2| *    0.0000000   |      3
 | |   3|      |      | *    0.0000000   |
 3 |   3|     8|     5| *    0.0010000   |     20
 5 |   9|    32|    27|      0.0840048   |   4844
 | | 100|      |      |      0.4710269   |
 | | 300|      |      |     10.3105897   |
 6 |   6|    64|    58|      8.0364597   | 910686
 | |  11|      |      |      8.9625126   |
 | |  31|      |      |     14.3210053   |
 | |  50|      |      |     19.8091331   |

### *proximity* strategy

simplex dim|embedding dim|num points|num simplices|construction time (s)|max systems / point
:-:|:--:|:----:|:----:|----------------:|:-:
 6 |   6|    64|    32| *    0.0260015   |      7
 | |  11|      |      | *    0.0250004   |
 | |  31|      |      |      0.0475007   |
 | | 131|      |      |      0.2430139   |
 7 |   7|   128|    64|      0.0712511   |      8
 | |  45|      |      |      0.1940111   |
 | |  93|      |      |      0.6100094   |
 | | 202|      |      |      7.3044178   |
 9 |  14|   512|   256|      1.5640894   |     10
 | |  23|      |      |      2.0160316   |
 | |  98|      |      |     14.2278137   |
 | | 145|      |      |     29.7297005   |
 | | 200|      |      |    152.9186335   |
11 |  11|  2048|  1024|     30.5517474   |     12
 | |  14|      |      |     34.2589595   |
 | |  35|      |      |     71.3640818   |
 | |  70|      |      |    169.3526864   |
12 |  12|  4096|  2048|    151.0918859   |     13
 | |  17|      |      |    180.3243131   |
 | |  30|      |      |    277.5564812   |
13 |  13|  8192|  4096|    685.4306396   |     14
 | |  16|      |      |    782.5215029   |
14 |  14| 16384|  8192|   3425.7124905   |     15



## Timing changes

### *simple* strategy

simplex dim|embedding dim|current|previous
:-:|:---:|-------------------|:-:
 2 |   2 | * 0.0000000 s     | *  0m0.050s
 | |   3 | * 0.0000000 s     | *  0m0.042s
 3 |   3 | * 0.0010000 s     | *  0m0.052s
 5 |   9 |   0.0840048 s     |    0m0.315s
 | | 100 |   0.4710269 s     |    0m2.532s
 | | 300 |  10.3105897 s     |    1m3.453s
 6 |   6 |   8.0364597 s     |   0m19.964s
 | |  11 |   8.9625126 s     |   0m22.230s
 | |  31 |  14.3210053 s     |   0m28.070s
 | |  50 |  19.8091331 s     |   0m42.580s


### *proximity* strategy

simplex dim|embedding dim|current|previous
:-:|:---:|-------------------|:-:
 6 | 6   | * 0.0260015 s     | *  0m0.070s
 | | 11  | * 0.0250004 s     | *  0m0.112s
 | | 31  |   0.0475007 s     |    0m0.111s
 | | 131 |   0.2430139 s     |    0m0.498s
 7 | 7   |   0.0712511 s     |    0m0.182s
 | | 45  |   0.1940111 s     |    0m0.363s
 | | 93  |   0.6100094 s     |    0m0.934s
 | | 202 |   7.3044178 s     |    0m4.595s
 9 | 14  |   1.5640894 s     |    0m1.951s
 | | 23  |   2.0160316 s     |    0m2.448s
 | | 98  |  14.2278137 s     |   0m18.850s
 | | 145 |  29.7297005 s     |   0m41.101s
 | | 200 | 152.9186335 s     |   1m22.800s
11 | 11  |  30.5517474 s     |   0m35.641s
 | | 14  |  34.2589595 s     |   0m37.103s
 | | 35  |  71.3640818 s     |   1m15.326s
 | | 70  |   2.822544773 min |   3m23.921s
12 | 12  |   2.518198098 min |   2m42.134s
 | | 17  |   3.005405218 min |   2m58.969s
 | | 30  |   4.625941353 min |   4m30.456s
13 | 13  |  11.423843993 min |  12m37.612s
 | | 16  |  13.042025048 min |  13m29.730s
14 | 14  |  57.095208175 min |  59m10.577s


