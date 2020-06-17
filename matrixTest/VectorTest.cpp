
#include <iostream>
#include "../matrixLibrary/RowVector.hpp"
#include "../matrixLibrary/ColumnVector.hpp"

using namespace matrix;
using namespace std;

int main() {
    double arr1[] = {1, 2, 3};
    double arr2[] = {3, 2, 1};
    cout << "初始化一个大小为 3 * 1的列向量，其内容为:" << endl;
    ColumnVector<double> columnVector1(3, arr1);
    columnVector1.showMatrix();
    cout << "初始化一个大小为 1 * 3的行向量，其内容为:" << endl;
    RowVector<double> rowVector1(3, arr2);
    rowVector1.showMatrix();

    cout << "columnVector1 * rowVector1 的结果为:" << endl;
    (columnVector1 * rowVector1).showMatrix();
    cout << "rowVector1 * columnVector1 的结果为:" << endl;
    (rowVector1 * columnVector1).showMatrix();

}
