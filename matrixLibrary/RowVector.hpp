#ifndef ROW_VECTOR
#define ROW_VECTOR
#include "Matrix.hpp"

/**
 *该类继承自Matrix，用以实现行向量
 */
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
