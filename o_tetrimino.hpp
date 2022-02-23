#ifndef TETRIS_CPP_O_TETRIMINO_H_
#define TETRIS_CPP_O_TETRIMINO_H_

#include "tetrimino.hpp"


namespace tetris {

class OTetrimino : public tetris::Tetrimino {
  public:
    OTetrimino(PlayArea* p_play_area);
    ~OTetrimino();
    bool DoSuperRotationClockwise();
    bool DoSuperRotationCounterClockwise();
    
  private:
    Coord rotation_points_N_[5]{{1,1},{1,1},{1,1},{1,1},{1,1}};
    Coord rotation_points_E_[5]{{1,1},{1,1},{1,1},{1,1},{1,1}};
    Coord rotation_points_W_[5]{{1,1},{1,1},{1,1},{1,1},{1,1}};
    Coord rotation_points_S_[5]{{1,1},{1,1},{1,1},{1,1},{1,1}};
    std::vector<Coord> mino_relative_coord_N_{{1,1},{2,1},{1,2},{2,2}};
    std::vector<Coord> mino_relative_coord_E_{{1,2},{1,1},{2,2},{2,1}};
    std::vector<Coord> mino_relative_coord_W_{{2,1},{2,2},{1,1},{1,2}};
    std::vector<Coord> mino_relative_coord_S_{{2,2},{1,2},{2,1},{1,1}};

};

} //namespace tetris

#endif //TETRIS_CPP_O_TETRIMINO_H_