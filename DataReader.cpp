//
// Created by gevagorou on 14/04/16.
//


#include "DataReader.h"


using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::vector;
using cv::Point2d;

void DataReader::readPoints() {

    cout << "reading file/points now" << endl;
    int i = 0;
    if (!in_file_stream) {
        cout << "failed to read input" << endl;
        exit(-1);
    }

    string line, word;
    vector<string> tokens;
    while (getline(in_file_stream, line)) {

        //ignore comment lines
        if (line[0] == '#') {
            continue;
        }
        //istringstream makes the line string an input string stream
        istringstream record(line);

        /*a record contains a number of coordinates and a cluster id:
        2.58119273751133 -3.0897997256242977 1*/
        while (record >> word) {
            tokens.push_back(word);
        }

        assert(tokens.size()==2);
        double x=std::stod(tokens[0]);
        double y=std::stod(tokens[1]);

        if (x>x_max){
            x_max=x;
        }


        if (y>y_max){
            y_max=y;
        }

        Point2d new_point(x,y);
        


        all_points.push_back(new_point);
        tokens.clear();
        ++i;

    }
    cout << "reading file done" << endl;
}

const vector<cv::Point2d> &DataReader::getAll_points() const {
    return all_points;
}
