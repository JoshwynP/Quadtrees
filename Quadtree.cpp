#include <iostream>
#include <string>
#include <cmath>
#include "Quadtree.h"
using namespace std;

Quadtree::Quadtree() {}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

Quadtree::Quadtree(int m, int x0, int y0, int x1, int y1) 
{
    Quadtree* new_leaf_LB = nullptr;
    Quadtree* new_leaf_RB = nullptr;
    Quadtree* new_leaf_LT = nullptr;
    Quadtree* new_leaf_RT = nullptr;

    this->m = m;
    
    counter = 0;
    num_subtrees = 0;
    point_array = new Point[m];

    cout << "new tree made" << endl;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

bool Quadtree::init(int x0, int y0, int x1, int y1)
{
    if ( x0 < x1 && y0 < y1 )
    {
        return true;
    }
    else 
    {
        // exception thing
        return false;
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// insert function definition: 
// -------------------------  returns true or false if a point was inserted successfully
bool Quadtree::insert(double X, double Y)
{
    if (this->new_leaf_LB != nullptr)
    {
        half_X = (x0 + x1) / 2;
        half_Y = (y0 + y1) / 2;

        if (X <= half_X && Y < half_Y)   // add data to left-bottom leaf
        {
            cout << "LB" << endl;
            return this->new_leaf_LB->insert(X, Y);
        }
        else if (X <= x1 && Y < half_Y)   // add data to right-bottom leaf
        {
            cout << "RB" << endl;
            return this->new_leaf_RB->insert(X, Y);
        }
        else if (X <= half_X && Y <= y1)   // add data to left-top leaf
        {
            cout << "LT" << endl;
            return this->new_leaf_LT->insert(X, Y);
        }
        else if (X <= x1 && Y <= y1)   // add data to right-top leaf
        {
            cout << "RT" << endl;
            return this->new_leaf_RT->insert(X, Y);
        }
    }
    else
    {
        cout << this->counter << endl;
        // traverse the tree until we find the appropriate leaf node
        // Checks for duplicate points 
        for (int i = 0; i < m; i++)
        {
            if (this->point_array[i].new_x == X && this->point_array[i].new_y == Y)
            {
                cout << "duplicate" << endl;
                return false;
            }
        }
        
        if (this->counter < m)
        {   
            cout << "Inserting into the " << this->counter << " element in the array" << endl;
    
            //just insert into the array
            this->point_array[this->counter].new_x = X;
            this->point_array[this->counter].new_y = Y;
            cout << "New points: " << this->point_array[this->counter].new_x << "," << this->point_array[this->counter].new_y << endl;
            this->counter++;
            return true;
        }
        else
        {
            // wen need to:
            // 1. Make the 4 new child nodes
            // 2. call insert on each of the points in the node
            // 3. delete the parent node
            cout << "make 4 subranches" << endl;
            this->new_leaf_LB = new Quadtree(m, x0, half_X, y0, half_Y);
            this->new_leaf_RB = new Quadtree(m, half_X, x1, y0, half_Y);
            this->new_leaf_LT = new Quadtree(m, x0, half_X, half_Y, y1);
            this->new_leaf_RT = new Quadtree(m, half_X, x1, half_Y, y1);

            for (int i = 0; i < m; i++)
            {
                cout << "moving old array to new" << endl;
                //parent = dummy_new_parent;
                this->insert(this->point_array[i].new_x, this->point_array[i].new_y);
            }

            cout << "checking delete" << endl;
            delete[] this->point_array;
            this->point_array = nullptr;
            cout << "insert overflow" << endl;
            return this->insert(X, Y);
        }
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// search function definition
// -------------------------  returns true if there exists a point which is less than d away from (X, Y)
bool Quadtree::search(double X, double Y, double d)
{
    if (new_leaf_LB == nullptr)
    {
        for (int i = 0; i < counter; i++)
        {
            if ((this->point_array[i].new_x + d) < X && (this->point_array[i].new_y + d) < Y)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        half_X = (x0 + x1) / 2;
        half_Y = (y0 + y1) / 2;

        if (X <= half_X && Y < half_Y)   // add data to left-bottom leaf
        {
            cout << "LB" << endl;
            return this->new_leaf_LB->search(X, Y, d);
        }
        else if (X <= x1 && Y < half_Y)   // add data to right-bottom leaf
        {
            cout << "RB" << endl;
            return this->new_leaf_RB->search(X, Y, d);
        }
        else if (X <= half_X && Y <= y1)   // add data to left-top leaf
        {
            cout << "LT" << endl;
            return this->new_leaf_LT->search(X, Y, d);
        }
        else if (X <= x1 && Y <= y1)   // add data to right-top leaf
        {
            cout << "RT" << endl;
            return this->new_leaf_RT->search(X, Y, d);
        }
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// nearest function definition
// -------------------------  
Point Quadtree::nearest(double X, double Y)
{
    Point nearest = Point(x1*2, y1*2);
    if (new_leaf_LB == nullptr)
    {
        for (int i = 0; i < counter; i++)
        {
            if (abs((this->point_array[i].new_x - X)) == (nearest.new_x - X) && abs((this->point_array[i].new_y - Y)) == (nearest.new_y - Y))
            {
                if ((this->point_array[i].new_x > nearest.new_x && this->point_array[i].new_y > nearest.new_y) || this->point_array[i].new_x > nearest.new_x)
                {
                    nearest.new_x = point_array[i].new_x;
                    nearest.new_y = point_array[i].new_y;
                }
            }
            else if (abs((this->point_array[i].new_x - X)) < (nearest.new_x - X) && abs((this->point_array[i].new_y - Y)) < (nearest.new_y - Y))
            {
                nearest.new_x = point_array[i].new_x;
                nearest.new_y = point_array[i].new_y;
            }
            else
            {
                continue;
            }
        }
    }

    else
    {
        new_leaf_LB->nearest(X, Y);
        new_leaf_RB->nearest(X, Y);
        new_leaf_LT->nearest(X, Y);
        new_leaf_RT->nearest(X, Y);

        return nearest;
    }    
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// range function definition
// -------------------------  
bool Quadtree::range(double xr0, double yr0, double xr1, double yr1)
{
    int output_counter = 0;
    if (new_leaf_LB == nullptr)
    {
        for (int i = 0; i < counter; i++)
        {
            if (this->point_array[i].new_x > xr0 && this->point_array[i].new_y > yr0 && this->point_array[i].new_x < xr1 && this->point_array[i].new_y < yr1)
            {
                output_counter++;
                cout << this->point_array[i].new_x << " " << this->point_array[i].new_y << " ";
            }
        }
    }
    else
    {
        new_leaf_LB->range(xr0, yr0, xr1, yr1);
        new_leaf_RB->range(xr0, yr0, xr1, yr1);
        new_leaf_LT->range(xr0, yr0, xr1, yr1);
        new_leaf_RT->range(xr0, yr0, xr1, yr1);
    }    

    if (output_counter > 0)
    {
        cout << "point in range" << endl;
        return true;
    }
    else 
    {
        cout << "no point in range" << endl;
        return false;
    }
    cout << endl;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// is_leaf function definition: 
// ---------------------------  returns true if the node passed in is a leaf
bool Quadtree::is_leaf()
{
    if (new_leaf_LB == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
