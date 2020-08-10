# fe-public

Test results for the **fe** mesh repo.

## Simplex mesh induction from a point cloud.

Tested with:

  * GNU g++ 9.2.1 (64-bit) Ubuntu
  * GNU g++ 9.1.0 (64-bit) Windows 7
  * GNU g++ 8.1.0 (32-bit) Windows 7
  * ~~GNU g++ 7.3.0 (64-bit) Ubuntu~~ (*no longer supported*)

Mesh construction test results with full algorithm log outputs are in directory `./test`.

### Test cases

#### Vertices of the m-cube

**Strategies**

  * *simple*:

        encounter-ordered subset search
        opportunistic first match
        no data assumptions


  * *proximity*:

        proximity-sorted search
        opportunistic first match
        no additional cell binding
        no data assumptions

**Parameters**

  * Inputs

    * *m* = cell dimension = 5, 6, 7, 9, 11, 12, 13
    * *n* = embedding dimension = 6, 7, 9, 11, 14, 17, 23, ..., as listed below
    * *strategy* : one of *simple* or *proximity*

  * Internal

    * *p* = number of data points = 2 ** *m* for the *m*-cube
    * Subsets
      * ...in data set : 2 ** (2 ** *m*)
      * ...in search space : C(2 ** *m*, *m*) (binomial coefficient)

  * Outputs

    * *cells constructed* = number of cells in the constructed mesh
    * *execution time* = test program execution real time for the given parameters.
      * This includes mesh construction time, logging time, and verification time.
      * Actual mesh construction time is not shown. (This is pending.)
    * *systems per point* = the max number of systems solved to adjoin a single point.
      * For *proximity* strategy, this value's distribution across the point cloud is *m*+1, constant.
      * For *simple* strategy, it is bimodal and asymmetric.

**Summary results**


```
     m      n      strategy      p      cells constructed    execution time    systems per point
    ___    ___    _________    _____    _________________    ______________    _________________

      2      2       simple        4                    2          0m0.050s*                   3
      2      3       simple        4                    2          0m0.042s*                   3
      3      3       simple        8                    5          0m0.052s*                  20
      5      9       simple       32                   27          0m0.315s                 4844
      5    100       simple       32                   27          0m2.532s                 4844
      5    300       simple       32                   27          1m3.453s                 4844
      6      6       simple       64                   58         0m19.964s               910686
      6     11       simple       64                   58         0m22.230s               910686
      6     31       simple       64                   58         0m28.070s               910686
      6     50       simple       64                   58         0m42.580s               910686
      6      6    proximity       64                   32          0m0.070s                    7
      6     11    proximity       64                   32          0m0.112s                    7
      6     31    proximity       64                   32          0m0.111s                    7
      6    131    proximity       64                   32          0m0.498s                    7
      7      7    proximity      128                   64          0m0.182s                    8
      7     45    proximity      128                   64          0m0.363s                    8
      7     93    proximity      128                   64          0m0.934s                    8
      7    202    proximity      128                   64          0m4.595s                    8
      9     14    proximity      512                  256          0m1.951s                   10
      9     23    proximity      512                  256          0m2.448s                   10
      9     98    proximity      512                  256         0m18.850s                   10
      9    145    proximity      512                  256         0m41.101s                   10
     11     11    proximity     2048                 1024         0m35.641s                   12
     11     14    proximity     2048                 1024         0m37.103s                   12
     12     12    proximity     4096                 2048         2m42.134s                   13
     12     17    proximity     4096                 2048         2m58.969s                   13
     12     30    proximity     4096                 2048         4m30.456s                   13
     13     13    proximity     8192                 4096        12m37.612s                   14
     13     16    proximity     8192                 4096        13m29.730s                   14
     14     14    proximity    16384                 8192        59m10.577s                   15

```

Contact: eric dot alan dot nolte at gee mail dot com
