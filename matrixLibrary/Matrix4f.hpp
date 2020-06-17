#include "Matrix.hpp"

namespace matrix{
    template<typename T>
    class Matrix4f:public Matrix<T>{

        Matrix4f():Matrix<T>(4,4) {

        }


        Matrix4f(T arr[]):Matrix<T>(4,4,arr){
        }


    };
}