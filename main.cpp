#include <iostream>
#include "Matrix.hpp"
using namespace matrix;
int main() {
    //test multiple
Matrix<int,2,1> a;
a.data[0][0] = 1;
a.data[1][0] = 2;
Matrix<int,1,2> b;
b.data[0][0] = 3;
b.data[0][1] = 4;


}
