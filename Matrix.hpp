
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
    };
}