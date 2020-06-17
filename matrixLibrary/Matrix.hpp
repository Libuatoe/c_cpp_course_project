#ifndef MATRIX
#define MATRIX

#include <complex.h>
#include "iostream"
#include "vector"

/**
 *该类是其他类的父类，里面有数值运算，运算符重载等基础方法。
 * 有多种形式的构造器方法和get、set方法
 */
namespace matrix {

    template<typename T>
    class Matrix {
    private:
        int row{};
        int column{};
    public:

        std::vector<std::vector<T>> data;

        Matrix(int row, int column) {
            this->row = row;
            this->column = column;
            initial();
        }

        void initial() {
            this->data.resize(row);
            for (int i = 0; i < row; ++i) {
                this->data[i].resize(column);
            }
        }

        explicit Matrix(int row, int column, T arr[]) : Matrix(row, column) {
            setMatrix(arr);
        }

        void setMatrix(T arr[]) {
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    data[i][j] = arr[i * column + j];
                }
            }
        };


        //矩阵乘法方法的实现
        Matrix<T> multiple(matrix::Matrix<T> multiplier) {
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
        Matrix<T> operator*(matrix::Matrix<T> multiplier) {
            return multiple(multiplier);
        }


        //标量乘法
        Matrix<T> scaleMultiple(T t) {
            Matrix<T> result(row, column);
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    result.data[i][j] = data[i][j] * t;
                }
            }
            return result;
        }

        /**加法运算的实现
         *包括一个加法方法，返回相加后的矩阵
         * 以及一个加号运算符的重载
        */
        Matrix<T> add(Matrix<T> adder) {
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
        Matrix<T> operator+(matrix::Matrix<T> adder) {
            return add(adder);
        }

        //赋值运算符的重载
        Matrix<T> &operator=(const Matrix<T> &matrix1) {
            row = matrix1.row;
            column = matrix1.column;
            data = matrix1.data;
            return *this;
        }

        friend Matrix operator*(T t, Matrix matrix) {
            Matrix<T> result(matrix.row, matrix.column);
            for (int i = 0; i < matrix.row; ++i) {
                for (int j = 0; j < matrix.column; ++j) {
                    result.data[i][j] = matrix.data[i][j] * t;
                }
            }
            return result;
        }

        //乘法运算符的重载
        friend Matrix<T> operator*(Matrix<T> matrix, T t) {
            Matrix<T> result(matrix.row, matrix.column);
            for (int i = 0; i < matrix.row; ++i) {
                for (int j = 0; j < matrix.column; ++j) {
                    result.data[i][j] = matrix.data[i][j] * t;
                }
            }
            return result;
        }


        //除法
        friend Matrix<T> operator/(Matrix<T> matrix, T t) {
            Matrix<T> result(matrix.row, matrix.column);
            for (int i = 0; i < matrix.row; ++i) {
                for (int j = 0; j < matrix.column; ++j) {
                    result.data[i][j] = matrix.data[i][j] / t;
                }
            }
            return result;
        }


        /**减法运算的实现
         *包括一个减法方法，返回减去后的矩阵
         * 以及一个减号运算符的重载
        */
        Matrix<T> subtract(Matrix<T> minuend) {
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
        Matrix<T> operator-(matrix::Matrix<T> minuend) {
            return subtract(minuend);
        }


        //阿达玛乘积的实现
        Matrix<T> elementMultiply(Matrix<T> b) {
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
        T findMax() {
            T max = this->data[0][0];
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    max = max > this->data[i][j] ? max : this->data[i][j];
                }
            }
            return max;
        }

        //求矩阵中的局部最大元素，限定行和列
        T findMax(int loRow, int loCol, int upRow, int upCol) {
            T max = this->data[0][0];
            for (int i = loRow; i < upRow; ++i) {
                for (int j = loCol; j < upCol; ++j) {
                    max = max > this->data[i][j] ? max : this->data[i][j];
                }
            }
            return max;
        }

        //求矩阵中的最小元素
        T findMin() {
            T min = this->data[0][0];
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    min = min < this->data[i][j] ? min : this->data[i][j];
                }
            }
            return min;
        }

        //求矩阵中的局部最小元素，限定行和列
        T findMin(int loRow, int loCol, int upRow, int upCol) {
            T min = this->data[0][0];
            for (int i = loRow; i < upRow; ++i) {
                for (int j = loCol; j < upCol; ++j) {
                    min = min < this->data[i][j] ? min : this->data[i][j];
                }
            }
            return min;
        }

        //求矩阵的平均值
        T average() {
            T average;
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    average += this->data[i][j];
                }
            }
            return average / (row * column);
        }

        //求矩阵中的局部平均值，限定行和列
        T average(int loRow, int loCol, int upRow, int upCol) {
            T average;
            for (int i = loRow; i < upRow; ++i) {
                for (int j = loCol; j < upCol; ++j) {
                    average += this->data[i][j];
                }
            }
            return average / ((upRow - loRow) * (upCol - loCol));
        }

        //求矩阵中所有元素的和
        T sumAll() {
            T sum;
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    sum += this->data[i][j];
                }
            }
            return sum;
        }


        //求该矩阵的转置，返回转置后的矩阵
        Matrix<T> transpose() {
            Matrix<T> result(this->column, this->row);
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    result.data[j][i] = this->data[i][j];
                }
            }
            return result;
        }

        //[]运算符重载
        std::vector<T> &operator[](int i) {
            return data[i];
        }

        //show方法，输出矩阵中的所有数据
        void showMatrix() {
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    std::cout << data[i][j] << " ";
                }
                std::cout << "\n";
            }
        }

        //以下是slice、sliceRow、sliceColumn方法的定义
        Matrix<T> slice(int x1, int y1, int x2, int y2);

        Matrix<T> sliceRow(int rowNum);

        Matrix<T> sliceColumn(int columnNum);

        //整形方法的定义
        void reshape(int newRow, int newColumn);

        //矩阵的卷积方法的定义
        Matrix convolution(Matrix kernel);

        //矩阵的三个set方法
        void setRow(int setRow) {
            this->row = setRow;
        }

        void setColumn(int setColumn) {
            this->column = column;
        }

        void setData(const std::vector<std::vector<T>> &setData) {
            this->data = setData;
        }
    };


}
#endif