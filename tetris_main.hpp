#ifndef TETRIS_CPP_TETRIS_MAIN_H_
#define TETRIS_CPP_TETRIS_MAIN_H_


#include "play_area.hpp"
#include "bag.hpp"
#include "tetrimino.hpp"
#include "win_input.hpp"


namespace tetris {

enum Phase {
  Idle,
  Generation,
  Falling,
  Lock,
  Pattern,
  Animate,
  Eliminate,
  Completion,
  GameOver
};


class TetrisMain {
  public:
    TetrisMain(WinInput *p_win_input);
    ~TetrisMain();

    void Reset();
    bool Update(float time);
    void CUIDraw(char* out, char* hold, char*next);
    void Hold();
    int GetLevel();
    int GetClearedLine();

  private:
    PlayArea play_area_;
    WinInput *p_win_input_;
    Bag bag_;
    Phase current_phase_;
    Phase next_phase_;
    Tetrimino* playing_tetrimino_;
    Tetrimino* next_tetrimino_;
    Tetrimino* holding_tetrimino_;
    bool swap;
    
    int level_;
    int cleared_line_;
    float speed_;

    float delta_time_;
};

} //namespace tetris

#endif //TETRIS_CPP_TETRIS_MAIN_H_


/*

bagからフェッチしたp_tetriminoのメモリ解放に責任を持つこと

*/