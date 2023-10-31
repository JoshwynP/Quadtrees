#include <iostream>
#include <string>
#include "Quadtree.h"
using namespace std;

void Quadtree::parse_file()
{
    while (cin >> command) 
    {
///////// INIT command is entered //
        if (command == "INIT") 
        {
            cin >> m >> x0 >> y0 >> x1 >> y1;

            point_array = new Point[m];

            if ( x0 < x1 && y0 < y1 )
            {
                cout << "success" << endl;
            }
            else
            {
                cout << "failure" << endl;
            }
            /////// End of the INIT command ///////
        } 
        
////////// INSERT command is entered //
        else if (command == "INSERT")
        { 
            cin >> X;
            cin >> Y;

            insert(X, Y);

            cout << command << endl;
            /////// End of the INSERT command ///////

        } 
        
////////// SEARCH command is entered //
        else if (command == "SEARCH") 
        {
            

            cout << command << endl;
        } 
////////// End of the SEARCH command ///////

//-----------------------------------------------------------------------//

////////// NEAREST command is entered //
        else if (command == "NEAREST") 
        {
            
            
            cout << command << endl;
            /////// End of the NEAREST command ///////

        }
        
        else if (command == "RANGE") //RANGE command is entered//
        { 
           
           
           cout << command << endl;
            /////// End of the RANGE command ///////
        }

        else if (command == "NUM") // NUM command is entered //
        { 
           
           
           cout << command << endl;
            /////// End of the NUM command ///////
        }

        else if (command == "EXIT") // EXIT command is entered //
        { 
           
           
           cout << command << endl;
           break;
            /////// End of the EXIT command ///////
        }
    }
}


int main()
{
    // string command;
    // int m;
    // double x0;
    // double y0;
    // double x1;
    // double y1;

    // double X;
    // double Y;

    Quadtree tree;
    tree.parse_file();
    
}
