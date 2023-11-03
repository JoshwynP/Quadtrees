#include <iostream>
#include <string>
#include "Point.h"
#include "illegal_exception.h"
using namespace std;

class Quadtree
{
        private:
        Point* point_array;

        Quadtree* new_leaf_LB = nullptr;
        Quadtree* new_leaf_RB = nullptr;
        Quadtree* new_leaf_LT = nullptr;
        Quadtree* new_leaf_RT = nullptr;

        public:
        // member functions //
        Quadtree();
        Quadtree(int m, int x0, int y0, int x1, int y1);
        //~Quadtree();

        void parse_file();
        bool init(int x0, int y0, int x1, int y1);
        bool insert(double X, double Y);
        bool search(double X, double Y, double d);
        Point nearest(double X, double Y);
        bool range(double xr0, double yr0, double xr1, double yr1);

        Quadtree* child(double X, double Y);
        bool is_leaf();


        // member variables //
        int m;
        double x0;
        double y0;
        double x1;
        double y1;
        int counter;
        int num_subtrees;

        // LEFT BOTTOM
        double lower_half_LBX;
        double lower_half_LBY;

        // RIGHT BOTTOM
        double lower_half_RBX;
        double lower_half_RBY;

        // LEFT TOP
        double upper_half_LBX;
        double upper_half_LBY;

        // RIGHT TOP
        double upper_half_RBX;
        double upper_half_RBY;

        double half_X;
        double half_Y;

        double hold_x0;
        double hold_y0;
        double hold_x1;
        double hold_y1;

        Quadtree* parent;
        Quadtree* dummy_new_parent;
        Quadtree* hold_parent;




};
