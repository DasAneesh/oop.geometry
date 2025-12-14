#include <iostream>
#include "Shapes.h"

using namespace std;


int main() {

    Circle c(Point(0, 0), 3);
    cout << c.area();
    return 0;
}