#include <iostream>
#include <string>
#include "Quadtree.h"
using namespace std;

void parse_file()
{
    Quadtree* root;
    string command;
    int m;
    double x0;
    double y0;
    double x1;
    double y1;
    double X;
    double Y;
    double d;
    int num = 0;

    while (cin >> command) 
    {
///////// INIT command is entered //
        if (command == "INIT") 
        {
            cin >> m >> x0 >> y0 >> x1 >> y1;

            root = new Quadtree(m, x0, y0, x1, y1);

            root->m = m;
            root->x0 = x0;
            root->y0 = y0;
            root->x1 = x1;
            root->y1 = y1;

            if (root->init(x0, y0, x1, y1))
            {
                cout << "success" << endl;
            }
            /////// End of the INIT command ///////
        } 
        
////////// INSERT command is entered //
        else if (command == "INSERT")
        { 
            double X;
            double Y;
            cin >> X >> Y;

            root->parent = root;
            root->dummy_new_parent = root;

            if (X < root->x0 || Y < root->y0 || X > root->x1 || Y > root->y1)
            {
                cout << "failure" << endl;
            }
            else
            {
                num++;
                if (root->insert(X, Y))
                {
                    cout << "success" << endl;
                }
                else
                {
                    cout << "failure" << endl;
                }
            }
            /////// End of the INSERT command ///////

        } 
        
////////// SEARCH command is entered //
        else if (command == "SEARCH") 
        {
            cin >> X >> Y >> d;

            if (root->search(X, Y, d) && d > 0)
            {
                cout << "point exists" << endl;
            }
            else
            {
                cout << "no point exists" << endl;
            }
        } 
////////// End of the SEARCH command ///////

//-----------------------------------------------------------------------//

////////// NEAREST command is entered //
        else if (command == "NEAREST") 
        {
            cin >> X >> Y;

            if (num >= 2 && X <= root->x1 && Y <= root->y1)
            {
                Point hold = root->nearest(X, Y);
                cout << hold.new_x << " " << hold.new_y << endl;
            }
            else 
            {
                cout << "no point exists" << endl;
            }
            /////// End of the NEAREST command ///////
        }
        
        else if (command == "RANGE") //RANGE command is entered//
        { 
           double xr0;
           double yr0;
           double xr1;
           double yr1;

           cin >> xr0 >> yr0 >> xr1 >> yr1;

           if (root->range(xr0, yr0, xr1, yr1) == false)
           {
            cout << "no points within range" << endl;
           }
            /////// End of the RANGE command ///////
        }

        else if (command == "NUM") // NUM command is entered //
        { 
           cout << num << endl;
            /////// End of the NUM command ///////
        }

        else if (command == "EXIT") // EXIT command is entered //
        { 
           break;
            /////// End of the EXIT command ///////
        }
    }
}
//////////////////////////////////////////////////////////////////////// MAIN //////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    parse_file();
    return 0;
}
