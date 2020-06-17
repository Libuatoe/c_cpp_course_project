cmake_minimum_required(VERSION 3.16)
project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(sqr_matrix SqrMatrixTest.cpp matrixLibrary/Matrix.hpp matrixLibrary/SqrMatrix.hpp SqrMatrixTest.cpp matrixLibrary/RowVector.hpp RowVectorTest.cpp)
add_executable(row_vector RowVectorTest.cpp matrixLibrary/RowVector.hpp)
add_executable(column_vector matrixLibrary/ColumnVector.hpp ColumnVectorTest.cpp)
add_executable(Reshape matrixLibrary/Reshape.cpp)
add_executable(Slice matrixLibrary/Slice.hpp SliceTest.cpp matrixLibrary/Matrix4f.hpp)
add_executable(spare_matrix matrixLibrary/SparseMatrix.cpp)
add_executable(matrix_arithmetic matrixLibrary/MatrixArithmetic.hpp)
