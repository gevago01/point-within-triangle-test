//
// Created by giannis on 15/02/17.
//

#ifndef POINTINTRIANGLE_TRIANGLEINTERSECTIONS_H
#define POINTINTRIANGLE_TRIANGLEINTERSECTIONS_H

using cv::Point;

class TriangleIntersections {

public:
    static bool barycentric(Point testpoint, Point p1, Point p2, Point p3 );
    static bool parametric(Point testpoint, Point p1, Point p2, Point p3 );
    static bool dot_product_side_check(Point testpoint, Point p1, Point p2, Point p3);

    static double side(Point p1, Point p2, Point testpoint);
};


#endif //POINTINTRIANGLE_TRIANGLEINTERSECTIONS_H
