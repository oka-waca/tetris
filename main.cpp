
#define _CRT_SECURE_NO_WARNINGS


#include <windows.h>
#include <stdio.h>
#include <string>

#include "DxLib.h"


#include "tetris_main.hpp"
#include "win_input.hpp"



/*

Windows API可
ここだけ差し替えでGodot対応にできるように

*/

enum State {
  Initial,
  Running,
  Idling,
  Gameover
};


void CUIDraw(State state, char* str);
void GUIDraw(char*, char*, char*,std::string);


//int main() {
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ){

 // ウインドウモードに変更
    ChangeWindowMode( TRUE ) ;

	if( DxLib_Init() == -1 )		// ＤＸライブラリ初期化処理
	{
		return -1 ;			// エラーが起きたら直ちに終了
	}




    //Command Prompt
    constexpr CONSOLE_CURSOR_INFO cursor { 1, FALSE };
    CONSOLE_CURSOR_INFO init;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &init); // カーソルの初期状態を得る。
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor); // カーソルを不可視化する。

    constexpr SMALL_RECT rect { 0, 0, 15, 25 };
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &rect);

    //FPS
    LARGE_INTEGER freq, updated;
    if (!QueryPerformanceFrequency(&freq)) { return -1; } // カウンタの周波数を得る。
    if (!QueryPerformanceCounter(&updated)) { return -1; } // カウンタの値で初期化する。



    tetris::WinInput win_input;
    tetris::TetrisMain tetris_main(&win_input);
    State state = Initial;

    tetris_main.Reset();

    char out[21*11+1]; 
    char next[17];
    char hold[17];
    std::string out_str;

    int i = 0;
    float duration = 16.0;

    //描画先を裏画面に設定
    SetDrawScreen(DX_SCREEN_BACK);



    //Game Loop
    while(ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0){



      i++;
      //FPS 精度悪い
      LARGE_INTEGER start;
      if (!QueryPerformanceCounter(&start)) { break; } // カウンタの値を得る。
      // 以前の更新からの経過時間を計算する。
      //float duration = (float)(now.QuadPart - updated.QuadPart) * 1000 / (float)freq.QuadPart ;
      // // 規定のフレーム間インターバル (16ms) との差だけ待機する。
      // if (static_cast<DWORD>(duration) < 16) { Sleep(16 - static_cast<DWORD>(duration)); }
      // if (!QueryPerformanceCounter(&updated)) { break; } // 現在時刻を記録する。

      win_input.Update();



      //Halt
      if(win_input.esc_){
        break;
      }


      //Game Update
      if(state == Initial){
        if(win_input.space_){
          state = Running;
        }
      }else if(state == Running){
        if(win_input.space_){
          state = Idling;
        }else{
          if(tetris_main.Update(duration)){
            state = Gameover;
          }
        }

      }else if(state == Idling){
        if(win_input.space_){ //Press Resume
          state = Running;
        }
      } 
      else if(state==Gameover){
        if(win_input.space_){
          state = Running;
          tetris_main.Reset();
        }else if(win_input.esc_){
          break;
        }

      }

      //Draw
      tetris_main.CUIDraw(out,hold,next);
      // SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0, 0 });
      // //puts(_itoa((int)win_input.space_, out, 10));
      // //printf("%d\n",i);
      // puts(out);
      GUIDraw(out,hold,next,out_str);

      // char level_str[10];
      // char lines_str[10];
      // if(tetris_main.GetLevel()<99999){
      //   itoa(tetris_main.GetLevel(),level_str,10);
      // }else{
      //   itoa(99999,level_str,10);
      // }
      // if(tetris_main.GetClearedLine()<99999){
      //   itoa(tetris_main.GetClearedLine(), lines_str,10);
      // }else{
      //   itoa(99999,lines_str,10);
      // }
      
      out_str = "Level: " + std::to_string(tetris_main.GetLevel()) + "\nLine: " + std::to_string(tetris_main.GetClearedLine()) + "\n";
      if(state == Gameover){
        out_str += "Game Over !";
      } 
      DrawString(29,399,out_str.c_str(), GetColor( 255 , 255 , 255 ));



      while(1){
        QueryPerformanceCounter(&updated);
        if((updated.QuadPart-start.QuadPart)*1000/freq.QuadPart>duration){
          break;
        }
      }



    }
    
    WaitKey() ;
    DxLib_End() ;

    return 0;


}


void CUIDraw(State state, char* out){

}

void GUIDraw(char* out, char* hold, char* next, std::string out_str){

  unsigned int rinkaku = GetColor(64,64,64);
  unsigned int rinkakuE = GetColor(128,128,128);

  for(int y = 0; y<21; y++){
    for(int x = 0; x<10; x++){
      unsigned int color = 0;
      switch(out[x+y*11]){
        case 'T':
          color = GetColor(128,0,128);
          break;
        case 'O':
          color = GetColor(255,215,0);
          break;
        case 'S':
          color = GetColor(0,128,0);
          break;
        case 'Z':
          color = GetColor(255,0,0);
          break;
        case 'I':
          color = GetColor(0,191,255);
          break;
        case 'L':
          color = GetColor(255,165,0);
          break;
        case 'J':
          color = GetColor(0,0,139);
          break;
        case 'G':
          color = GetColor(128,128,128);
          break;
        case '.':
          color = GetColor(255,255,255);
          break;
      }
        DrawBox( 219+x*20, 29+y*20, 219 + 19 +x*20, 29+19+y*20, color, TRUE ) ;
        if(out[x+y*11]=='.'){
          DrawBox( 219+x*20, 29+y*20, 219 + 19 +x*20, 29+19+y*20, rinkakuE, FALSE ) ;
        }else{
          DrawBox( 219+x*20, 29+y*20, 219 + 19 +x*20, 29+19+y*20, rinkaku, FALSE ) ;
        }
    }  
  }


  //Hold
  for(int y = 0; y<4; y++){
    for(int x = 0; x<4; x++){
      unsigned int color = 0;
      switch(hold[x+y*4]){
        case 'T':
          color = GetColor(128,0,128);
          break;
        case 'O':
          color = GetColor(255,215,0);
          break;
        case 'S':
          color = GetColor(0,128,0);
          break;
        case 'Z':
          color = GetColor(255,0,0);
          break;
        case 'I':
          color = GetColor(0,191,255);
          break;
        case 'L':
          color = GetColor(255,165,0);
          break;
        case 'J':
          color = GetColor(0,0,139);
          break;
        case 'G':
          color = GetColor(128,128,128);
          break;
        case '.':
          color = GetColor(255,255,255);
          break;
      }
        DrawBox( 99+x*20, 29+y*20, 99 + 19 +x*20, 29+19+y*20, color, TRUE ) ;
        if(out[x+y*11]=='.'){
          DrawBox( 99+x*20, 29+y*20, 99 + 19 +x*20, 29+19+y*20, rinkakuE, FALSE ) ;
        }else{
          DrawBox( 99+x*20, 29+y*20, 99 + 19 +x*20, 29+19+y*20, rinkaku, FALSE ) ;
        }
    }  
  }

  //Next
    for(int y = 0; y<4; y++){
    for(int x = 0; x<4; x++){
      unsigned int color = 0;
      switch(next[x+y*4]){
        case 'T':
          color = GetColor(128,0,128);
          break;
        case 'O':
          color = GetColor(255,215,0);
          break;
        case 'S':
          color = GetColor(0,128,0);
          break;
        case 'Z':
          color = GetColor(255,0,0);
          break;
        case 'I':
          color = GetColor(0,191,255);
          break;
        case 'L':
          color = GetColor(255,165,0);
          break;
        case 'J':
          color = GetColor(0,0,139);
          break;
        case 'G':
          color = GetColor(128,128,128);
          break;
        case '.':
          color = GetColor(255,255,255);
          break;
      }
        DrawBox( 459+x*20, 29+y*20, 459 + 19 +x*20, 29+19+y*20, color, TRUE ) ;
        if(out[x+y*11]=='.'){
          DrawBox( 459+x*20, 29+y*20, 459 + 19 +x*20, 29+19+y*20, rinkakuE, FALSE ) ;
        }else{
          DrawBox( 459+x*20, 29+y*20, 459 + 19 +x*20, 29+19+y*20, rinkaku, FALSE ) ;
        }
    }  
  }




}

