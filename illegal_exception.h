#include <iostream>
#include <string>
using namespace std;

class illegal_exception
{
    private:
    string exception_message;

    public:
    illegal_exception();
    string exception(int x0, int y0, int x1, int y1);
};