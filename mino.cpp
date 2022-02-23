
#include "mino.hpp"

namespace tetris {

Mino::Mino(){
  mino_type_ = 'E';
}

Mino::Mino(char mino_type){
  mino_type_ = mino_type;
  x_=0;
  y_=0;
}

Mino::Mino(char mino_type, int x, int y){
  mino_type_ = mino_type;
  x_=x;
  y_=y;
}

int  Mino::GetX(){
  return x_;
}

void Mino::SetX(int x){
  x_ = x;
}

int  Mino::GetY(){
  return y_;
}

void Mino::SetY(int y){
  y_ = y;
}

char Mino::GetMinoType(){
  return mino_type_;
}

void Mino::SetMinoType(char mino_type){
  mino_type_ = mino_type;
}



}