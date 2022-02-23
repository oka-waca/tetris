
#include "win_input.hpp"

namespace tetris {

WinInput::WinInput(){

  pre_rotate_clock_ = false ;
  pre_rotate_counter_clock_ = false ;
  pre_move_right_ = false ;
  pre_move_left_ = false ;
  pre_do_hard_drop_ = false ;
  pre_do_soft_drop_ = false ;
  pre_space_ = false ;
  pre_tab_ = false ;
  pre_esc_ = false ;

  rotate_clock_ = false ;
  rotate_counter_clock_ = false ;
  move_right_ = false ;
  move_left_ = false ;
  do_hard_drop_ = false ;
  do_soft_drop_ = false ;
  space_ = false ;
  tab_ = false ;
  esc_ = false ;
}

void WinInput::Update(){
  /*
  pre_rotate_clock_ = rotate_clock_ ;
  pre_rotate_counter_clock_ = rotate_counter_clock_ ;
  pre_move_right_ = move_right_ ;
  pre_move_left_ = move_left_ ;
  pre_do_hard_drop_ = do_hard_drop_ ;
  pre_do_soft_drop_ = do_soft_drop_ ;
  pre_space_ = space_  ;
  pre_tab_ = tab_ ;
  pre_esc_ = esc_ ;
  
  rotate_clock_ = ( (GetAsyncKeyState(0x52) & 0x8000 )== 0x8000)? !pre_rotate_clock_ : false ;
  rotate_counter_clock_ =( (GetAsyncKeyState(0x57)& 0x8000 )== 0x8000)? !pre_rotate_counter_clock_ : false ;
  move_right_ =( (GetAsyncKeyState(VK_RIGHT)& 0x8000 )== 0x8000)? !pre_move_right_ : false ;
  move_left_ = ((GetAsyncKeyState(VK_LEFT)& 0x8000 )== 0x8000)? !pre_move_left_ : false ;
  do_hard_drop_ = ((GetAsyncKeyState(VK_UP)& 0x8000 )== 0x8000)? !pre_do_hard_drop_ : false ;
  do_soft_drop_ = ((GetAsyncKeyState(VK_DOWN)& 0x8000 )== 0x8000)? !pre_do_soft_drop_ : false ;
  space_ = ((GetAsyncKeyState(VK_SPACE)& 0x8000 )== 0x8000 )? !pre_space_ : false ;
  tab_ = ((GetAsyncKeyState(VK_TAB)& 0x8000 )== 0x8000)? !pre_tab_ : false ;
  esc_ = ((GetAsyncKeyState(VK_ESCAPE)& 0x8000) == 0x8000)? !pre_esc_ : false ;
  */
  //â¸ó«ïKóvÅ@âüÇµÇ¡ÇœÇ…îΩâûÇµÇ»Ç¢ÇÊÇ§Ç…
  rotate_clock_ = ((GetAsyncKeyState(0x52) & 0x1) == 0x1);
  rotate_counter_clock_ = ((GetAsyncKeyState(0x57) & 0x1) == 0x1);
  move_right_ = ((GetAsyncKeyState(VK_RIGHT) & 0x1) == 0x1);
  move_left_ = ((GetAsyncKeyState(VK_LEFT) & 0x1) == 0x1);
  do_hard_drop_ = ((GetAsyncKeyState(VK_UP) & 0x1) == 0x1);
  do_soft_drop_ = ((GetAsyncKeyState(VK_DOWN) & 0x1) == 0x1);
  space_ = ((GetAsyncKeyState(VK_SPACE) & 0x1) == 0x1);
  tab_ = ((GetAsyncKeyState(VK_TAB) & 0x1) == 0x1);
  esc_ = ((GetAsyncKeyState(VK_ESCAPE) & 0x1) == 0x1);
}


}