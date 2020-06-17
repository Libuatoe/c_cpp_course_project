cmake_minimum_required(VERSION 3.16)
project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(sqr_matrix matrixLibrary/Matrix.hpp matrixLibrary/SqrMatrix.hpp matrixTest/SqrMatrixTest.cpp)
add_executable(vector matrixTest/VectorTest.cpp matrixLibrary/RowVector.hpp)
add_executable(Reshape matrixLibrary/Reshape.hpp)
add_executable(slice matrixLibrary/Slice.hpp matrixTest/SliceTest.cpp matrixLibrary/Matrix4f.hpp)
add_executable(spare_matrix matrixLibrary/SparseMatrix.hpp)
add_executable(matrix matrixLibrary/Matrix.hpp matrixTest/MatrixTest.cpp)
add_executable(matrix_convolution matrixLibrary/MatrixConvolution.hpp matrixTest/MatrixConvolutionTest.cpp)
add_executable(reshape matrixLibrary/Reshape.hpp matrixTest/ReshapeTest.cpp)
add_executable(complex matrixLibrary/ComplexMatrix.hpp)
