#ifndef TETRIS_CPP_MATRIX_H_
#define TETRIS_CPP_MATRIX_H_

#include <vector>

#include "cell.hpp"


namespace tetris {

class Matrix {
  public:
    Matrix();
    Matrix(int row = 20, int col = 10);
    ~Matrix();

  private:
    std::vector<std::vector<Cell>> matrix_data_;
};

} //namespace tetris

#endif //TETRIS_CPP_MATRIX_H_
