#ifndef TETRIS_CPP_BAG_H_
#define TETRIS_CPP_BAG_H_

#include <vector>


#include "tetrimino.hpp"
#include "t_tetrimino.hpp"
#include "o_tetrimino.hpp"
#include "s_tetrimino.hpp"
#include "z_tetrimino.hpp"
#include "i_tetrimino.hpp"
#include "l_tetrimino.hpp"
#include "j_tetrimino.hpp"

namespace tetris {

  class PlayArea;

  class Bag {
  public:
    Bag(PlayArea* p_play_area);
    Bag(const Bag & bag);
    Bag();
    ~Bag();


    Bag &operator=(const Bag &);

    void RefreshBag();
    Tetrimino* FetchTetrimino();

  private:
    std::vector<Tetrimino*> bag_list_;
    PlayArea* p_play_area_;

  };

} //namespace tetris

#endif //TETRIS_CPP_BAG_H_


/*

コピーコンストラクタ、代入演算子等実装していないので注意

*/