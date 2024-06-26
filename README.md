# Quadtree Implementation

This repository contains a C++ project implementing a Quadtree data structure, a hierarchical tree data structure used to partition a two-dimensional space and efficiently store and query points within that space. For more details [click here to preview the design document](https://drive.google.com/file/d/1_dZCjfYj0GbsTUTZ4MIfo61sEsHemuF7/view?usp=sharing)


## Overview

The Quadtree class in this project provides functionality for creating and managing a Quadtree data structure. It supports operations such as insertion of points, searching for points within a specified distance, finding the nearest point to a given point, querying points within a range, and more.

## Core Functionalities

### Constructor

#### `Quadtree::Quadtree()`

- Default constructor for the Quadtree class.

#### `Quadtree::Quadtree(int m, int x0, int y0, int x1, int y1)`

- Constructs a Quadtree with specified parameters `m` and bounding box coordinates `(x0, y0, x1, y1)`.

### Initialization

#### `bool Quadtree::init(int x0, int y0, int x1, int y1)`

- Initializes the Quadtree with the specified bounding box coordinates `(x0, y0, x1, y1)`.

### Insertion

#### `bool Quadtree::insert(double X, double Y)`

- Inserts a point with coordinates `(X, Y)` into the Quadtree.

### Searching

#### `bool Quadtree::search(double X, double Y, double d)`

- Searches for points within a specified distance `d` of the point `(X, Y)`.

### Nearest Point

#### `Point Quadtree::nearest(double X, double Y)`

- Finds the nearest point to the specified point `(X, Y)`.

### Range Query

#### `bool Quadtree::range(double xr0, double yr0, double xr1, double yr1)`

- Queries points within the specified range `(xr0, yr0, xr1, yr1)`.

### Utility Functions

#### `bool Quadtree::is_leaf()`

- Checks if the current node is a leaf node in the Quadtree.

## Getting Started

To use this Quadtree implementation in your C++ project, follow these steps:

1. Clone the repository to your local machine.
2. Include the necessary header files in your project.
3. Instantiate a `Quadtree` object and use its methods to perform desired operations on points.

## Example Terminal Input

```cpp
INIT 9 0 0 16 16
INSERT 1 1
INSERT 1 2
INSERT 1 3
INSERT 1 4
INSERT 1 5
INSERT 1 6
INSERT 1 7
INSERT 1 8
INSERT 1 9
INSERT 1 10
INSERT 1 11
INSERT 1 12
INSERT 1 13
INSERT 1 14
INSERT 1 15
RANGE 0 0 4 4
EXIT
```

## Example Terminal Output

```cpp
success
success
success
success
success
success
success
success
success
success
success
success
success
success
success
success
1 1 1 2 1 3
