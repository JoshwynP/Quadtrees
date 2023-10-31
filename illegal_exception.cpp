#include <iostream>
#include <string>
#include "illegal_exception.h"
using namespace std;

illegal_exception::illegal_exception(): exception_message ("illegal argument") 
{
    
}
string illegal_exception::exception(int x0, int y0, int x1, int y1)
{
    if (x0 > x1 || y0 > y1) 
    {
        throw illegal_exception();
    } 
}