#ifndef TETRIS_CPP_Z_TETRIMINO_H_
#define TETRIS_CPP_Z_TETRIMINO_H_

#include "tetrimino.hpp"


namespace tetris {

class ZTetrimino : public tetris::Tetrimino {
  public:
    ZTetrimino(PlayArea* p_play_area);
    ~ZTetrimino();
    bool DoSuperRotationClockwise();
    bool DoSuperRotationCounterClockwise();
  private:
    Coord rotation_points_N_[5]{{1,1},{1,1},{1,1},{1,1},{1,1}};
    Coord rotation_points_E_[5]{{1,1},{2,1},{2,0},{1,3},{2,3}};
    Coord rotation_points_W_[5]{{1,1},{0,1},{0,0},{1,3},{0,3}};
    Coord rotation_points_S_[5]{{1,1},{1,1},{1,1},{1,1},{1,1}};
    std::vector<Coord> mino_relative_coord_N_{{1,1},{2,1},{0,2},{1,2}};
    std::vector<Coord> mino_relative_coord_E_{{1,1},{1,0},{2,2},{2,1}};
    std::vector<Coord> mino_relative_coord_W_{{1,1},{1,2},{0,0},{0,1}};
    std::vector<Coord> mino_relative_coord_S_{{1,1},{0,1},{2,0},{1,0}};

};

} //namespace tetris

#endif //TETRIS_CPP_Z_TETRIMINO_H_