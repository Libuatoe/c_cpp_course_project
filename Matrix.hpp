
namespace matrix {
    template<typename T, int width, int length>
    class Matrix {
    private:
        int matrixWidth;
        int matrixLength;
    public:
        T data[width][length];
        //无参数构造器，将矩阵中的所有值初始化为T的默认值。
        Matrix() {
            matrixWidth = width;
            matrixLength = length;
            data = new T[matrixWidth][matrixLength];
            for (int i = 0; i < width; ++i) {
                for (int j = 0; j < length; ++j) {
                    data[i][j] = T{};
                }
            }
        }

        static Matrix multiple(const Matrix &a, const Matrix &b){
                Matrix<T,a.matrixWidth,b.matrixLength> result;
                for (int i = 0; i < a.matrixWidth; ++i) {
                    for (int k = 0; k < b.matrixLength; ++k) {
                        for (int j = 0; j < a.matrixLength; ++j) {
                            result.data[i][k] += a.data[i][j] * b.data[j][k];
                        }
                    }
                }
                return result;
        }
    };


}