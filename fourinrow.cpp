#include "fourinrow.h"

FourInRow::FourInRow()
{
    initialize();
}

using namespace std;


void FourInRow::showBoard(){
    system("CLS");
    for(int i = 0; i<BOARD_HEIGHT;i++){
        cout<<endl<<" "<<i+1<<"|";
        for(int j = 0; j<BOARD_WIDTH;j++){
            cout<<board[j][i]<<" ";
        }
        cout<<"|";
     }
    cout<<endl<<"   1 2 3 4 5 6 7";
    cout<<endl;
};

void FourInRow::insertCoinInRow(int row){
    for(int i = BOARD_HEIGHT-1;i>=0;i--){
        if(board[row][i]=='_'){
            board[row][i]=playerOnMove;
            break;
        }
    }
    srand(time(NULL));
}

void FourInRow::switchPlayerOnMove(){
    if(playerOnMove ==char(219)){
        playerOnMove =char(177);
    }
    else{
        playerOnMove = char(219);
    }
};

void FourInRow::makeMove(){
    int row;
    if(playerOnMove==char(219)){
        do{
            cout<<endl<<"Select row to insert the coin: " ;
            cin>>row;
            if(board[row-1][0]!='_'){
                cout<<endl<<"Selected row is already full";
            }
        }
        while(board[row-1][0]!='_');

        insertCoinInRow(row-1);
    }
    if(playerOnMove==char(177)){
        row = rand() % 7;
        insertCoinInRow(row);
    }
    switchPlayerOnMove();
}

char FourInRow::checkWinner(){
    // check horizontal:
    int max = BOARD_WIDTH>BOARD_HEIGHT? BOARD_WIDTH:BOARD_HEIGHT;

    for(int k = 0;k<6;k++){
        for(int i=0;i<max;i++){
            int inRowX=0;
            int inRow0=0;
            for(int j=0;j<max;j++){
                char z = '_';
                switch (k) {
                    case 0:
                        if(i<BOARD_WIDTH && j<BOARD_HEIGHT){
                                z = board[i][j];
                        }
                        break;
                    case 1:
                        if(j<BOARD_WIDTH && i<BOARD_HEIGHT){
                            z = board[j][i];
                        }
                        break;
                    case 2:
                        if(i+j<BOARD_WIDTH && j<BOARD_HEIGHT){
                            z =board[i+j][j];
                        }
                        else{
                            continue;
                        }
                        break;
                    case 3:
                        if((i+j-(max-1)>=0) && (i+j-(max-1)<BOARD_WIDTH)){
                            z =board[i+j-(max-1)][j];
                        }
                        else{
                            continue;
                        }
                        break;
                    case 4:
                        if((max-i-j>=0) && (max-i-j<BOARD_WIDTH)){
                            z =board[max-j-i][j];
                        }
                        else{
                            continue;
                        }
                        break;
                    case 5:
                        if((2*max-2-j-i<BOARD_WIDTH) && (2*max-2-j-i>=0)){
                            z =board[2*max-2-j-i][j];
                        }
                        else{
                            continue;
                        }
                        break;

                }
                switch(z){
                    case char(177):
                        inRow0 +=1;
                        inRowX =0;
                        break;
                    case char(219):
                        inRowX +=1;
                        inRow0 =0;
                        break;
                    case '_':
                        inRowX =0;
                        inRow0 =0;
                        break;
                }
                if(inRowX >= 4){
                    cout<<"   Winner is "<<char(219)<<endl;
                    return 'X';
                }
                if(inRow0 >= 4){
                    cout<<"   Winner is "<<char(177)<<endl;
                    return '0';
                }
            }
        }
    }
    return NULL;
};



void FourInRow::initialize(){
    for(int i = 0; i<BOARD_WIDTH;i++){
        for(int j = 0; j<BOARD_HEIGHT;j++){
            board[i][j]='_';
        }
    }
};
