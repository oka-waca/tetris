#ifndef TETRIS_CPP_TETRIMINO_H_
#define TETRIS_CPP_TETRIMINO_H_

#include <vector>


#include "mino.hpp"


namespace tetris {

class PlayArea;

struct Coord{
  int x;
  int y;
};

class Tetrimino{
  public:
    //Tetrimino();
    Tetrimino(PlayArea* p_play_area);
    virtual ~Tetrimino();
    bool MoveRight();
    bool MoveLeft();
    void MoveDown();
    virtual bool RotateClockwise();
    virtual bool RotateCounterClockwise();
    void DoHardDrop();
    void DoSoftDrop();

    void Fall(float time);
    void CheckLockDown(float time);
    void CheckDrop();
    bool GetIsDropped();
    bool GetIsLockedDown();

    void SetFallingTimeMax(float time);
    void SetFallingTime(float time);
    void SetLockDownTimerMax(float time);
    void SetLockDownTimer(float time);
    void SetMovementCount(int count);
    
    void IncrementMovementCount();
    std::vector<Mino> GetMinos();
    std::vector<Mino> GetGhostMinos();

    void CalcGhostMino();

    virtual bool DoSuperRotationClockwise();
    virtual bool DoSuperRotationCounterClockwise();

    int GetLowestLine();
    void SetThePreviousLowestLine(int);
    int GetThePreviousLowestLine();

    
  protected:
    std::vector<Mino> minos_;
    std::vector<Mino> tmp_minos_;
    std::vector<Mino> ghost_minos_;
    PlayArea* p_play_area_;

    Coord absolute_coord; 
    char facing_;

    float lock_down_timer_max_; 
    float lock_down_timer_; //m sec
    int movement_count_max_;
    int movement_count_;
    float falling_time_max_; //m sec
    float falling_time_;
    bool is_dropped_; //接地した　Lock Downは関係なし
    bool is_locked_down_;
    int lowest_line_ = 22;
    int the_previous_lowest_line_ = 22;

};

} //namespace tetris

#endif //TETRIS_CPP_TETRIMINO_H_