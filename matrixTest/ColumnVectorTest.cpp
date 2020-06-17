
#include "../matrixLibrary/ColumnVector.hpp"

using namespace matrix;
using namespace std;

int main(){
    double arr1[] = {1,2,3};
    double arr2[] = {3,2,1};
    Matrix<double> matrix1(1,3, arr1);
    ColumnVector<double> columnVector1(3, arr2);
    Matrix<double> answer1 =   matrix1.multiple(columnVector1);
    answer1.showMatrix();
}
