#include "Matrix.hpp"

template<typename T>

/*减法运算的实现
 *包括一个减法方法，返回减去后的矩阵
 * 以及一个减号运算符的重载
*/
matrix::Matrix<T> matrix::Matrix<T>::subtract(matrix::Matrix<T> minuend) {
    if (this->column == minuend.column && this->row == minuend.row) {
        Matrix<T> answer(this->row, this->column);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                answer.data[i][j] = this->data[i][j] - minuend.data[i][j];
            }
        }
        return answer;
    } else {
    }
}

//减号运算符的重载
template<typename T>
matrix::Matrix<T> matrix::Matrix<T>::operator-(matrix::Matrix<T> minuend) {
    return subtract(minuend);
}

/*加法运算的实现
 *包括一个加法方法，返回相加后的矩阵
 * 以及一个加号运算符的重载
*/
template<typename T>
matrix::Matrix<T> matrix::Matrix<T>::add(Matrix<T> adder) {
    if (this->column == adder.column && this->row == adder.row) {
        Matrix<T> result(this->row, this->column);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                result.data[i][j] = this->data[i][j] + adder.data[i][j];
            }
        }
        return result;
    } else {
    }
}


//加法运算符的重载
template<typename T>
matrix::Matrix<T> matrix::Matrix<T>::operator+(matrix::Matrix<T> adder) {
    return add(adder);
}


//矩阵乘法方法的实现
template<typename T>
matrix::Matrix<T> matrix::Matrix<T>::multiple(matrix::Matrix<T> multiplier) {
    if (this->column == multiplier.row) {
        Matrix<T> result(this->row, multiplier.column);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < multiplier.column; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < column; ++k) {
                    result.data[i][j] = result.data[i][j] + this->data[i][k] * multiplier.data[k][j];
                }
            }
        }
        return result;
    } else {

    }
}

//乘法运算符的重载
template<typename T>
matrix::Matrix<T> matrix::Matrix<T>::operator*(matrix::Matrix<T> multiplier) {
    return multiple(multiplier);
}

//标量乘法
template<typename T>
matrix::Matrix<T> matrix::Matrix<T>::scaleMultiple(T t) {
    Matrix<T> result(row, column);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            result.data[i][j] = data[i][j] * t;
        }
    }
    return result;
}

//阿达玛乘积
template<typename T>
T matrix::Matrix<T>::elementMultiply(matrix::Matrix<T> b) {
    if (this->column == b.column && this->row == b.row) {
        Matrix<T> result(this->row, this->column);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                result.data[i][j] = this->data[i][j] * b.data[i][j];
            }
        }
        return result;
    } else {

    }
}

//求矩阵中的最大元素
template<typename T>
T matrix::Matrix<T>::findMax() {
    T max = this->data[0][0];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            max = max > this->data[i][j] ? max : this->data[i][j];
        }
    }
    return max;
}

//求矩阵中的最小元素
template<typename T>
T matrix::Matrix<T>::findMin() {
    T min = this->data[0][0];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            min = min < this->data[i][j] ? min : this->data[i][j];
        }
    }
    return min;
}

//求矩阵的平均值
template<typename T>
T matrix::Matrix<T>::average() {
    T average;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            average += this->data[i][j];
        }
    }
    return average / (row * column);
}

//求矩阵中所有元素的和
template<typename T>
T matrix::Matrix<T>::sum() {
    T sum;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            sum += this->data[i][j];
        }
    }
    return sum;
}


//求该矩阵的转置，返回转置后的矩阵
template<typename T>
matrix::Matrix<T> matrix::Matrix<T>::transpose() {
    Matrix<T> result(this->column, this->row);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            result.data[j][i] = this->data[i][j];
        }
    }
    return result;
}
