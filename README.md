# Point within triangle test
This repository implements in C++, all the methods discussed in  [this blog](http://totologic.blogspot.co.uk/2014/01/accurate-point-in-triangle-test.html)
, for checking whether a point is within a triangle. 
The application draws on the screen the triangle, the containing points and the points that are not enclosed in the triangle with different colors. 
A sample input file is provided (points.txt) that contains 2D points to check whether each one is within a triangle. The triangle is hardcoded into the source code.


## Project Requirements
   1. C++11
   2. CMake 
   3. OpenCV 

   
## How to run on Linux
```bash
git clone https://github.com/gevago01/Agglomerative-Clustering.git
cd Agglomerative-Clustering
mkdir build
cd build
cmake ..
make
./Agglomerative
```

