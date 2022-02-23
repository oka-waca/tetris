#ifndef TETRIS_CPP_PLAY_AREA_H_
#define TETRIS_CPP_PLAY_AREA_H_

#include <vector>

#include "mino.hpp"
#include "cell.hpp"

namespace tetris {

  class Tetrimino;

  class PlayArea {
  public:
//    PlayArea(int matrix_row = 20, int matrix_col = 10, int buffer_zone_row = 20);
    PlayArea(int matrix_row, int matrix_col, int buffer_zone_row);
    PlayArea();

    //~PlayArea();

    void Reset();
    void CheckLine();
    void ClearLine();
    bool IsGameOver(Tetrimino* p_next_tetrimino);
    bool CheckBoundary(std::vector<Mino> minos);
    void WriteToMatrix(Tetrimino* p_tetrimino);
    int GetClerIndexSize();

    char CUIDraw(int y, int x);

  private:
    //Matrix matrix_;
    //BufferZone buffer_zone_;
    int matrix_row_;
    int matrix_col_;
    int buffer_zone_row_;

    std::vector<std::vector<Cell>> play_field_; //[y][x]
    std::vector<unsigned int> clear_idx;

    int locked_down_row_; //確定後

  };



} //namespace tetris

#endif //TETRIS_CPP_PLAY_AREA_H_