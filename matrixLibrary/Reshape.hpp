#ifndef RESHAPE
#define RESHAPE
# include "Matrix.hpp"

//this function reshape matrix with the new size.
template<typename T>
void matrix::Matrix<T>::reshape(int newRow, int newColumn) {
    if (this->row * this->column != newRow * newColumn) {
        std::cout << "Cannot reshape the matrix since the size is not match." << std::endl;
        return;
    }
    std::vector<std::vector<T>> newData;
    newData.resize(newRow);
    for (int i = 0; i < newRow; ++i) {
        newData[i].resize(column);
    }
    std::vector<T> num;
    num.resize(this->row * this->column);
    int numCounter = 0;
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->column; ++j) {
            num[numCounter] = this->data[i][j];
            ++numCounter;
        }
    }
    numCounter = 0;

    for (int i = 0; i < newRow; ++i) {
        for (int j = 0; j < newColumn; ++j) {
            newData[i][j] = num[numCounter];
            ++numCounter;
        }
    }
    this->data = newData;
}
#endif