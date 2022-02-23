#include "tetrimino.hpp"
#include "play_area.hpp"

namespace tetris {

Tetrimino::Tetrimino(PlayArea* p_play_area){
  p_play_area_ = p_play_area;

  is_dropped_ = false;
  is_locked_down_ = false;
  lock_down_timer_max_ = 500.0;
  falling_time_max_ = 1000.0;
  movement_count_max_ = 15;
  lock_down_timer_ = 0.0;
  falling_time_ = 0.0;
  movement_count_ = 0;
  facing_ = 'N';
  // //Debug
  // minos_.push_back(Mino('D'));
  // // minos_.push_back(Mino('D'));
  // // minos_.push_back(Mino('D'));
  // minos_.push_back(Mino('D'));
  // int i = 0;
  // for(auto& mino : minos_){
  //   mino.SetY(20);
  //   mino.SetX(i+4);
  //   i++;
  // }

}


Tetrimino::~Tetrimino(){

}


bool Tetrimino::MoveRight(){
  bool tmp = false;
  tmp_minos_ = minos_;
  for(auto &mino: tmp_minos_){
    mino.SetX(mino.GetX()+1);
  }
  if(p_play_area_->CheckBoundary(tmp_minos_)){
    minos_ = tmp_minos_;
    absolute_coord.x++;
    tmp = true;
  }
  CheckDrop();

  return tmp;
}

bool Tetrimino::MoveLeft(){
  bool tmp = false;
  tmp_minos_ = minos_;
  for(auto &mino: tmp_minos_){
    mino.SetX(mino.GetX()-1);
  }
  if(p_play_area_->CheckBoundary(tmp_minos_)){
    minos_ = tmp_minos_;
    absolute_coord.x--;
    tmp = true;
  }
  CheckDrop();
  return tmp;


}


void Tetrimino::MoveDown(){
    tmp_minos_ = minos_;
    for(auto &mino: tmp_minos_){
      mino.SetY(mino.GetY()-1);
    }
    if(p_play_area_->CheckBoundary(tmp_minos_)){
      minos_ = tmp_minos_;
      absolute_coord.y--;
    }
    CheckDrop();

}

bool Tetrimino::RotateClockwise(){
  return true;
}

bool Tetrimino::RotateCounterClockwise(){
  return true;
}


void Tetrimino::Fall(float time){
  //printf("called");
  falling_time_ += time;
  if(falling_time_ > falling_time_max_){
    falling_time_ = 0;
    MoveDown();
  }
}


void Tetrimino::DoHardDrop(){
  while(!is_dropped_){
    MoveDown();
  }
  SetLockDownTimerMax(0.1);
}

void Tetrimino::DoSoftDrop(){
  falling_time_max_ /= 20;
}

void Tetrimino::CheckDrop(){

  tmp_minos_ = minos_;
  for(auto &mino: tmp_minos_){
    lowest_line_ = (lowest_line_<mino.GetY())? lowest_line_ : mino.GetY();
    mino.SetY(mino.GetY()-1);
  }
  if( !p_play_area_->CheckBoundary(tmp_minos_)){
    is_dropped_ = true;
  }else{
    is_dropped_ =false;
  }

}


void Tetrimino::CheckLockDown(float time){
  lock_down_timer_ += time;

  if(movement_count_max_ <= movement_count_ || lock_down_timer_ > lock_down_timer_max_){
    if(!is_dropped_){
      is_locked_down_ = false;
    }else{
      is_locked_down_ = true;
    }
  }

}

void Tetrimino::IncrementMovementCount(){
  movement_count_++;
  SetLockDownTimer(0.0);
}

void Tetrimino::SetFallingTimeMax(float time){
  falling_time_max_ = time;
}

void Tetrimino::SetFallingTime(float time){
  falling_time_ = time;
}
void Tetrimino::SetLockDownTimerMax(float time){
  lock_down_timer_max_ = time;
}

void Tetrimino::SetLockDownTimer(float time){
  lock_down_timer_ = time;
}

void Tetrimino::SetMovementCount(int count){
  movement_count_ = count;
}

bool Tetrimino::GetIsDropped(){
  return is_dropped_;
}

bool Tetrimino::GetIsLockedDown(){
  return is_locked_down_;
}

std::vector<Mino> Tetrimino::GetMinos(){
  return minos_;
}

std::vector<Mino> Tetrimino::GetGhostMinos(){
  return ghost_minos_;
}

bool Tetrimino::DoSuperRotationClockwise(){
  return true;
}

bool Tetrimino::DoSuperRotationCounterClockwise(){
  return true;
}


int Tetrimino::GetLowestLine(){
  return lowest_line_;
}

void Tetrimino::SetThePreviousLowestLine(int lowest_line){
  the_previous_lowest_line_ = lowest_line;
}


int Tetrimino::GetThePreviousLowestLine(){
  return the_previous_lowest_line_;
}


void Tetrimino::CalcGhostMino(){
  tmp_minos_ = minos_;
  while(p_play_area_->CheckBoundary(tmp_minos_)){
    ghost_minos_ = tmp_minos_;
    for(auto &mino: tmp_minos_){
      mino.SetY(mino.GetY()-1);
    }
  }
}



}
