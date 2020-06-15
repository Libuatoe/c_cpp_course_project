
namespace matrix {
    template<typename T, int width, int length>
    class Matrix {
    private:
        int matrixWidth;
        int matrixLength;
    public:
        T data[width][length];

        //矩阵加法
        Matrix operator+(Matrix b) {
            if (this->matrixLength == b.matrixLength && this->matrixWidth == b.matrixWidth) {
                Matrix<T, width, length> result;
                for (int i = 0; i < width; ++i) {
                    for (int j = 0; j < length; ++j) {
                        result.data[i][j] = this->data[i][j] + b.data[i][j];
                    }
                }
                return result;
            } else {

            }
        }

        //矩阵减法
        Matrix operator-(Matrix b) {
            if (this->matrixLength == b.matrixLength && this->matrixWidth == b.matrixWidth) {
                Matrix<T, width, length> result;
                for (int i = 0; i < width; ++i) {
                    for (int j = 0; j < length; ++j) {
                        result.data[i][j] = this->data[i][j] - b.data[i][j];
                    }
                }
                return result;
            } else {

            }
        }

        //乘法
        Matrix operator*(Matrix b) {
            if (this->matrixLength == b.matrixWidth) {
                Matrix<T, width, b.matrixLength> result;
                for (int i = 0; i < width; ++i) {
                    for (int j = 0; j < b.matrixLength; ++j) {
                        result.data[i][j] = 0;
                        for (int k = 0; k < length; ++k) {
                            result.data[i][j] = result.data[i][j] + this->data[i][k] * b.data[k][j];
                        }
                    }
                }
            } else {

            }
        }

        //标量乘法，常数乘矩阵或矩阵乘常数
        friend Matrix operator*(Matrix matrix, T t) {
            Matrix<T, width, length> result;
            for (int i = 0; i < width; ++i) {
                for (int j = 0; j < length; ++j) {
                    result.data[i][j] = matrix.data[i][j] * t;
                }
            }
            return result;
        }

        friend Matrix operator*(T t, Matrix matrix) {
            Matrix<T, width, length> result;
            for (int i = 0; i < width; ++i) {
                for (int j = 0; j < length; ++j) {
                    result.data[i][j] = matrix.data[i][j] * t;
                }
            }
            return result;
        }

        //元素乘法，仅限于两矩阵大小相同的情况
        T elementMultiply(Matrix b) {
            if (this->matrixLength == b.matrixLength && this->matrixWidth == b.matrixWidth) {
                Matrix<T, width, length> result;
                for (int i = 0; i < width; ++i) {
                    for (int j = 0; j < length; ++j) {
                        result.data[i][j] = this->data[i][j] * b.data[i][j];
                    }
                }
                return result;
            } else {

            }
        }

        __unused //找矩阵最大值
        T findMax() {
            T max = this->data[0][0];
            for (int i = 0; i < width; ++i) {
                for (int j = 0; j < length; ++j) {
                    max = max > this->data[i][j] ? max : this->data[i][j];
                }
            }
            return max;
        }

        __unused //找矩阵最小值
        T findMin() {
            T min = this->data[0][0];
            for (int i = 0; i < width; ++i) {
                for (int j = 0; j < length; ++j) {
                    min = min < this->data[i][j] ? min : this->data[i][j];
                }
            }
            return min;
        }

        __unused //求和
        T sum() {
            T sum;
            for (int i = 0; i < width; ++i) {
                for (int j = 0; j < length; ++j) {
                    sum += this->data[i][j];
                }
            }
            return sum;
        }

        //求平均
        __unused T average() {
            T average;
            for (int i = 0; i < width; ++i) {
                for (int j = 0; j < length; ++j) {
                    average += this->data[i][j];
                }
            }
            return average / (width * length);
        }

        __unused //转置
        Matrix transpose() {
            Matrix<T, length, width> result;
            for (int i = 0; i < width; ++i) {
                for (int j = 0; j < length; ++j) {
                    result.data[j][i] = this->data[i][j];
                }
            }
            return result;
        }


    };
}