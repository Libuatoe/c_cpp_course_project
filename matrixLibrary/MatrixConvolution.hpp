#include "Matrix.hpp"

Matrix Matrix::convolution() {
    if (kernel.matrixLength / 2 == 1 && kernel.matrixWidth / 2 == 1) {
        int mid = (kernel.matrixLength - 1) / 2;
        int temp;
        Matrix <T, width, length> result;
        int kLength = kernel.matrixLength;
        int kWidth = kernel.matrixWidth;

        for (int i = 0; i < kLength + length - 1; i++) {
            for (int j = 0; j < kWidth + width - 1; j++) {
                temp = 0;
                for (int m = 0; m < kLength; m++) {
                    for (int n = 0; n < kWidth; n++) {
                        if ((i - m) >= 0 && (i - m) < length && (j - n) >= 0 && (j - n) < width) {
                            temp += kernel[m][n] * arr[i - m][j - n];
                        }
                    }
                }
                result[i][j] = temp;
            }
        }
    } else {

    }
}