#include "Matrix.hpp"
#include "vector"
#include "math.h"

namespace matrix {

    template<typename T, int width>
    class SqrMatrix : public Matrix<T, width, width> {
    private:
    public:
        SqrMatrix() {
            Matrix<T, width, width>();
        }

        explicit SqrMatrix(T arr[]) : Matrix<T, width, width>(arr) {
        }

//计算矩阵的迹
        T trace() {
            T ans = 0;
            for (int i = 0; i < width; ++i) {
                Matrix<T, width, width> tmp = *this;
                ans += tmp(i, i);
            }
            return ans;
        }

//计算矩阵的行列式
        T getDeterminant() {
            std::vector<std::vector<T>> arr(width, std::vector<T>(width));
            for (int i = 0; i < width; ++i) {
                for (int j = 0; j < width; ++j) {
                    arr[i][j] = this->data[i][j];
                }
            }
            return det(arr, width);
        }

        static T det(const std::vector<std::vector<T>> arr, int layer) {
            T ans{0};
            if (layer == 1) {
                return arr[0][0];
            }
            if (layer == 2) {
                return (arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0]);
            } else {
                for (int cnt2 = 0; cnt2 < layer; ++cnt2) {
                    std::vector<std::vector<T>> tmp(layer - 1);
                    std::vector<int> spand;
                    for (int cnt1 = 0; cnt1 < layer; ++cnt1) {
                        if (cnt2 != cnt1) {
                            spand.push_back(cnt1);
                        }
                    }
                    for (int i = 0; i < layer - 1; ++i) {
                        tmp[i].resize(layer - 1);
                        for (int j = 0; j < layer - 1; ++j) {
                            tmp[i][j] = arr[spand[i]][j + 1];
                        }
                    }
                    int sign = (int) pow(-1, 1 + cnt2 + 1);
                    ans += arr[cnt2][0] * sign * det(tmp, layer - 1);
                }
            }

            return ans;
        }


        //计算伴随矩阵
       static int adjoint(const std::vector<std::vector<T>> &mat, std::vector<std::vector<T>> &adj, int N) {
            if (mat.size() != N) {
                fprintf(stderr, "mat must be square matrix\n");
                return -1;
            }
            for (int i = 0; i < mat.size(); ++i) {
                if (mat[i].size() != N) {
                    fprintf(stderr, "mat must be square matrix\n");
                    return -1;
                }
            }

            adj.resize(N);
            for (int i = 0; i < N; ++i) {
                adj[i].resize(N);
            }

            for (int y = 0; y < N; ++y) {
                std::vector<int> m_cols;
                for (int i = 0; i < N; ++i) {
                    if (i != y) m_cols.push_back(i);
                }

                for (int x = 0; x < N; ++x) {
                    std::vector<int> m_rows;
                    for (int i = 0; i < N; ++i) {
                        if (i != x) m_rows.push_back(i);
                    }

                    std::vector<std::vector<T>> m(N - 1);
                    for (int i = 0; i < N - 1; ++i) {
                        m[i].resize(N - 1);
                    }
                    for (int j = 0; j < N - 1; ++j) {
                        for (int i = 0; i < N - 1; ++i) {
                            m[j][i] = mat[m_rows[j]][m_cols[i]];
                        }
                    }

                    int sign = (int) pow(-1, x + y);
                    adj[y][x] = sign * getDeterminant(m, N - 1);
                }
            }
            return 0;
        }

        // 求逆矩阵
       SqrMatrix inverse(){
       SqrMatrix<T,width> inverseMatrix;

       std::vector<std::vector<T>> origin;
            std::vector<std::vector<T>> answer;
            for (int i = 0; i < width; ++i) {
                for (int j = 0; j < width; ++j) {
                    origin[i][j] = this->data[i][j];
                }
            }
            inverse(origin, answer, width);
            for (int i = 0; i < width; ++i) {
                for (int j = 0; j < width; ++j) {
                    inverseMatrix->data[i][j] = answer[i][j];
                }
            }
            return inverseMatrix;
    }
       static void inverse(const std::vector<std::vector<T>> &mat, std::vector<std::vector<T>> &inv, int N) {
            T det = determinant(mat, N);

            inv.resize(N);
            for (int i = 0; i < N; ++i) {
                inv[i].resize(N);
            }

            double coef = 1.f / det;
            std::vector<std::vector<T>> adj;
            if (adjoint(mat, adj, N) != 0) return;

            for (int y = 0; y < N; ++y) {
                for (int x = 0; x < N; ++x) {
                    inv[y][x] = (T) (coef * adj[y][x]);
                }
            }
        }
    };
}
