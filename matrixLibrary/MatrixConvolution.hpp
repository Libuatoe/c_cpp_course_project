#ifndef MATRIX_CONVOLUTION
#define MATRIX_CONVOLUTION
#include "Matrix.hpp"


template<typename T>
matrix::Matrix<T> matrix::Matrix<T>::convolution(matrix::Matrix<T> kernel) {
        int mid = (kernel.column - 1) / 2;
        int temp;
        Matrix<T> result(row, column);
        int kLength = kernel.column;
        int kWidth = kernel.row;

        for (int i = 0; i < kLength + column - 1; i++) {
            for (int j = 0; j < kWidth + row - 1; j++) {
                temp = 0;
                for (int m = 0; m < kLength; m++) {
                    for (int n = 0; n < kWidth; n++) {
                        if ((i - m) >= 0 && (i - m) < column && (j - n) >= 0 && (j - n) < row) {
                            temp += kernel[m][n] * this->data[i - m][j - n];
                        }
                    }
                }
                result[i][j] = temp;
            }
        }
        return result;
}
#endif