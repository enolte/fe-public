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

* proximity-sorted search (*n*-dimensional partial "z-order" search)
* opportunistic first match
* no additional simplex binding
* no data assumptions


## Test cases

### *m*-cube

* [vertices](./test/unit_cube)
* Nested m-cubes (*pending*)
* m-cubic lattice (*pending*)
* two intersecting m-cubes (*pending*)

### *m*-sphere

* co-spherical grid points (*pending*)
* spherical shell (*pending*)
* nested m-spheres (*pending*)
* two intersecting m-cubes (*pending*)


### random point cloud

* constrained m-angle (*pending*)
* constrained point distance (*pending*)
* constrained simplex measure (*pending*)
