#include <iostream>

#include "DataReader.h"
#include "TriangleIntersections.h"
#include "highgui.h"
#include "opencv2/opencv.hpp"


using std::vector;
using std::cout;
using std::endl;


using cv::Mat;
using cv::moveWindow;
using cv::Point2d;
using cv::Scalar;

void draw_line(Mat &mat, Point2d v1, Point2d v2, const Scalar &sc);

void draw_circle(Mat &mat, Point2d v1, const Scalar &sc);

void draw_line(Mat &mat, Point2d v1, Point2d v2, const Scalar &sc) {

    int thickness = 1;
    cv::line(mat, v1, v2, sc, thickness);
}

void draw_circle(Mat &mat, Point2d v1, const Scalar &sc) {

    int radius = 1;
    int thickness = 1;
    cv::circle(mat, v1, radius, sc, thickness);
}


int main(int argc, char **argv) {
    /// Windows names
    std::string window_name = "Point/Triangle Intersections";

    // Create empty image

    DataReader dr(argv[1]);

    /**our triangle's vertices**/
    Point2d v1(80, 80);
    Point2d v2(80, 120);
    Point2d v3(120, 80);
    /***************************/

    vector<cv::Point2d> all_points = dr.getAll_points();

//    Mat canvas(dr.x_max * 2, dr.y_max * 2, CV_8UC3, Scalar(255, 255, 255));
    Mat canvas(dr.x_max *2 , dr.y_max * 2, CV_32FC3, Scalar(0, 0, 0));
//    cv::Mat canvas = cv::Mat::zeros(dr.x_max * 3, dr.y_max * 3, CV_32FC3);

    for (cv::Point2d point:all_points) {


        //check if point is within triangle
        bool in = TriangleIntersections::barycentric(point, v1, v2, v3);
        bool in2 = TriangleIntersections::parametric(point, v1, v2, v3);
        bool in3 = TriangleIntersections::dot_product_side_check(point, v1, v2, v3);

        if (in) {
            cout << point.x << "," << point.y << endl;
//            draw_circle(canvas, point, Scalar(153, 153, 251));
            draw_line(canvas, point, point,Scalar(0, 255, 0));
        } else {
//            draw_circle(canvas, point, Scalar(0, 255, 0));
            draw_line(canvas, point, point, Scalar(255, 0, 0));
        }

        if (in != in2 && in2 != in3) {
            cout << "methods do not agree" << endl;
            cout << point.x << "," << point.y << endl;
            exit(1);
        }
    }

    //draw triangle
    draw_line(canvas, v1, v2, Scalar(1, 1, 1));
    draw_line(canvas, v2, v3, Scalar(1, 1, 1));
    draw_line(canvas, v1, v3, Scalar(1, 1, 1));

    /// display the image
    namedWindow(window_name, cv::WINDOW_NORMAL);
    imshow(window_name, canvas);
    cv::resizeWindow(window_name,1000,1000);

    cv::waitKey(0);

    return 0;
}

