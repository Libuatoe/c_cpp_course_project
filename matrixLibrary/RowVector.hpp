#ifndef ROW_VECTOR
#define ROW_VECTOR
#include "Matrix.hpp"

namespace matrix {
    template<typename T>
    class RowVector : public Matrix<T> {
    private:
        int column;
    public:
        RowVector(int column, T arr[]) : Matrix<T>(1, column, arr) {
            this->column = column;
        }

        RowVector(int column) : Matrix<T>(1, column) {
            this->column = column;
        }
    };
}
#endif
