#ifndef MATRIX4F
#define MATRIX4F
#include "Matrix.hpp"

/**
 *该类继承自Matrix，用以实现小矩阵
 */
namespace matrix{
    template<typename T>
    class Matrix4f:public Matrix<T>{

        Matrix4f():Matrix<T>(4,4) {

        }


        Matrix4f(T arr[]):Matrix<T>(4,4,arr){
        }

    };
}

#endif