cmake_minimum_required(VERSION 3.16)
project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(sqr_matrix matrixLibrary/Matrix.hpp matrixLibrary/SqrMatrix.hpp matrixTest/SqrMatrixTest.cpp )
add_executable(row_vector matrixTest/RowVectorTest.cpp matrixLibrary/RowVector.hpp)
add_executable(column_vector matrixLibrary/ColumnVector.hpp matrixTest/ColumnVectorTest.cpp)
add_executable(Reshape matrixLibrary/Reshape.cpp)
add_executable(Slice matrixLibrary/Slice.hpp matrixTest/SliceTest.cpp matrixLibrary/Matrix4f.hpp)
add_executable(spare_matrix matrixLibrary/SparseMatrix.cpp)
add_executable(matrix matrixLibrary/Matrix.hpp matrixTest/MatrixTest.cpp)
add_executable(matrix_convolution matrixLibrary/MatrixConvolution.hpp matrixTest/MatrixConvolutionTest.cpp)
