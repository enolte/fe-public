# fe-public

Test results for the **fe** mesh repo.

## Simplex mesh induction from a point cloud.

Tested with:

  * GNU g++ 11.2.0 (64-bit) Windows 7

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

## Basis construction strategies

#### *C<sup>0</sup> isometric*

* Identical knot selection strategy for any simplex
  * No dimension assumptions
  * No simplex geometry assumptions
* Direct construction of polynomials from simplex vertices
* L<sup>∞</sup>-normalization (implicit)
* Continuous splines
* No differentiability guarantees
* min degree = 1

#### *C<sup>1</sup> isometric*

* Identical knot selection strategy for any simplex
  * No dimension assumptions
  * No simplex geometry assumptions
* Direct construction of polynomials from simplex vertices
* Differentiable splines (approximate normalization)
* min degree = 2

## Test cases

Test cases are organized by geometric selection of input points. For the below,

* *k* = simplex dimension
* *m* = capacity dimension of source region

Various embedding dimension values (*n*) are tested.

### *m*-cube vertices, case *k* = *m*

* unit cube
  * [mesh](./test/unit_cube/mesh)
  * [basis](./test/unit_cube/basis) (*pending*)
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
