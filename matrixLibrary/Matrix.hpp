#ifndef MATRIX
#define MATRIX

#include <complex.h>
#include "iostream"
#include "vector"

/**
 * 使用名为matrix的命名空间来调用所有的函数
 */
namespace matrix {

    /**
     * 这是最基础的矩阵类Matrix类
     * 使用类模板参数来确定矩阵数据类型
     * 模板参数支持所有基础数据类型以及std::complex类型
     * 该类共有三个属性，包括一个行向量数，一个列向量数，一个二维vector用来储存具体的矩阵
     * 该库中ColumnVector类，RowVector类，Matrix4f类，ComplexMatrix类，SqrMatrix类均派生自此类
     * @tparam T
     */
    template<typename T>
    class Matrix {
    private:
        int row{};
        int column{};
    public:

        std::vector<std::vector<T>> data;


        /**
         * 最基础的构造器，传入矩阵的行数和列数，
         * 矩阵内容被初始化为具体类型的默认值
         * @param row
         * @param column
         */
        Matrix(int row, int column) {
            this->row = row;
            this->column = column;
            initial();
        }

        /**
         * 这是初始化函数
         * 用于初始化data这个二维vector
         * 其中所有的值被初始化为T类型的默认值
         */
        void initial() {
            this->data.resize(row);
            for (int i = 0; i < row; ++i) {
                this->data[i].resize(column);
            }
        }

        /**
         * 这个构造器在基础构造器的基础上传入一个row * column大小的数组
         * 数组中的值用于初始化矩阵
         * 若矩阵大小不匹配，则不进行初始化，并且在控制台输出错误提示
         * @param row
         * @param column
         * @param arr
         */
        explicit Matrix(int row, int column, T arr[]) : Matrix(row, column) {
            setMatrix(arr);
        }

        /**
         * 这是data二维vector的setter方法,
         * 可以被上述构造器复用来构造矩阵
         * @param arr
         */
        void setMatrix(T arr[]) {
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    data[i][j] = arr[i * column + j];
                }
            }
        };


        /**
         * @param multiplier(一个与原矩阵大小相同的Matrix类型的矩阵)
         * @return Matrix类型的矩阵，内容为叉乘后的结果
         * 若是矩阵大小不匹配，则无法进行乘积，直接返回原矩阵
         **/
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
                std::cout << "The matrices size do not match each other." << std::endl;
                return &this;
            }
        }

        /**
         * @param multiplier
         * @return Matrix<T>
         * 这里对 * 运算符进行了重载，调用multiple函数
         * 类似 matrix1 * matrix2 运算将直接返回一个矩阵的实例
         */
        Matrix<T> operator*(matrix::Matrix<T> multiplier) {
            return multiple(multiplier);
        }


        /**
         *
         * @param t
         * @return  Matrix<T>
         * 这是标量乘法，传入一个T类型的值，与矩阵相乘后返回结果矩阵
         */
        Matrix<T> scaleMultiple(T t) {
            Matrix<T> result(row, column);
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    result.data[i][j] = data[i][j] * t;
                }
            }
            return result;
        }


        /**
         * @param adder
         * @return Matrix<T>
         * 这里实现了加法运算，传入一个相同大小的矩阵
         * 返回相加过后的结果矩阵
         * 若是相加不成功，则输出错误提示，然后直接返回原矩阵
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
                std::cout << "The size of adder and origin matrix do not match." << std::endl;
                return &this;
            }
        }

        /**
         * 这里重载了加法运算符
         * 调用上述加法函数
         * @param adder
         * @return
         */
        Matrix<T> operator+(matrix::Matrix<T> adder) {
            return add(adder);
        }

        /**
         * 这里重载了赋值运算符
         * 决定了Matrix类的直接赋值
         * 返回的矩阵类型的实例可以被直接赋值到一个声明的Matrix实例中
         * @param matrix1
         * @return
         */
        Matrix<T> &operator=(const Matrix<T> &matrix1) {
            row = matrix1.row;
            column = matrix1.column;
            data = matrix1.data;
            return *this;
        }

        /**
         * 重载了与t类型标量的乘法运算符
         * @param t
         * @param matrix
         * @return
         */
        friend Matrix operator*(T t, Matrix matrix) {
            Matrix<T> result(matrix.row, matrix.column);
            for (int i = 0; i < matrix.row; ++i) {
                for (int j = 0; j < matrix.column; ++j) {
                    result.data[i][j] = matrix.data[i][j] * t;
                }
            }
            return result;
        }

        /**
         * 重载了与t类型标量的乘法运算符（与上一重载顺序不同）
         * @param matrix
         * @param t
         * @return
         */
        friend Matrix<T> operator*(Matrix<T> matrix, T t) {
            Matrix<T> result(matrix.row, matrix.column);
            for (int i = 0; i < matrix.row; ++i) {
                for (int j = 0; j < matrix.column; ++j) {
                    result.data[i][j] = matrix.data[i][j] * t;
                }
            }
            return result;
        }


        /**
         * 重载了除法运算符，可以直接使用除法运算符与标量进行除法运算
         * @param matrix
         * @param t
         * @return
         */
        friend Matrix<T> operator/(Matrix<T> matrix, T t) {
            Matrix<T> result(matrix.row, matrix.column);
            for (int i = 0; i < matrix.row; ++i) {
                for (int j = 0; j < matrix.column; ++j) {
                    result.data[i][j] = matrix.data[i][j] / t;
                }
            }
            return result;
        }


        /**
         * 这里实现了减法方法
         * 传入一个被减的矩阵，返回减运算过后的矩阵
         * @param minuend
         * @return
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
                std::cout << "The size of matrices do not match." << std::endl;
                return &this;
            }
        }

        /**
         * 重载了 - 运算符
         * 直接调用subtract函数
         * @param minuend
         * @return
         */
        Matrix<T> operator-(matrix::Matrix<T> minuend) {
            return subtract(minuend);
        }

        /**
         * 矩阵的点乘(阿达玛乘积)
         * 传入一个Matrix<T>类型的矩阵
         * 返回乘积运算过后的矩阵
         * @param b
         * @return
         */
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


        /**
         * 返回矩阵中元素的最大值
         * @return
         */
        T findMax() {
            T max = this->data[0][0];
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    max = max > this->data[i][j] ? max : this->data[i][j];
                }
            }
            return max;
        }

        /**
         * 给定具体的坐标
         * 返回具体的轴相关的最大值
         * axis-specific
         * @param loRow
         * @param loCol
         * @param upRow
         * @param upCol
         * @return
         */
        T findMax(int loRow, int loCol, int upRow, int upCol) {
            T max = this->data[0][0];
            for (int i = loRow; i < upRow; ++i) {
                for (int j = loCol; j < upCol; ++j) {
                    max = max > this->data[i][j] ? max : this->data[i][j];
                }
            }
            return max;
        }

        /**
         * 返回矩阵中元素的最小值
         * @return
         */

        T findMin() {
            T min = this->data[0][0];
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    min = min < this->data[i][j] ? min : this->data[i][j];
                }
            }
            return min;
        }

        /**
         * 根据传入的指定的坐标区间
         * 返回对应轴相关的最小值
         * axis-specific
         * @param loRow
         * @param loCol
         * @param upRow
         * @param upCol
         * @return
         */
        T findMin(int loRow, int loCol, int upRow, int upCol) {
            T min = this->data[0][0];
            for (int i = loRow; i < upRow; ++i) {
                for (int j = loCol; j < upCol; ++j) {
                    min = min < this->data[i][j] ? min : this->data[i][j];
                }
            }
            return min;
        }

        /**
         * 返回矩阵中所有元素的平均值
         * @return
         */
        T average() {
            T average;
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    average += this->data[i][j];
                }
            }
            return average / (row * column);
        }


        /**
         * 根据参数坐标，返回指定参数范围内的轴相关矩阵的平均值
         * @param loRow
         * @param loCol
         * @param upRow
         * @param upCol
         * @return
         */
        T average(int loRow, int loCol, int upRow, int upCol) {
            T average;
            for (int i = loRow; i < upRow; ++i) {
                for (int j = loCol; j < upCol; ++j) {
                    average += this->data[i][j];
                }
            }
            return average / ((upRow - loRow) * (upCol - loCol));
        }

        /**
         * 对矩阵中所有元素进行求和
         * 返回这个和值
         * @return
         */
        T sumAll() {
            T sum;
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    sum += this->data[i][j];
                }
            }
            return sum;
        }


        /**
         * 矩阵的转置函数
         * 调用过后直接返回转置矩阵
         * @return
         */
        Matrix<T> transpose() {
            Matrix<T> result(this->column, this->row);
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    result.data[j][i] = this->data[i][j];
                }
            }
            return result;
        }

        /**
         * 重载[] 运算符
         * 用户可以使用类似 matrix[1][2] 的代码来直接访问矩阵的具体值
         * @param i
         * @return
         */
        std::vector<T> &operator[](int i) {
            return data[i];
        }

        /**
         * 这个函数在控制台输出矩阵的所有元素
         */
        void showMatrix() {
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    std::cout << data[i][j] << " ";
                }
                std::cout << "\n";
            }
        }

        /**
         * 用于切片的函数，具体在 Slice.hpp 中实现
         * @param x1
         * @param y1
         * @param x2
         * @param y2
         * @return
         */
        Matrix<T> slice(int x1, int y1, int x2, int y2);

        /**
         * 用于切片的函数，具体在 Slice.hpp 中实现
         * @param rowNum
         * @return
         */
        Matrix<T> sliceRow(int rowNum);

        /**
         * 用于切片的函数，具体在 Slice.hpp 中实现
         * @param columnNum
         * @return
         */
        Matrix<T> sliceColumn(int columnNum);

        /**
         * 用于实现矩阵重塑的函数，具体在Reshape.hpp中实现
         * @param newRow
         * @param newColumn
         */
        void reshape(int newRow, int newColumn);

        /**
         * 矩阵的卷积运算函数，具体在MatrixConvolution.hpp 中实现
         * @param kernel
         * @return
         */
        Matrix convolution(Matrix kernel);

        /**
         * row属性的setter
         * @param setRow
         */
        void setRow(int setRow) {
            this->row = setRow;
        }

        /**
         * column属性的setter
         * @param setColumn
         */
        void setColumn(int setColumn) {
            this->column = column;
        }

        /**
         * data属性的setter
         * @param setData
         */
        void setData(const std::vector<std::vector<T>> &setData) {
            this->data = setData;
        }
    };


}
#endif