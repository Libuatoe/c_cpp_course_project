#include "Matrix.hpp"

template<typename T>
struct triple {
    int rowCoo; //行坐标
    int colCoo; //列坐标
    T value;
};

template<typename T>
class SparseMatrix {
    int size{};
    int row{}; //行数
    int column{}; //列数
    std::vector<triple<T>> data;

public:

    explicit SparseMatrix(int size, int row, int column) :SparseMatrix(row,column){
        this->size = size;
        this->row = row;
        this->column = column;
        data.resize(size);
    }

    SparseMatrix(int row, int column) {
        this->row = row;
        this->column = column;
    }

    SparseMatrix(int size, int row, int column, triple<T> arr[]) : SparseMatrix(row, column) {
        this->column = column;
        data.resize(size);
        for (int i = 0; i < size; ++i) {
            data[i] = arr[i];
        }
    }

    SparseMatrix(int size, int row, int column, std::vector<triple<T>> arr[]) : SparseMatrix(row, column) {
        this->size = size;
        data.resize(size);
        for (int i = 0; i < size; ++i) {
            data[i] = arr[i];
        }
    }

    //将稀疏矩阵转化为稠密矩阵
    matrix::Matrix<T> toMatrix(){
        matrix::Matrix<T> ans;
        ans.setRow(row);
        ans.setColumn(column);
        std::vector<std::vector<T>> newData;
        newData.resize(row);
        for (int i = 0; i < row; ++i) {
            newData[i].resize(column);
        }

        for (int i = 0; i < data.size(); ++i) {
            int x = data[i].rowCoo;
            int y = data[i].colCoo;
            T z = data[i].value;
            newData[x][y] = z;
        }

        ans.setMatrix(newData);
        return ans;
    }

};



