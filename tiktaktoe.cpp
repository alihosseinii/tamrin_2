#include "tiktaktoe.hpp"
#include <iostream>

using namespace std;

void tiktaktoe::display() const{
    for(int i {}; i<9; i++){
        for(int j {}; j<3; j++){
            cout << board[i];
            if(j != 2){
                cout << "|";
            }
            i++;
        }
        i--;
        if(i != 8)
            cout << "\n-----\n";
    }
    cout << '\n';   
}

bool tiktaktoe::iswiner() const{
    const int win[8][3] {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

    for (int i = 0; i < 8; ++i) {
        if (board[win[i][0]] == board[win[i][1]] && board[win[i][1]] == board[win[i][2]] && board[win[i][0]] != ' ') {
            return true;
        }
    }
    return false;
}

void tiktaktoe::switchplayer() {
    player = (player == 'X') ? 'O' : 'X';
}

bool tiktaktoe::isdrwa() const {
    for(int i {}; i<9; i++){
        if(board[i] == ' '){
            return false;
        }
    }
    return true;
}

bool tiktaktoe::isposible(int n) const{
    if(n<0 || n>8){
        return false;
    }
    return true;
}

bool tiktaktoe::isfull(int n) const{
    if(board[n] != ' '){
        return false;
    }
    return true;
}

void tiktaktoe::play() {
    while(true){
        cout << "chose(1,9)\n";
        display();
        int n;
        cin >> n;
        n--;
        if(!isposible(n)){
            cerr << "\nthe number must be betwin 1 and 9 \t enter another number.\n";
        }else if(!isfull(n)){
            cerr << "\n this house is allready have a paece inside it\t enter another number \n";
        }else{
            board[n] = player;
            if(iswiner()){
                cout << "\n*******************\n";
                display();
                cout << "\ncongrojilation\tyou won!!!\n";
                break;
            }else if(isdrwa()){
                cout << "\n*******************\n";
                display();
                cout << "\nits a drwa!\n";
                break;
            }
            switchplayer();
        }
        
        
        
      
    }
}