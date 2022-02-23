
#include <cmath>

#include "tetris_main.hpp"

namespace tetris {

TetrisMain::TetrisMain(WinInput *p_win_input) {
  play_area_ = PlayArea(20, 10, 20);
  p_win_input_ = p_win_input;
  bag_ = Bag(&play_area_);  //kikenn dainyuuenzannsi overload wo

}

TetrisMain::~TetrisMain() {
  delete playing_tetrimino_;
  delete next_tetrimino_;
  delete holding_tetrimino_;
}

void TetrisMain::Reset(){
  play_area_.Reset();

  bag_ = Bag(&play_area_);//kikenn dainyuuenzannsi overload wo
  delete playing_tetrimino_;
  playing_tetrimino_ = nullptr;
  delete next_tetrimino_;
  next_tetrimino_ = nullptr;
  next_tetrimino_ = bag_.FetchTetrimino();
  current_phase_ = Idle;
  swap = false;
  level_ = 1;
  cleared_line_ = 0;
  speed_ = 1000;
  delete holding_tetrimino_;
  holding_tetrimino_ = nullptr;
}


bool TetrisMain::Update(float time) {

  level_ = cleared_line_/10 + 1;
  if(level_>15) level_ = 15;
  speed_ = std::pow(0.8-(level_-1)*0.007,level_-1)*1000;

  current_phase_ = next_phase_;

  switch (current_phase_)
  {

  case Idle:

    // if(p_win_input_->space_){
    //   //printf("callesd!");
    //   next_phase_ = Generation;
    // }
    next_phase_ = Generation;
    //printf("Idle\n");
    break;
 
  case Generation:
    playing_tetrimino_ = next_tetrimino_;
    next_tetrimino_ = bag_.FetchTetrimino();
    swap = false;


    next_phase_ = Falling;
    //printf("Generation\n");
    break;
  
  case Falling:

    playing_tetrimino_->SetFallingTimeMax(speed_);

    // if(p_win_input_->tab_ && swap == false){
    //   Hold();
    //   break;
    // }else if(p_win_input_->move_right_){
    //   playing_tetrimino_->MoveRight();
    // }else if(p_win_input_->move_left_){
    //   playing_tetrimino_->MoveLeft();
    // }else if(p_win_input_->rotate_clock_){
    //   //playing_tetrimino_->RotateClockwise();
    //   playing_tetrimino_->DoSuperRotationClockwise();
    // }else if(p_win_input_->rotate_counter_clock_){
    //   //playing_tetrimino_->RotateCounterClockwise();
    //   playing_tetrimino_->DoSuperRotationCounterClockwise();
    // }else if(p_win_input_->do_soft_drop_){
    //   playing_tetrimino_->DoSoftDrop();
    // }else if(p_win_input_->do_hard_drop_){
    //   playing_tetrimino_->DoHardDrop();
    // }

    if(p_win_input_->tab_ && swap == false){
      Hold();
      break;
    }
    if(p_win_input_->move_right_){
      playing_tetrimino_->MoveRight();
    }
    if(p_win_input_->move_left_){
      playing_tetrimino_->MoveLeft();
    }
    if(p_win_input_->rotate_clock_){
      //playing_tetrimino_->RotateClockwise();
      playing_tetrimino_->DoSuperRotationClockwise();
    }
    if(p_win_input_->rotate_counter_clock_){
      //playing_tetrimino_->RotateCounterClockwise();
      playing_tetrimino_->DoSuperRotationCounterClockwise();
    }
    if(p_win_input_->do_soft_drop_){
      playing_tetrimino_->DoSoftDrop();
    }
    if(p_win_input_->do_hard_drop_){
      playing_tetrimino_->DoHardDrop();
    }

    playing_tetrimino_->Fall(time);

    playing_tetrimino_->CalcGhostMino();

    if( playing_tetrimino_->GetIsDropped() ){
      next_phase_ = Lock;
      //playing_tetrimino_->SetThePreviousLowestLine(playing_tetrimino_->GetLowestLine());

    } 
    //printf("Falling\n");


    break;
  
  case Lock:
    if( playing_tetrimino_->GetIsLockedDown() ){
      next_phase_ = Pattern;    
      break;
    }

    playing_tetrimino_->SetFallingTimeMax(speed_);
    
    // if(p_win_input_->tab_ && swap == false){
    //   Hold();
    //   break;
    // }else if(p_win_input_->move_right_){
    //   playing_tetrimino_->MoveRight();
    //   playing_tetrimino_->IncrementMovementCount();
    // }else if(p_win_input_->move_left_){
    //   playing_tetrimino_->MoveLeft();
    //   playing_tetrimino_->IncrementMovementCount();
    // }else if(p_win_input_->rotate_clock_){
    //   //playing_tetrimino_->RotateClockwise();
    //   playing_tetrimino_->DoSuperRotationClockwise();
    //   playing_tetrimino_->IncrementMovementCount();
    // }else if(p_win_input_->rotate_counter_clock_){
    //   //playing_tetrimino_->RotateCounterClockwise();
    //   playing_tetrimino_->DoSuperRotationCounterClockwise();
    //   playing_tetrimino_->IncrementMovementCount();
    // }else if(p_win_input_->do_soft_drop_){
    //   playing_tetrimino_->DoSoftDrop();
    // }else if(p_win_input_->do_hard_drop_){
    //   playing_tetrimino_->DoHardDrop();
    // }

    if(p_win_input_->tab_ && swap == false){
      Hold();
      break;
    }
    if(p_win_input_->move_right_){
      if(playing_tetrimino_->MoveRight()){
        playing_tetrimino_->IncrementMovementCount();
      }
    }
    if(p_win_input_->move_left_){
      if(playing_tetrimino_->MoveLeft()){
        playing_tetrimino_->IncrementMovementCount();
      }
    }
    if(p_win_input_->rotate_clock_){
      //playing_tetrimino_->RotateClockwise();
      if(playing_tetrimino_->DoSuperRotationClockwise()){
        playing_tetrimino_->IncrementMovementCount();
      }
    }
    if(p_win_input_->rotate_counter_clock_){
      //playing_tetrimino_->RotateCounterClockwise();
      if(playing_tetrimino_->DoSuperRotationCounterClockwise()){
        playing_tetrimino_->IncrementMovementCount();
      }
    }
    if(p_win_input_->do_soft_drop_){
      playing_tetrimino_->DoSoftDrop();
    }
    if(p_win_input_->do_hard_drop_){
      playing_tetrimino_->DoHardDrop();
    }


    playing_tetrimino_->Fall(time);
    playing_tetrimino_->CalcGhostMino();

    if( !playing_tetrimino_->GetIsDropped() ){
      //next_phase_ = Falling;
      playing_tetrimino_->SetLockDownTimerMax(500);
      playing_tetrimino_->SetLockDownTimer(0.0);
      if(playing_tetrimino_->GetLowestLine()<playing_tetrimino_->GetThePreviousLowestLine()) {
        playing_tetrimino_->SetMovementCount(0);
        playing_tetrimino_->SetThePreviousLowestLine(playing_tetrimino_->GetLowestLine());
      }
      //playing_tetrimino_->SetFallingTime(0.0);
    }

    playing_tetrimino_->CheckLockDown(time);

    if( playing_tetrimino_->GetIsLockedDown()) next_phase_ = Pattern;
    //printf("Lock\n");

    break;

  case Pattern:

    play_area_.WriteToMatrix(playing_tetrimino_);
    delete playing_tetrimino_;
    playing_tetrimino_ = nullptr;
    play_area_.CheckLine();
    cleared_line_ += play_area_.GetClerIndexSize();

    next_phase_ = Animate;
    //printf("pattern\n");


    break;

  case Animate: //Not Draw
    
    next_phase_ = Eliminate;
    //printf("Animate\n");

    break;

  case Eliminate:

    play_area_.ClearLine();
    //printf("Elilminate\n");
    next_phase_ = Completion;

    break;

  case Completion:
    //Level
    //Score
    //printf("Completion\n");

    next_phase_ = Generation;

    break;
  default:
    break;
  }

  return (play_area_.IsGameOver(next_tetrimino_) && (current_phase_ == Completion));

}

void TetrisMain::CUIDraw(char* out, char* hold, char*next) {
  for(int y = 0 ; y < 21  ; y++){
    for(int x = 0; x < 10; x++){
      out[x+(20-y)*11] =  play_area_.CUIDraw(y,x);
    }
  } 

  if(playing_tetrimino_!=nullptr){
    for(auto &mino:playing_tetrimino_->GetGhostMinos()){
      out[mino.GetX() + (20-mino.GetY())*11] = 'G';
    }
  }


  if(playing_tetrimino_!=nullptr){
    for(auto &mino:playing_tetrimino_->GetMinos()){
      out[mino.GetX() + (20-mino.GetY())*11] = mino.GetMinoType();
    }
  }

  for(int y = 0 ; y < 21  ; y++){
    out[10+y*11] = '\n';
  }
  out[231] = '\0';


  for(int i = 0 ; i<16; i++){
    hold[i] = '.';
    next[i] = '.';
  }
  hold[16] = '\0';
  next[16] = '\0';

  if(next_tetrimino_!=nullptr){
    for(auto &mino:next_tetrimino_->GetMinos()){
      next[(mino.GetX()-3) + (3-(mino.GetY()-19))*4] = mino.GetMinoType();
    }
  }

  if(holding_tetrimino_!=nullptr){
    for(auto &mino:holding_tetrimino_->GetMinos()){
      hold[(mino.GetX()-3) + (3-(mino.GetY()-19))*4] = mino.GetMinoType();
    }
  }



}


void TetrisMain::Hold(){
    next_phase_ = Falling;

    Tetrimino *tmp = holding_tetrimino_;
//    holding_tetrimino_ =  playing_tetrimino_;
//    playing_tetrimino_ = tmp;


    switch((playing_tetrimino_->GetMinos())[0].GetMinoType()){
      case 'T':
        holding_tetrimino_ = new TTetrimino(&play_area_);
        break;
      case 'O':
        holding_tetrimino_ = new OTetrimino(&play_area_);
        break;
      case 'S':
        holding_tetrimino_ = new STetrimino(&play_area_);
        break;
      case 'Z':
        holding_tetrimino_ = new ZTetrimino(&play_area_);
        break;
      case 'I':
        holding_tetrimino_ = new ITetrimino(&play_area_);
        break;
      case 'L':
        holding_tetrimino_ = new LTetrimino(&play_area_);
        break;
      case 'J':
        holding_tetrimino_ = new JTetrimino(&play_area_);
        break;
    }

    delete playing_tetrimino_;
    
    if(tmp==nullptr){
      playing_tetrimino_ = next_tetrimino_;
      next_tetrimino_ = bag_.FetchTetrimino();
    }else{
      playing_tetrimino_ = tmp;
    }

    swap = true;

  
}

int TetrisMain::GetLevel(){
  return level_;
}

int TetrisMain::GetClearedLine(){
  return cleared_line_;  
}



}