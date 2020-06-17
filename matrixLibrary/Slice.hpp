#ifndef SLICE
#define SLICE
#include "Matrix.hpp"

/**
 *该类继承自Matrix，可以从行列两个方向对矩阵进行切片
 */
//Slice a submatrix with coordinate
//x1 y1 for left upper , x2 y2 for right bottom
template<typename T>
matrix::Matrix<T> matrix::Matrix<T>::slice(int x1, int y1, int x2, int y2) {
    int newRow = x2 - x1 + 1;
    int newColumn = y2 - y1 + 1;
    matrix::Matrix<T> ans(newRow, newColumn);
    for (int i = 0; i < newRow; ++i) {
        for (int j = 0; j < newColumn; ++j) {
            ans[i][j] = this->data[x1 + i][y1 + j];
        }
    }
    return ans;
}


//这个方法切下一个行向量矩阵
template<typename T>
matrix::Matrix<T> matrix::Matrix<T>::sliceRow(int rowNum) {
    std::vector<T> vec = this->data[rowNum];
    matrix::Matrix<T> ans(1, this->column);
    ans.data[0] = vec;
    return ans;
}


//这个方法切下一个列向量矩阵
template<typename T>
matrix::Matrix<T> matrix::Matrix<T>::sliceColumn(int columnNum) {
    matrix::Matrix<T> ans(this->row, 1);
    for (int i = 0; i < this->row; ++i) {
        ans[i][0] = this->data[i][columnNum];
    }
    return ans;
}

#endif
















