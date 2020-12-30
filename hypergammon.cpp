#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <vector>

const int8_t CUBE_BLACK = -1;
const int8_t CUBE_MIDDLE = 0;
const int8_t CUBE_WHITE = 1;
const int8_t TURN_WHITE = 1;
const int8_t TURN_BLACK = -1;
const int8_t PIP_OUT = -1;
const int8_t PIP_BAR_WHITE = 0;
const int8_t PIP_BAR_BLACK = 25;

class Game {
public:
  int8_t cube;
  int8_t pipWhite[3];
  int8_t pipBlack[3];
  int8_t turn;
  enum GameState { INVALID, WHITE_WIN, BLACK_WIN, OPEN };

  Game(int8_t cube,int8_t w1,int8_t w2,int8_t w3,int8_t b1,int8_t b2,int8_t b3,int8_t turn) : cube{cube}, pipWhite{w1,w2,w3}, pipBlack{b1,b2,b3}, turn{turn} {}

  static Game startGamePosition(int whiteTurn) {
    return Game(CUBE_MIDDLE,1,2,3,22,23,24,whiteTurn?TURN_WHITE:TURN_BLACK);
  }

  int32_t id() const { return *(int32_t*)this; }
  void normalize() {
    std::sort(pipBlack,pipBlack+3);
    std::sort(pipBlack,pipBlack+3);
  }

    void printChecker(int pipcount, int pos, const char* empty="   ") {
        if (abs(pipcount)>pos) {
            if (pos==4 && abs(pipcount)>5)
                printf("%3d",abs(pipcount)); //< put max 5 pips visually, then number
            else
                printf("%s",pipcount<0?"  B":"  W");
        }
        else
            printf("%s",empty);
    }

    std::vector<Game> nextPositions(int dice1, int dice2) {
        const int8_t* pips = turn==TURN_WHITE ? pipWhite : pipBlack;

        Game res=*this;
        res.turn =

    }


  void print() {
    std::vector<int> board(27);
    for (auto i : pipWhite) ++board[i];
    for (auto i : pipBlack) --board[i];
    for (int j=13;j<=24;++j) {
      printf("%3d",j);
      if (j==18) printf("  |");
    }
    printf("\n");
    for (int j=0;j<5;++j) {
        for (int i=13;i<=24;++i) {
            printChecker(board[i],j);
            if (i==18) printChecker(board[PIP_BAR_BLACK],j,"  |");
        }
        printf("\n");
    }

    for (int i=1;i<=13;++i)
        printf("---");

    printf("\n");
    for (int j=4;j>=0;--j) {
        for (int i=12;i>=1;--i) {
            printChecker(board[i],j);
            if (i==7) printChecker(board[PIP_BAR_WHITE],j,"  |");
        }
        printf("\n");
    }

    for (int j=12;j>=1;--j) {
        printf("%3d",j);
      if (j==7) printf("  |");
    }
    printf("\n");


  }

};




int main(int,char**) {
//  printf("hello world");
  Game::startGamePosition(true).print();
  return 0;
}
