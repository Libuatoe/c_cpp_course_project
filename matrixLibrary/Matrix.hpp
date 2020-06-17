#include "iostream"
#include "vector"

namespace matrix {

    template<typename T>
    class Matrix {
    private:
        int row;
        int column;
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

        //矩阵加法
        Matrix add(Matrix<T> adder);

        Matrix operator+(Matrix<T> b);

        //矩阵减法
        Matrix<T> subtract(Matrix<T> minuend);

        Matrix operator-(Matrix<T> minuend);

        //矩阵乘法
        Matrix<T> operator*(Matrix<T> multiplier);
        Matrix<T> multiple(Matrix<T> multiplier);



        friend Matrix operator/(Matrix matrix, T t);

        friend Matrix operator/(T t, Matrix matrix);

        Matrix<T> scaleMultiple(T t);
        //标量乘法，常数乘矩阵或矩阵乘常数



        friend Matrix operator*(T t, Matrix matrix) {
            Matrix<T> result(matrix.row, matrix.column);
            for (int i = 0; i < matrix.row; ++i) {
                for (int j = 0; j < matrix.column; ++j) {
                    result.data[i][j] = matrix.data[i][j] * t;
                }
            }
            return result;
        }

        friend Matrix<T> operator*(Matrix<T> matrix, T t) {
            Matrix<T> result(matrix.row, matrix.column);
            for (int i = 0; i < matrix.row; ++i) {
                for (int j = 0; j < matrix.column; ++j) {
                    result.data[i][j] = matrix.data[i][j] * t;
                }
            }
            return result;
        }

        friend Matrix operator/(T t, Matrix matrix) {
            Matrix<T> result(matrix.row, matrix.column);
            for (int i = 0; i < matrix.row; ++i) {
                for (int j = 0; j < matrix.column; ++j) {
                    result.data[i][j] = matrix.data[i][j] / t;
                }
            }
            return result;
        }

        friend Matrix operator/(Matrix matrix, T t) {
            Matrix<T> result(matrix.row, matrix.column);
            for (int i = 0; i < matrix.row; ++i) {
                for (int j = 0; j < matrix.column; ++j) {
                    result.data[i][j] = matrix.data[i][j] / t;
                }
            }
            return result;
        }

        //元素乘法，仅限于两矩阵大小相同的情况
        T elementMultiply(Matrix b);

        __unused //找矩阵最大值
        T findMax();

        __unused //找矩阵最小值
        T findMin();


        __unused //求和
        T sum();

        //求平均
        T average();


        __unused //转置
        Matrix transpose();

        std::vector<T> &operator[](int i) {
            return data[i];
        }

        void showMatrix() {
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {
                    std::cout << data[i][j] << " ";
                }
                std::cout << "\n";
            }
        }

        Matrix<T> slice(int x1, int y1, int x2, int y2);

        Matrix<T> sliceRow(int rowNum);

        Matrix<T> sliceColumn(int columnNum);

        void reshape(int newRow, int newColumn);

        Matrix convolution(Matrix kernel);
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