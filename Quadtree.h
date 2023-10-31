#include <iostream>
#include <string>
#include "Point.h"
#include "illegal_exception.h"
using namespace std;

class Quadtree
{
        private:
        Point* point_array;

        public:
        // member functions //
        Quadtree();
        //~Quadtree();

        void parse_file();
        bool insert(double X, double Y);


        // member variables //
        string command;
        int m;
        double x0;
        double y0;
        double x1;
        double y1;

        double X;
        double Y;


};