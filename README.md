# fe-public

Test results for the **fe** mesh repo.

## Simplex mesh induction from a point cloud.

Tested with:

  * GNU g++ 11.2.0 (64-bit) Windows 7
  * GNU g++ 9.2.1 (64-bit) Ubuntu

Older compilers are not supported.

## Mesh Construction Strategies

#### *simple*

* encounter-ordered subset search (*n*-dimensional "z-order" iteration)
* opportunistic first match
* no additional simplex binding
* no data assumptions

#### *proximity*

* proximity-sorted search (*n*-dimensional partial proximity-sorted search)
* opportunistic first match
* no additional simplex binding
* no data assumptions

## Test cases

Test cases are organized by geometric selection of input points. For the below,

* *k* = simplex dimension
* *m* = capacity dimension of source region

Various embedding dimension values (*n*) are tested.

### *m*-cube vertices, case *k* = *m*

* [unit cube](./test/unit_cube)
* nested m-cubes (*pending*)
* two intersecting m-cubes (*pending*)
* m-cubic lattice (*pending*)

### *m*-cube vertices, case *k* < *m*

* unit cube (*pending*)
* nested m-cubes (*pending*)
* two intersecting m-cubes (*pending*)
* m-cubic lattice (*pending*)

### *m*-sphere

* co-spherical grid points (*pending*)
* spherical shell (*pending*)
* nested m-spheres (*pending*)
* two intersecting m-cubes (*pending*)


### random n-dimensional point cloud

* constrained m-angle (*pending*)
* constrained point distance (*pending*)
* constrained simplex measure (*pending*)
