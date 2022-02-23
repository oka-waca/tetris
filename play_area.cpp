#include "play_area.hpp"
#include "tetrimino.hpp"

namespace tetris {

PlayArea::PlayArea(int matrix_row, int matrix_col , int buffer_zone_row ){

  matrix_col_ = matrix_col;
  matrix_row_ = matrix_row;
  buffer_zone_row_ = buffer_zone_row;
  locked_down_row_ = 0;


}


PlayArea::PlayArea(){

}
void PlayArea::Reset(){

  play_field_.clear();
  for(int y = 0; y < matrix_row_ + buffer_zone_row_ ; y++){
    play_field_.push_back(std::vector<Cell>());
    
    for(int x = 0; x < matrix_col_; x++){
     play_field_[y].push_back(Cell());
    }

  }

}



void PlayArea::CheckLine(){
  clear_idx.clear();
  for( int y = matrix_row_ + buffer_zone_row_ - 1 ; y >= 0  ; --y){
    
    for(int x = 0; x < matrix_col_; x++){

      if ( play_field_[y][x].getCellType() == 'E' ) break;
      if ( x == matrix_col_ - 1 ){
        clear_idx.push_back(y);
      } 

    }
    
  } 

}


int PlayArea::GetClerIndexSize(){
  return clear_idx.size();
}

void PlayArea::ClearLine(){

  for (  int i = 0; i < clear_idx.size(); i ++ ){
    
      play_field_.erase(play_field_.begin() + clear_idx[i]);
      play_field_.push_back(std::vector<Cell>());
      for(int x = 0; x < matrix_col_; x++){
        (play_field_.end()-1)->push_back(Cell());
      }
      locked_down_row_--;
  }



}


bool PlayArea::IsGameOver(Tetrimino* p_next_tetrimino){
  // Lock Out
  if (locked_down_row_ >= matrix_row_) {  
    //printf("called2");
    return true;
  }

  //Block Out
  if ( !CheckBoundary(p_next_tetrimino->GetMinos()) ) {  
  //  printf("called3");
    return true;
  }

  return false; 
}


bool PlayArea::CheckBoundary(std::vector<Mino> minos){
  for(auto &mino: minos){
    //範囲外か判定
    if( mino.GetX() < 0 || mino.GetX() >= matrix_col_ || mino.GetY() < 0 || mino.GetY() >= matrix_row_+buffer_zone_row_){
      //printf("called6");
      return false;     
    }

    //空かどうか判定
    if(play_field_[mino.GetY()][mino.GetX()].getCellType() != 'E'){
      //printf("called5");
      return false;
    }

  }
  //printf("calleds");
  return true;

}


void PlayArea::WriteToMatrix(Tetrimino* p_tetrimino){

  locked_down_row_ = matrix_row_;
  for (auto &mino: p_tetrimino->GetMinos()){
    play_field_[mino.GetY()][mino.GetX()].setCellType(mino.GetMinoType());
    locked_down_row_ = (mino.GetY() < locked_down_row_)? mino.GetY() : locked_down_row_ ;
  }

}

char PlayArea::CUIDraw(int y, int x){

  char rt_val = (play_field_[y][x].getCellType()=='E')? '.' : play_field_[y][x].getCellType();

  return rt_val;
}




}