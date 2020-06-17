//
// Created by ZYFtuo on 2020/6/17.
//

#ifndef PROJECT_COMPLEXMATRIX_HPP
#define PROJECT_COMPLEXMATRIX_HPP

#include "Matrix.hpp"
#include "complex"

/**
 *该类继承自Matrix，用以实现复数矩阵中的共轭算法。
 * 复数矩阵中的其他方法均在父类Matrix中实现
 */
namespace matrix {
    template<typename T>
    class Complex : public Matrix<T> {
    private:
        int row;
        int column;
    public:
        Complex(int row, int column, std::complex<T> arr[]) : Matrix<std::complex<T>>(row, column, arr) {
            this->row = row;
            this->column = column;
        }

        Complex conjugate() {
            this->data = conj(this->data);
            return this;
        }
    };
}

#endif //PROJECT_COMPLEXMATRIX_HPP


