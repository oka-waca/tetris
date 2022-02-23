#ifndef TETRIS_CPP_I_TETRIMINO_H_
#define TETRIS_CPP_I_TETRIMINO_H_

#include "tetrimino.hpp"


namespace tetris {

class ITetrimino : public tetris::Tetrimino {
  public:
    ITetrimino(PlayArea* p_play_area);
    ~ITetrimino();
    bool DoSuperRotationClockwise();
    bool DoSuperRotationCounterClockwise();

  private:
    Coord rotation_points_N_[5]{{1,2},{0,2},{3,2},{0,2},{3,2}};
    Coord rotation_points_E_[5]{{1,2},{2,2},{2,2},{2,3},{2,0}};
    Coord rotation_points_W_[5]{{1,2},{1,2},{1,2},{1,0},{1,3}};
    Coord rotation_points_S_[5]{{1,2},{3,2},{0,2},{3,1},{0,1}};
    std::vector<Coord> mino_relative_coord_N_{{0,2},{1,2},{2,2},{3,2}};
    std::vector<Coord> mino_relative_coord_E_{{2,3},{2,2},{2,1},{2,0}};
    std::vector<Coord> mino_relative_coord_W_{{1,0},{1,1},{1,2},{1,3}};
    std::vector<Coord> mino_relative_coord_S_{{3,1},{2,1},{1,1},{0,1}};

};

} //namespace tetris

#endif //TETRIS_CPP_I_TETRIMINO_H_