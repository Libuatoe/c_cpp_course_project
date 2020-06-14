
namespace matrix {
    template<typename T, int width, int length>
    class Matrix {
    private:
        int matrixWidth;
        int matrixLength;
    public:
        T data[width][length];

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
    };
}