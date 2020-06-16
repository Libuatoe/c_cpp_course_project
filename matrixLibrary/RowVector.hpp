#include "Matrix.hpp"

namespace matrix {
    template<typename T>
    class ColumnVector : public Matrix<T> {
    private:
        int column;
    public:
        ColumnVector(int column, T arr[]) : Matrix<T>(1, column, arr) {
            this->column = column;
        }

        ColumnVector(int column) : Matrix<T>(1, column) {
            this->column = column;
        }
    };
}
