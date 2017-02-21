//
// Created by giannis on 15/02/17.
//

#include <ml.h>
#include "TriangleIntersections.h"

using cv::Point;

/**
 *
 * @param testpoint
 * @param p1 1st vertex of triangle
 * @param p2 2nd vertex of triangle
 * @param p3 3rd vertex of triangle
 * @return true or false depending on whether testpoint is within the triangle
 */
bool TriangleIntersections::barycentric(Point testpoint, Point p1, Point p2, Point p3) {


    double a, b, c, denominator;
    denominator = ((p2.y - p3.y) * (p1.x - p3.x) +
                   (p3.x - p2.x) * (p1.y - p3.y));
    a = ((p2.y - p3.y) * (testpoint.x - p3.x) +
         (p3.x - p2.x) * (testpoint.y - p3.y)) / denominator;
    b = ((p3.y - p1.y) * (testpoint.x - p3.x) +
         (p1.x - p3.x) * (testpoint.y - p3.y)) / denominator;
    c = 1 - a - b;
    return 0 <= a && a <= 1 && 0 <= b && b <= 1 && 0 <= c && c <= 1;

}

bool TriangleIntersections::parametric(Point testpoint, Point p1, Point p2, Point p3) {
    double denominator = (p1.x * (p2.y - p3.y) + p1.y * (p3.x - p2.x) +
                          p2.x * p3.y - p2.y * p3.x);
    double t1 = (testpoint.x * (p3.y - p1.y) + testpoint.y * (p1.x - p3.x) -
                 p1.x * p3.y + p1.y * p3.x) / denominator;
    double t2 = (testpoint.x * (p2.y - p1.y) + testpoint.y * (p1.x - p2.x) -
                 p1.x * p2.y + p1.y * p2.x) / -denominator;
    double s = t1 + t2;

    return 0 <= t1 && t1 <= 1 && 0 <= t2 && t2 <= 1 && s <= 1;
}


bool TriangleIntersections::dot_product_side_check(Point testpoint, Point p1, Point p2, Point p3) {

    bool checkSide1 = side(p1, p2, testpoint) >= 0;
    bool checkSide2 = side(p2, p3, testpoint) >= 0;
    bool checkSide3 = side(p3, p1, testpoint) >= 0;
    return checkSide1 && checkSide2 && checkSide3;
}

double TriangleIntersections::side(Point p1, Point p2, Point testpoint) {

    return (p2.y - p1.y) * (testpoint.x - p1.x) + (-p2.x + p1.x) * (testpoint.y - p1.y);
}
