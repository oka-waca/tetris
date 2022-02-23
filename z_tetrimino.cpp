#include "z_tetrimino.hpp"
#include "play_area.hpp"


namespace tetris {

ZTetrimino::ZTetrimino(PlayArea* p_play_area) : Tetrimino(p_play_area){

  absolute_coord.x = 3;
  absolute_coord.y = 19;
  facing_ = 'N';
  
  for(auto rel_coord:mino_relative_coord_N_){
    minos_.push_back(Mino('Z', absolute_coord.x + rel_coord.x, absolute_coord.y + rel_coord.y));
  }

}

ZTetrimino::~ZTetrimino(){

}


bool ZTetrimino::DoSuperRotationClockwise(){
  bool tmp = false;
  if(facing_ == 'N'){
    for(int i=0; i<5; i++){
      tmp_minos_.clear();
      int tmp_abs_x = absolute_coord.x + rotation_points_N_[i].x - rotation_points_E_[i].x;
      int tmp_abs_y = absolute_coord.y + rotation_points_N_[i].y - rotation_points_E_[i].y;
      for(auto coord:mino_relative_coord_E_){
        tmp_minos_.push_back(Mino('Z', coord.x+tmp_abs_x, coord.y+tmp_abs_y));
      }
      if(p_play_area_->CheckBoundary(tmp_minos_)){
        absolute_coord.x = tmp_abs_x;
        absolute_coord.y = tmp_abs_y;
        minos_ = tmp_minos_;
        tmp = true;
        facing_ = 'E';
        break;
      }
    }

  }else if(facing_ == 'E'){
    for(int i=0; i<5; i++){
      tmp_minos_.clear();
      int tmp_abs_x = absolute_coord.x + rotation_points_E_[i].x - rotation_points_S_[i].x;
      int tmp_abs_y = absolute_coord.y + rotation_points_E_[i].y - rotation_points_S_[i].y;
      for(auto coord:mino_relative_coord_S_){
        tmp_minos_.push_back(Mino('Z', coord.x+tmp_abs_x, coord.y+tmp_abs_y));
      }
      if(p_play_area_->CheckBoundary(tmp_minos_)){
        absolute_coord.x = tmp_abs_x;
        absolute_coord.y = tmp_abs_y;
        minos_ = tmp_minos_;
        tmp = true;
        facing_ = 'S';
        break;
      }
    }

  }else if(facing_ == 'W'){
    for(int i=0; i<5; i++){
      tmp_minos_.clear();
      int tmp_abs_x = absolute_coord.x + rotation_points_W_[i].x - rotation_points_N_[i].x;
      int tmp_abs_y = absolute_coord.y + rotation_points_W_[i].y - rotation_points_N_[i].y;
      for(auto coord:mino_relative_coord_N_){
        tmp_minos_.push_back(Mino('Z', coord.x+tmp_abs_x, coord.y+tmp_abs_y));
      }
      if(p_play_area_->CheckBoundary(tmp_minos_)){
        absolute_coord.x = tmp_abs_x;
        absolute_coord.y = tmp_abs_y;
        minos_ = tmp_minos_;
        tmp = true;
        facing_ = 'N';
        break;
      }
    }    
  }else if(facing_ == 'S'){
    for(int i=0; i<5; i++){
      tmp_minos_.clear();
      int tmp_abs_x = absolute_coord.x + rotation_points_S_[i].x - rotation_points_W_[i].x;
      int tmp_abs_y = absolute_coord.y + rotation_points_S_[i].y - rotation_points_W_[i].y;
      for(auto coord:mino_relative_coord_W_){
        tmp_minos_.push_back(Mino('Z', coord.x+tmp_abs_x, coord.y+tmp_abs_y));
      }
      if(p_play_area_->CheckBoundary(tmp_minos_)){
        absolute_coord.x = tmp_abs_x;
        absolute_coord.y = tmp_abs_y;
        minos_ = tmp_minos_;
        tmp = true;
        facing_ = 'W';
        break;
      }
    }    
  }

  CheckDrop();
  return tmp;

}


bool ZTetrimino::DoSuperRotationCounterClockwise(){
  bool tmp = false;
  if(facing_ == 'N'){
    for(int i=0; i<5; i++){
      tmp_minos_.clear();
      int tmp_abs_x = absolute_coord.x + rotation_points_N_[i].x - rotation_points_W_[i].x;
      int tmp_abs_y = absolute_coord.y + rotation_points_N_[i].y - rotation_points_W_[i].y;
      for(auto coord:mino_relative_coord_W_){
        tmp_minos_.push_back(Mino('Z', coord.x+tmp_abs_x, coord.y+tmp_abs_y));
      }
      if(p_play_area_->CheckBoundary(tmp_minos_)){
        absolute_coord.x = tmp_abs_x;
        absolute_coord.y = tmp_abs_y;
        minos_ = tmp_minos_;
        tmp = true;
        facing_ = 'W';
        break;
      }
    }

  }else if(facing_ == 'E'){
    for(int i=0; i<5; i++){
      tmp_minos_.clear();
      int tmp_abs_x = absolute_coord.x + rotation_points_E_[i].x - rotation_points_N_[i].x;
      int tmp_abs_y = absolute_coord.y + rotation_points_E_[i].y - rotation_points_N_[i].y;
      for(auto coord:mino_relative_coord_N_){
        tmp_minos_.push_back(Mino('Z', coord.x+tmp_abs_x, coord.y+tmp_abs_y));
      }
      if(p_play_area_->CheckBoundary(tmp_minos_)){
        absolute_coord.x = tmp_abs_x;
        absolute_coord.y = tmp_abs_y;
        minos_ = tmp_minos_;
        tmp = true;
        facing_ = 'N';
        break;
      }
    }

  }else if(facing_ == 'W'){
    for(int i=0; i<5; i++){
      tmp_minos_.clear();
      int tmp_abs_x = absolute_coord.x + rotation_points_W_[i].x - rotation_points_S_[i].x;
      int tmp_abs_y = absolute_coord.y + rotation_points_W_[i].y - rotation_points_S_[i].y;
      for(auto coord:mino_relative_coord_S_){
        tmp_minos_.push_back(Mino('Z', coord.x+tmp_abs_x, coord.y+tmp_abs_y));
      }
      if(p_play_area_->CheckBoundary(tmp_minos_)){
        absolute_coord.x = tmp_abs_x;
        absolute_coord.y = tmp_abs_y;
        minos_ = tmp_minos_;
        tmp = true;
        facing_ = 'S';
        break;
      }
    }    
  }else if(facing_ == 'S'){
    for(int i=0; i<5; i++){
      tmp_minos_.clear();
      int tmp_abs_x = absolute_coord.x + rotation_points_S_[i].x - rotation_points_E_[i].x;
      int tmp_abs_y = absolute_coord.y + rotation_points_S_[i].y - rotation_points_E_[i].y;
      for(auto coord:mino_relative_coord_E_){
        tmp_minos_.push_back(Mino('Z', coord.x+tmp_abs_x, coord.y+tmp_abs_y));
      }
      if(p_play_area_->CheckBoundary(tmp_minos_)){
        absolute_coord.x = tmp_abs_x;
        absolute_coord.y = tmp_abs_y;
        minos_ = tmp_minos_;
        tmp = true;
        facing_ = 'E';
        break;
      }
    }    
  }

  CheckDrop();
  return tmp;

}


} //namespace tetris