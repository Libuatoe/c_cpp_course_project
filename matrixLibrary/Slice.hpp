#include "Matrix.hpp"

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

//这里再写两个切片行或列的方法
