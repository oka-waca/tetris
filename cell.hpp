#ifndef TETRIS_CPP_CELL_H_
#define TETRIS_CPP_CELL_H_


namespace tetris {

class Cell {
  public:
    Cell();
  //  ~Cell();

    char getCellType();
    void setCellType(char cell_type);


  private:
    char cell_type_;
};


} //namespace tetris

#endif //TETRIS_CPP_CELL_H_