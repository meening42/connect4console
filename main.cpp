#include <fourinrow.h>
#include <stdio.h>

using namespace std;
int main(int argc, char *argv[])
{
    FourInRow game;
    char anotherGame = 'Y';
    while(anotherGame == 'Y'){
        game.initialize();
        game.showBoard();
        while(game.checkWinner()==NULL){
            game.makeMove();
            game.showBoard();
        }
        cout<<endl<<"Do you want to play another game?  [Y/N]"<< endl;
        scanf(" %c", &anotherGame);
    }
    return 0;
}
