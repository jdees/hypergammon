#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <vector>

const int8_t CUBE_BLACK = -1;
const int8_t CUBE_MIDDLE = 0;
const int8_t CUBE_WHITE = 1;
const int8_t TURN_WHITE = 1;
const int8_t TURN_BLACK = 1;
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

  void print() {
    std::vector<int> board(27);
    for (auto i : pipWhite) ++board[i+1];
    for (auto i : pipBlack) --board[i+1];
    for (int j=13;j<24;++j) {
      printf("%3d",j);
      if (j==18) printf("| ");
    }
    printf("\n");
//    for (int j=0;j<3;j)
//      for (int i=13;++i;i<19)

  }

};




int main(int,char**) {
//  printf("hello world");
  Game::startGamePosition(true).print();
  return 0;
}
