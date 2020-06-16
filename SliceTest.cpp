#include <iostream>
#include "matrixLibrary/Slice.hpp"

using namespace matrix;
using namespace std;

int main() {
    //新建一个4*5的矩阵进行测试
    double array1[] = {1, 2, 3, 4, 5,
                       6, 7, 8, 9, 10,
                       11, 12, 13, 14, 15,
                       16, 17, 18, 19, 20};

    Matrix<double> matrix1(4, 5, array1);
    cout << matrix1[1][1]<<" "<<matrix1[1][2]<<endl;
    cout << matrix1[2][1]<<" "<<matrix1[2][2]<<endl;
    cout << matrix1[3][1]<<" "<<matrix1[3][2]<<endl;
    Matrix<double> matrix2 = matrix1.slice(1, 1, 3, 2);
    matrix2.showMatrix();
}

