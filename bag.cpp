#include <random>
#include <ctime>


#include "bag.hpp"


namespace tetris {

Bag::Bag(PlayArea* p_play_area){
  p_play_area_ = p_play_area;
}

Bag::Bag(){
  
}

Bag::Bag(const Bag & bag){
  this->p_play_area_ = bag.p_play_area_;
  this->bag_list_.clear();
  /*
  for(auto &ptetrimino:bag.bag_list_){
    Tetrimino *p = new Tetrimino(p_play_area_);
    *p = *ptetrimino;
    bag_list_.push_back(p);
  }
  */
}

Bag::~Bag(){
//Free baglist tetriminos
  for(auto &e : bag_list_){
    delete e;
  }

}

Bag &Bag::operator=(const Bag &robj){
  if(this != &robj){
    this->p_play_area_ = robj.p_play_area_;
    this->bag_list_.clear();
    /*
    for(auto ptetrimino:robj.bag_list_){
      Tetrimino *p = new Tetrimino(p_play_area_);
      *p = *ptetrimino;
      bag_list_.push_back(p);
    }
    */
  }
  return (*this);
}


void Bag::RefreshBag(){
  char tetrimino_type[7] = {'T', 'O', 'S', 'Z', 'I', 'L', 'J'};
  std::srand(std::time(nullptr));
  
  for(int i = 7; i>=1; --i){
    int r_idx = rand()%i; //0 ~ (i-1)
    char tmp = tetrimino_type[i-1];
    tetrimino_type[i-1] = tetrimino_type[r_idx];
    tetrimino_type[r_idx] = tmp;
  }

  bag_list_.clear();

  for (int i = 0; i<7; i++){
    Tetrimino *p_tetrimino;

    switch(tetrimino_type[i]){
      case 'T':
        p_tetrimino = new TTetrimino(p_play_area_);
        break;
      case 'O':
        p_tetrimino = new OTetrimino(p_play_area_);
        break;
      case 'S':
        p_tetrimino = new STetrimino(p_play_area_);
        break;
      case 'Z':
        p_tetrimino = new ZTetrimino(p_play_area_);
        break;
      case 'I':
        p_tetrimino = new ITetrimino(p_play_area_);
        break;
      case 'L':
        p_tetrimino = new LTetrimino(p_play_area_);
        break;
      case 'J':
        p_tetrimino = new JTetrimino(p_play_area_);
        break;

    }

   bag_list_.push_back(p_tetrimino);
  
  }
}

Tetrimino* Bag::FetchTetrimino(){
 
  if (bag_list_.size() == 0){
    RefreshBag();
  }
  Tetrimino* p_rt_val = bag_list_[0];
  bag_list_.erase(bag_list_.begin());
 

  return p_rt_val;
}



}