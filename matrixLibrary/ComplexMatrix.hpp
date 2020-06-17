//
// Created by ZYFtuo on 2020/6/17.
//

#ifndef PROJECT_COMPLEXMATRIX_HPP
#define PROJECT_COMPLEXMATRIX_HPP

#include "Matrix.hpp"
#include "complex"


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


