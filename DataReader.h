//
// Created by gevagorou on 14/04/16.
//

#ifndef THESIS_DATAREADER_H
#define THESIS_DATAREADER_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <ml.h>
#include "opencv/cxcore.hpp"

class DataReader {
private:
    std::string file_name;
    std::ifstream in_file_stream;
    std::vector<cv::Point2d> all_points;

public:
    const std::vector<cv::Point2d> &getAll_points() const;

    double x_max;
    double y_max;

    DataReader(char *filename) : file_name(filename), in_file_stream(filename), x_max(0), y_max(0) {
        std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
        readPoints();
    };

    void readPoints();


};

#endif //THESIS_DATAREADER_H