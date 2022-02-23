#ifndef TETRIS_CPP_WIN_INPUT_H_
#define TETRIS_CPP_WIN_INPUT_H_

#include <windows.h>

namespace tetris {

class WinInput {
  public:
    WinInput();
    void Update();
    bool rotate_clock_;
    bool rotate_counter_clock_;
    bool move_right_;
    bool move_left_;
    bool do_hard_drop_;
    bool do_soft_drop_;
    bool space_;
    bool tab_;
    bool esc_;

  private:
    bool pre_rotate_clock_;
    bool pre_rotate_counter_clock_;
    bool pre_move_right_;
    bool pre_move_left_;
    bool pre_do_hard_drop_;
    bool pre_do_soft_drop_;
    bool pre_space_;
    bool pre_tab_;
    bool pre_esc_;


};


} //namespace tetris

#endif //TETRIS_CPP_WIN_INPUT_H_