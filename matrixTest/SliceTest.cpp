#include <iostream>
#include "../matrixLibrary/Slice.hpp"

using namespace matrix;
using namespace std;

int main() {
    //新建一个4*5的矩阵进行测试
    double array1[] = {1, 2, 3, 4, 5,
                       6, 7, 8, 9, 10,
                       11, 12, 13, 14, 15,
                       16, 17, 18, 19, 20};

    Matrix<double> matrix1(4, 5, array1);

    cout<<"原矩阵的内容为:"<<endl;
    matrix1.showMatrix();
    Matrix<double> matrix2 = matrix1.slice(1, 1, 3, 2);

    cout<<"切下（1，1）到（3，2）后,得到的新矩阵的内容为"<<endl;
    matrix2.showMatrix();

    cout<<"切下第一行，得到一个新矩阵的内容为:"<<endl;
    Matrix<double> matrix3 = matrix1.sliceRow(1);
    matrix3.showMatrix();

    cout<<"切下第二列，得到一个新矩阵的内容为:"<<endl;
    Matrix<double> matrix4 = matrix1.sliceColumn(2);
    matrix4.showMatrix();
}

