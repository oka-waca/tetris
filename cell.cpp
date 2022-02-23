#include "cell.hpp"

namespace tetris {

Cell::Cell(){
  cell_type_ = 'E';
}


char Cell::getCellType(){
  return cell_type_;
}

void Cell::setCellType(char cell_type){
  cell_type_ = cell_type;
}


}