#include <iostream>
#include <string>
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
    
    counter = 0;
    num_subtrees = 0;
    point_array = new Point[m];

    half_X = (x0 + x1) / 2;
    half_Y = (y0 + y1) / 2;

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
        return false;
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// insert function definition: 
// -------------------------  returns true or false if a point was inserted successfully
bool Quadtree::insert(Quadtree* parent, double X, double Y)
{
    if (X < x0 || Y < y0 || X > x1 || Y > y1)
    {
        return false;
    }
    else
    {        
        cout << this->counter << endl;
        // traverse the tree until we find the appropriate leaf node
        if (is_leaf(parent))
        {
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
                    new_leaf_LB = new Quadtree(m, x0, half_X, y0, half_Y);
                    new_leaf_RB = new Quadtree(m, half_X, x1, y0, half_Y);
                    new_leaf_LT = new Quadtree(m, x0, half_X, half_Y, y1);
                    new_leaf_RT = new Quadtree(m, half_X, x1, half_Y, y1);

                    for (int i = 0; i < m; i++)
                    {
                        cout << "moving old array to new" << endl;
                        //parent = dummy_new_parent;
                        insert(parent, this->point_array[i].new_x, this->point_array[i].new_y);
                    }

                    cout << "checking delete" << endl;
                    delete[] this->point_array;
                    cout << "insert overflow" << endl;
                    return insert(parent, X, Y);
            }
        }
        else
        {
            if (X <= half_X && Y < half_Y)   // add data to left-bottom leaf
            {
                cout << "LB" << endl;
                parent = parent->new_leaf_LB;
            }
            else if (X > half_X && Y < half_Y)   // add data to right-bottom leaf
            {
                cout << "RB" << endl;
                parent = parent->new_leaf_RB;
            }
            else if (X <= half_x && Y >= half_y)   // add data to left-top leaf
            {
                cout << "LT" << endl;
                parent = parent->new_leaf_LT; 
            }
            else if (X > half_x && Y > half_y)   // add data to right-top leaf
            {
                cout << "RT" << endl;
                parent = parent->new_leaf_RT;
            }
            // maybe change to if insert node is true, return true and vice versa.
            cout << "Recursive call" << endl;
            return insert(parent, X, Y);
        }
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

// child function definition: 
// -------------------------  returns a Quadtree pointer of the child of the given node
Quadtree* Quadtree::child(Quadtree* parent, double X, double Y)
{
    //each boundaary case for the 4-way split, and then return the corresponding quadtree child
    if (X == 1000000000)
    {
    //     if (Y < half_Y)
    //     {
    //         cout << "x = half" << endl;
    //         parent = parent->new_leaf_LB;
    //     }
    //     else
    //     {
    //         cout << "x = half" << endl;
    //         parent = parent->new_leaf_RB;
    //     }
    // }
    // else if (X != half_X && Y == half_Y)
    // {
    //     if (X < half_X)
    //     {
    //         cout << "y = half" << endl;
    //         parent = parent->new_leaf_LT;
    //     }
    //     else
    //     {
    //         cout << "y = half" << endl;
    //         parent = parent->new_leaf_RT;
    //     }
    // }
    // else if (X == half_X && Y == half_Y)
    // {
    //     cout << "X & y = half" << endl;
    //     parent = parent->new_leaf_LT;
    }
    else
    {
        if (X <= half_X && Y < half_Y)   // add data to left-bottom leaf
        {
            cout << "LB" << endl;
            parent = parent->new_leaf_LB;
        }
        else if (X > half_X && Y < half_Y)   // add data to right-bottom leaf
        {
            cout << "RB" << endl;
            parent = parent->new_leaf_RB;
        }
        else if (X <= half_x && Y >= half_y)   // add data to left-top leaf
        {
            cout << "LT" << endl;
            parent = parent->new_leaf_LT; 
        }
        else if (X > half_x && Y > half_y)   // add data to right-top leaf
        {
            cout << "RT" << endl;
            parent = parent->new_leaf_RT;
        }
    }
    return parent;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


        // if (new_parent != nullptr)
        // {
        //     cout << "not at lowest node" << endl;
        //     hold_parent = new_parent;
        //     num_subtrees++;

        //     if (X == half_X && Y != half_Y)
        //     {
        //         if (Y < half_Y)
        //         {
        //             cout << "x = half" << endl;
        //             new_parent = new_parent->new_leaf_LB;
        //             insert(X, Y);
        //             return true;
        //         }
        //         else
        //         {
        //             cout << "x = half" << endl;
        //             new_parent = new_parent->new_leaf_RB;
        //             insert(X, Y);
        //             return true;
        //         }
        //     }

        //     else if (X != half_X && Y == half_Y)
        //     {
        //         if (X < half_X)
        //         {
        //             cout << "y = half" << endl;
        //             new_parent = new_parent->new_leaf_LT;
        //             insert(X, Y);
        //             return true;
        //         }
        //         else
        //         {
        //             cout << "y = half" << endl;
        //             new_parent = new_parent->new_leaf_RT;
        //             insert(X, Y);
        //             return true;
        //         }
        //     }

        //     else if (X == half_X && Y == half_Y)
        //     {
        //         cout << "X & y = half" << endl;
        //         new_parent = new_parent->new_leaf_LT;
        //         insert(X, Y);
        //         return true;
        //     }
        //     else
        //     {
        //         if (X < half_X && Y < half_Y)   // add data to left-bottom leaf
        //         {
        //             cout << "1st" << endl;
        //             new_parent = new_parent->new_leaf_LB;
        //             insert(X, Y);
        //             return true;
        //         }
        //         if (X > half_X && Y < half_Y)   // add data to right-bottom leaf
        //         {
        //             cout << "2nd" << endl;
        //             new_parent = new_parent->new_leaf_RB;
        //             insert(X, Y);
        //             return true;
        //         }
        //         if (X < half_x && Y > half_y)   // add data to left-top leaf
        //         {
        //             cout << "3rd" << endl;
        //             new_parent = new_parent->new_leaf_LT; 
        //             insert(X, Y);
        //             return true;
        //         }
        //         if (X > half_x && Y > half_y)   // add data to right-top leaf
        //         {
        //             cout << "4th" << endl;
        //             new_parent = new_parent->new_leaf_RT;
        //             insert(X, Y);
        //             return true;
        //         }
        //     }
        // }

       

    //     cout << hold_parent->counter << endl;
    //     if (hold_parent->counter < m)
    //     {
    //         //just insert into the array
    //         point_array[hold_parent->counter].new_x = X;
    //         point_array[hold_parent->counter].new_y = Y;
    //         cout << "New points: " << point_array[hold_parent->counter].new_x << "," << point_array[hold_parent->counter].new_y << endl;
    //         hold_parent->counter++;
    //         return true;
    //     }
    //     else
    //     {
    //         // wen need to:
    //         // 1. Make the 4 new child nodes
    //         // 2. call insert on each of the points in the node
    //         // 3. delete the parent node
    //             cout << "make 4 subranches" << endl;
    //             new_leaf_LB = new Quadtree(m, x0, half_X, y0, half_Y);
    //             new_leaf_RB = new Quadtree(m, half_X, x1, y0, half_Y);
    //             new_leaf_LT = new Quadtree(m, x0, half_X, half_Y, y1);
    //             new_leaf_RT = new Quadtree(m, half_X, x1, half_Y, y1);

    //             for (int i = 0; i < m; i++)
    //             {
    //                 cout << "moving old array to new" << endl;
    //                 new_parent = dummy_new_parent;
    //                 insert(new_parent, point_array[i].new_x, point_array[i].new_y);
    //             }

    //             cout << "checking delete" << endl;
    //             delete[] point_array;
    //             cout << "insert overflow" << endl;
    //             insert(X,Y);
    //             return true;
    //     }
    // }

    // if (X < half_x && Y < half_y)
    //     {
    //         // add data to left-bottom leaf
    //         new_leaf_LB->point_array[counter] = Point(X, Y);
    //     }

    //     if (X > half_x && Y < half_y)
    //     {
    //         // add data to left-bottom leaf
    //         new_leaf_RB->point_array[this->counter] = Point(X, Y);
    //     }

    //     if (X < half_x && Y > half_y)
    //     {
    //         // add data to left-bottom leaf
    //         new_leaf_LT->point_array[this->counter] = Point(X, Y);
    //     }

    //     if (X > half_x && Y > half_y)
    //     {
    //         // add data to left-bottom leaf
    //         new_leaf_RT->point_array[this->counter] = Point(X, Y);
    //     }

    // counter++;
    // if(counter <= (m-1))
    // {
    //     this->point_array[counter] = Point(X, Y);
    //     counter++;
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }


// is_leaf function definition: 
// ---------------------------  returns true if the node passed in is a leaf
bool Quadtree::is_leaf(Quadtree* node)
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


