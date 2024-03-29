#include <iostream>
#include <vector>
#include <string>


bool isWin(char game[3][3]){
  bool win = false;
  if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
  if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && (game[1][0] == 'X' || game[1][0] == 'O')) win = true;
  if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && (game[2][0] == 'X' || game[2][0] == 'O')) win = true;
  // column
  if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
  if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && (game[0][1] == 'X' || game[0][1] == 'O')) win = true;
  if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
  // diagonal
  if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
  if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
  return win;
}
int  main(){
  int i, j;
  char game[3][3];
   // Tic-tac-toe
  for(int x=0;x<3;x++)
  {
      for(int y=0;y<3;y++)
      {
          game[x][y]=' ';
      }
  }
  char player1 = 'X';
  char player2 = 'O';
  bool turn = true; // false for player 1's turn, true for player 2's turn. Player 1 first.

  cout << "X = Player 1" << endl;
  cout<< "O = Player 2" << endl;
  int n=0;
    for (; n<9; n++){
        turn = !turn;  // use the not-operator to change true to false or false to true.
        if (turn == false)
            std::cout << "Player 1: ";
        else
            std::cout << "Player 2: ";
        std::cout << "Which cell to mark? i:[1..3], j:[1..3]: "; 
        std::cin >> i ;
        std::cin >> j ;
        if (turn == false)
            game[i][j] = 'X';
        else 
            game[i][j] = 'O';
        std::cout<<game[0][0]<<" "<<game[0][1]<<" "<<game[0][2]<<endl;
        std::cout<<game[1][0]<<" "<<game[1][1]<<" "<<game[1][2]<<endl;
        std::cout<<game[2][0]<<" "<<game[2][1]<<" "<<game[2][2]<<endl;
        if (isWin(game)){
            std::cout << "Win!" << std::endl;
            break; // need to terminate the problem
        }
    }
    if (n==9) // all celles with i=0 to 2 have been inputted above but no winner yet
        std::cout << "Tie!" << std::endl;

    return 0;

}   
