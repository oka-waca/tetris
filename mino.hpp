
#ifndef TETRIS_CPP_MINO_H_
#define TETRIS_CPP_MINO_H_


namespace tetris {

class Mino {
  public:
    Mino();
    Mino(char mino_type);
    Mino(char mino_type, int x, int y);
    //~Mino();
    int GetX();
    void SetX(int x);
    int GetY();
    void SetY(int y);
    char GetMinoType();
    void SetMinoType(char mino_type);

  private:
    char mino_type_;
    int x_;
    int y_;

};


} //namespace tetris

#endif //TETRIS_CPP_MINO_H_