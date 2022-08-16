/**
 * @file othello.cc
 * @author Graham Pfeifer
 * @brief Implementation of the Othello class derived from the game class
 * @date 2022-04-24
 */

#include <iostream>
#include "game.h"
#include "othello.h"

Othello::Othello(){
    Spaces tmp;
    int num = 2;
    for(int i = 0; i < 9; i++){
        for(int k = 1; k < 18; k += 2){
            board[i][k].set_piece('|');
        }
        for(int j = 2; j < 9; j += 2){
            board[i][j].set_piece('-');
        }
    }
    for(char y = 'A'; y < 'I'; y++){
        board[0][num].set_piece(y);
        num += 2;
    }
    num = 1;
    for(char x = '1'; x < '9'; x++){
        board[num][0].set_piece(x);
        num++;
    }
    board[0][0].set_piece(' ');
    board[4][8].set_piece('O');
    board[4][10].set_piece('X');
    board[5][8].set_piece('X');
    board[5][10].set_piece('O');
}

void Othello::make_move(const std::string& move){
    int column, row, i, j, x, y;
    queue <string> moves;
    if(move == "XX"){
        cout << "Skip" << endl;
        game::make_move(move);
    }
    else{

        if(move[0] == 'A'){
            column = 2;
        }
        else if(move[0] == 'B'){
            column = 4;
        }
        else if(move[0] == 'C'){
            column = 6;
        }
        else if(move[0] == 'D'){
            column = 8;
        }
        else if(move[0] == 'E'){
            column = 10;
        }
        else if(move[0] == 'F'){
            column = 12;
        }
        else if(move[0] == 'G'){
            column = 14;
        }
        else if(move[0] == 'H'){
            column = 16;
        }
        else{
            column = 0;
        }
        if(move[1] == '1'){
            row = 1;
        }
        else if(move[1] == '2'){
            row = 2;
        }
        else if(move[1] == '3'){
            row = 3;
        }
        else if(move[1] == '4'){
            row = 4;
        }
        else if(move[1] == '5'){
            row = 5;
        }
        else if(move[1] == '6'){
            row = 6;
        }
        else if(move[1] == '7'){
            row = 7;
        }
        else if(move[1] == '8'){
            row = 8;
        }
        else{
            row = 0;
        }
        if(next_mover() == HUMAN){
            board[row][column].set_piece('X');
            //Diagonal top-left
            i = 2;
            j = 4;
            if(board[row - 1][column - 2].piece() == 'O'){
                while((row - i) > 0 && (column - j) > 0 && board[row - i][column - j].piece() == 'O'){
                    i++;
                    j += 2;
                }
                if(board[row - i][column - j].piece() == 'X'){
                    i--;
                    j -= 2;
                    while(i > 0 && j > 0){
                        board[row - i][column - j].flip();
                        i--;
                        j -= 2;
                    }
                }
            }
            //Up
            i = 2;
            if(board[row - 1][column].piece() == 'O'){
                while((row - i) > 0 && board[row - i][column].piece() == 'O'){
                    i++;
                }
                if(board[row - i][column].piece() == 'X'){
                    i--;
                    while(i > 0){
                        board[row - i][column].flip();
                        i--;
                    }
                }
            }
            //Diagonal top-right
            i = 2;
            j = 4;
            if(board[row - 1][column + 2].piece() == 'O'){
                while((row - i) > 0 && (column + j) < 17 && board[row - i][column + j].piece() == 'O'){
                    i++;
                    j += 2;
                }
                if(board[row - i][column + j].piece() == 'X'){
                    i--;
                    j -= 2;
                    while(i > 0 && j > 0){
                        board[row - i][column + j].flip();
                        i--;
                        j -= 2;
                    }
                }
            }
            //Left
            j = 4;
            if(board[row][column - 2].piece() == 'O'){
                while((column - j) > 0 && board[row][column - j].piece() == 'O'){
                    j += 2;
                }
                if(board[row][column - j].piece() == 'X'){
                    j -= 2;
                    while(j > 0){
                        board[row][column - j].flip();
                        j -= 2;
                    }
                }
            }
            //Right
            j = 4;
            if(board[row][column + 2].piece() == 'O'){
                while((column + j) < 17 && board[row][column + j].piece() == 'O'){
                    j += 2;
                }
                if(board[row][column + j].piece() == 'X'){
                    j -= 2;
                    while(j > 0){
                        board[row][column + j].flip();
                        j -= 2;
                    }
                }
            }
            //Diagonal bottom-left
            i = 2;
            j = 4;
            if(board[row + 1][column - 2].piece() == 'O'){
                while((row + i) < 9 && (column - j) > 0 && board[row + i][column - j].piece() == 'O'){
                    i++;
                    j += 2;
                }
                if(board[row + i][column - j].piece() == 'X'){
                    i--;
                    j -= 2;
                    while(i > 0 && j > 0){
                        board[row + i][column - j].flip();
                        i--;
                        j -= 2;
                    }
                }
            }
            //Down
            i = 2;
            if(board[row + 1][column].piece() == 'O'){
                while((row + i) < 9 && board[row + i][column].piece() == 'O'){
                    i++;
                }
                if(board[row + i][column].piece() == 'X'){
                    i--;
                    while(i > 0){
                        board[row + i][column].flip();
                        i--;
                    }
                }
            }
            //Diagonal bottom-right
            i = 2;
            j = 4;
            if(board[row + 1][column + 2].piece() == 'O'){
                while((row + i) < 9 && (column + j) < 17 && board[row + i][column + j].piece() == 'O'){
                    i++;
                    j += 2;
                }
                if(board[row + i][column + j].piece() == 'X'){
                    i--;
                    j -= 2;
                    while(i > 0 && j > 0){
                        board[row + i][column + j].flip();
                        i--;
                        j -=2;
                    }
                }
            }
        }
        else{
            board[row][column].set_piece('O');
            //Diagonal top-left
            i = 2;
            j = 4;
            if(board[row - 1][column - 2].piece() == 'X'){
                while((row - i) > 0 && (column - j) > 0 && board[row - i][column - j].piece() == 'X'){
                    i++;
                    j += 2;
                }
                if(board[row - i][column - j].piece() == 'O'){
                    while(i > 0 && j > 0){
                        i--;
                        j -= 2;
                        board[row - i][column - j].flip();
                        i--;
                        j -= 2;
                    }
                }
            }
            //Up
            i = 2;
            if(board[row - 1][column].piece() == 'X'){
                while((row - i) > 0 && board[row - i][column].piece() == 'X'){
                    i++;
                }
                if(board[row - i][column].piece() == 'O'){
                    i--;
                    while(i > 0){
                        board[row - i][column].flip();
                        i--;
                    }
                }
            }
            //Diagonal top-right
            i = 2;
            j = 4;
            if(board[row - 1][column + 2].piece() == 'X'){
                while((row - i) > 0 && (column + j) < 17 && board[row - i][column + j].piece() == 'X'){
                    i++;
                    j += 2;
                }
                if(board[row - i][column + j].piece() == 'O'){
                    i--;
                    j -= 2;
                    while(i > 0 && j > 0){
                        board[row - i][column + j].flip();
                        i--;
                        j -= 2;
                    }
                }
            }
            //Left
            j = 4;
            if(board[row][column - 2].piece() == 'X'){
                while((column - j) > 0 && board[row][column - j].piece() == 'X'){
                    j += 2;
                }
                if(board[row][column - j].piece() == 'O'){
                    j -= 2;
                    while(j > 0){
                        board[row][column - j].flip();
                        j -= 2;
                    }
                }
            }
            //Right
            j = 4;
            if(board[row][column + 2].piece() == 'X'){
                while((column + j) < 17 && board[row][column + j].piece() == 'X'){
                    j += 2;
                }
                if(board[row][column + j].piece() == 'O'){
                    j -= 2;
                    while(j > 0){
                        board[row][column + j].flip();
                        j -= 2;
                    }
                }
            }
            //Diagonal bottom-left
            i = 2;
            j = 4;
            if(board[row + 1][column - 2].piece() == 'X'){
                while((row + i) < 9 && (column - j) > 0 && board[row + i][column - j].piece() == 'X'){
                    i++;
                    j += 2;
                }
                if(board[row + i][column - j].piece() == 'O'){
                    i--;
                    j -= 2;
                    while(i > 0 && j > 0){
                        board[row + i][column - j].flip();
                        i--;
                        j -= 2;
                    }
                }
            }
            //Down
            i = 2;
            if(board[row + 1][column].piece() == 'X'){
                while((row + i) < 9 && board[row + i][column].piece() == 'X'){
                    i++;
                }
                if(board[row + i][column].piece() == 'O'){
                    i--;
                    while(i > 0){
                        board[row + i][column].flip();
                        i--;
                    }
                }
            }
            //Diagonal bottom-right
            i = 2;
            j = 4;
            if(board[row + 1][column + 2].piece() == 'X'){
                while((row + i) < 9 && (column + j) < 17 && board[row + i][column + j].piece() == 'X'){
                    i++;
                    j += 2;
                }
                if(board[row + i][column + j].piece() == 'O'){
                    i--;
                    j -= 2;
                    while(i > 0 && j > 0){
                        board[row - i][column - j].flip();
                        i--;
                        j -=2;
                    }
                }
            }
            //Diagonal top-left
            i = 2;
            j = 4;
            if(board[row - 1][column + 2].piece() == 'X'){
                while((row - i) > 0 && (column + j) < 17 && board[row - i][column + j].piece() == 'X'){
                    i++;
                    j += 2;
                }
                if(board[row - i][column + j].piece() == 'O'){
                    i--;
                    j -= 2;
                    while(i > 0 && j > 0){
                        board[row - i][column + j].flip();
                        i--;
                        j -= 2;
                    }
                }
            }
            //Up
            i = 2;
            if(board[row - 1][column].piece() == 'X'){
                while((row - i) > 0 && board[row - i][column].piece() == 'X'){
                    i++;
                }
                if(board[row - i][column].piece() == 'O'){
                    i--;
                    while(i > 0){
                        board[row - i][column].flip();
                        i--;
                    }
                }
            }
            //Diagonal top-right
            i = 2;
            j = 4;
            if(board[row - 1][column + 2].piece() == 'X'){
                while((row - i) > 0 && (column + j) < 17 && board[row - i][column + j].piece() == 'X'){
                    i++;
                    j += 2;
                }
                if(board[row - i][column + j].piece() == 'O'){
                    i--;
                    j -= 2;
                    while(i > 0 && j > 0){
                        board[row - i][column + j].flip();
                        i--;
                        j -= 2;
                    }
                }
            }
            //Left
            j = 4;
            if(board[row][column - 2].piece() == 'X'){
                while((column - j) > 0 && board[row][column - j].piece() == 'X'){
                    j += 2;
                }
                if(board[row][column - j].piece() == 'O'){
                    j -= 2;
                    while(j > 0){
                        board[row][column - j].flip();
                        j -= 2;
                    }
                }
            }
            //Right
            j = 4;
            if(board[row][column + 2].piece() == 'X'){
                while((column + j) < 17 && board[row][column + j].piece() == 'X'){
                    j += 2;
                }
                if(board[row][column + j].piece() == 'O'){
                    j -= 2;
                    while(j > 0){
                        board[row][column + j].flip();
                        j -= 2;
                    }
                }
            }
            //Diagonal bottom-left
            i = 2;
            j = 4;
            if(board[row + 1][column - 2].piece() == 'X'){
                while((row + i) < 9 && (column - j) > 0 && board[row + i][column - j].piece() == 'X'){
                    i++;
                    j += 2;
                }
                if(board[row + i][column - j].piece() == 'O'){
                    i--;
                    j -= 2;
                    while(i > 0 && j > 0){
                        board[row + i][column - j].flip();
                        i--;
                        j -= 2;
                    }
                }
            }
            //Down
            i = 2;
            if(board[row + 1][column].piece() == 'X'){
                while((row + i) < 9 && board[row + i][column].piece() == 'X'){
                    i++;
                }
                if(board[row + i][column].piece() == 'O'){
                    i--;
                    while(i > 0){
                        board[row + i][column].flip();
                        i--;
                    }
                }
            }
            //Diagonal bottom-right
            i = 2;
            j = 4;
            if(board[row + 1][column + 2].piece() == 'X'){
                while((row + i) < 9 && (column + j) < 17 && board[row + i][column + j].piece() == 'X'){
                    i++;
                    j += 2;
                }
                if(board[row + i][column + j].piece() == 'O'){
                    i--;
                    j -= 2;
                    while(i > 0 && j > 0){
                        board[row + i][column + j].flip();
                        i--;
                        j -=2;
                    }
                }
            }
        }
        game::make_move(move);
    }
}

void Othello::restart(){
    game::restart();
    return;
}

game* Othello::clone()const{
    return new Othello(*this);
}

void Othello::compute_moves(queue<string>& moves)const{
    string move, row, column;
    /**for(char row = 'A'; row < 'I'; row++){
        for(char column = '1'; column < '9'; column++){
            move = row + column;
            if(is_legal(move)){
                moves.push(move);
            }
        }
    }*/
    /**for(int i = 1; i < 9; i++){
        for(int j = 1; j < 9; j++){
            if(i == 1){
                column = "A";
            }
            else if(i == 2){
                column = "B";
            }
            else if(i == 3){
                column = "C";
            }
            else if(i == 4){
                column = "D";
            }
            else if(i == 5){
                column = "E";
            }
            else if(i == 6){
                column = "F";
            }
            else if(i == 7){
                column = "G";
            }
            else if(i == 8){
                column = "H";
            }
            if(j == 1){
                row = 1;
            }
            else if(j == 2){
                row = 2;
            }
            else if(j == 3){
                row = 3;
            }
            else if(j == 4){
                row = 4;
            }
            else if(j == 5){
                row = 5;
            }
            else if(j == 6){
                row = 6;
            }
            else if(j == 7){
                row = 7;
            }
            else if(j == 8){
                row = 8;
            }
            move = column + row;
            if(is_legal(move)){
                moves.push(move);
            }
        }
    }*/
    /**if(moves.empty()){
        moves.push("XX");
    }*/
    move = "A1";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "A2";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "A3";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "A4";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "A5";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "A6";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "A7";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "A8";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "B1";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "B2";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "B3";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "B4";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "B5";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "B6";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "B7";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "B8";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "C1";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "C2";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "C3";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "C4";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "C5";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "C6";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "C7";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "C8";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "D1";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "D2";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "D3";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "D4";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "D5";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "D6";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "D7";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "D8";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "E1";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "E2";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "E3";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "E4";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "E5";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "E6";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "E7";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "E8";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "F1";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "F2";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "F3";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "F4";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "F5";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "F6";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "F7";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "F8";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "G1";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "G2";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "G3";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "G4";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "G5";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "G6";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "G7";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "G8";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "H1";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "H2";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "H3";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "H4";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "H5";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "H6";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "H7";
    if(is_legal(move)){
        moves.push(move);
    }
    move = "H8";
    if(is_legal(move)){
        moves.push(move);
    }
    if(moves.empty()){
        moves.push("XX");
    }
}

void Othello::display_status()const{
    if(next_mover() == HUMAN){
        display_message("Black's Move\n");
    }
    else{
        display_message("White's Move\n");
    }
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 18; j++){
            board[i][j].output(cout);
        }
        cout << endl;
    }
}

int Othello::evaluate()const{
    int black, white;
    black = white = 0;
    for(int i = 1; i < 9; i++){
        for(int j = 2; j < 17; j += 2){
            if(board[i][j].piece() == 'O'){
                if(i == 1 || i == 8 || j == 2 || j == 16){
                    white++;
                }
                if((i == 1 && j == 2) || (i == 1 && j == 16) || (i == 8 && j == 2) || (i == 8 && j == 16)){
                    white++;
                }
                white++;
            }
            else if(board[i][j].piece() == 'X'){
                if(i == 1 || i == 8 || j == 2 || j == 16){
                    black++;
                }
                if((i == 1 && j == 2) || (i == 1 && j == 16) || (i == 8 && j == 2) || (i == 8 && j == 16)){
                    black++;
                }
                black++;
            }
        }
    }
    return white - black;
}

bool Othello::is_game_over()const{
    queue <string> moves;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 17; j++){
            if(board[i][j].piece() == '-'){
                return false;
            }
        }
    }
    compute_moves(moves);
    if(moves.front() == "XX"){
        return true;
    }
    else{
        return false;
    }
}

bool Othello::is_legal(const std::string& move)const{
    int column, row;
    queue <string> moves;
    if(move == "XX"){
        compute_moves(moves);
        if(moves.front() == "XX"){
            return true;
        }
        else{
            return false;
        }
    }
    else{

        if(move[0] == 'A'){
            column = 2;
        }
        else if(move[0] == 'B'){
            column = 4;
        }
        else if(move[0] == 'C'){
            column = 6;
        }
        else if(move[0] == 'D'){
            column = 8;
        }
        else if(move[0] == 'E'){
            column = 10;
        }
        else if(move[0] == 'F'){
            column = 12;
        }
        else if(move[0] == 'G'){
            column = 14;
        }
        else if(move[0] == 'H'){
            column = 16;
        }
        else{
            column = 0;
        }
        if(move[1] == '1'){
            row = 1;
        }
        else if(move[1] == '2'){
            row = 2;
        }
        else if(move[1] == '3'){
            row = 3;
        }
        else if(move[1] == '4'){
            row = 4;
        }
        else if(move[1] == '5'){
            row = 5;
        }
        else if(move[1] == '6'){
            row = 6;
        }
        else if(move[1] == '7'){
            row = 7;
        }
        else if(move[1] == '8'){
            row = 8;
        }
        else{
            row = 0;
        }
        if(next_mover() == HUMAN){
            int i, j;
            if(board[row][column].piece() != '-'){
                return false;
            }
            else{
                //Diagonal top-left
                if(board[row - 1][column - 2].piece() == 'O' && board[row - 2][column - 4].piece() != '-'){
                    if(board[row - 2][column - 4].piece() == 'X'){
                        return true;
                    }
                    else{
                        i = 3;
                        j = 6;
                        while((row - i) > 0 && (column - j) > 0){
                            if(board[row - i][column - j].piece() == 'X'){
                                return true;
                            }
                            i++;
                            j += 2;
                        }
                    }
                }
                //Up
                if(board[row - 1][column].piece() == 'O' && board[row - 2][column].piece() != '-'){
                    if(board[row - 2][column].piece() == 'X'){
                        return true;
                    }
                    else{
                        i = 3;
                        while((row - i) > 0){
                            if(board[row - i][column].piece() == 'X'){
                                return true;
                            }
                            i++;
                        }
                    }
                }
                //Diagonal top-right
                if(board[row - 1][column + 2].piece() == 'O' && board[row - 2][column + 4].piece() != '-'){
                    if(board[row - 2][column + 4].piece() == 'X'){
                        return true;
                    }
                    else{
                        i = 3;
                        j = 6;
                        while((row - i) > 0 && (column + j) < 17){
                            if(board[row - i][column + j].piece() == 'X'){
                                return true;
                            }
                            i++;
                            j += 2;
                        }
                    }
                }
                //Left
                if(board[row][column - 2].piece() == 'O' && board[row][column - 4].piece() != '-'){
                    if(board[row][column - 4].piece() == 'X'){
                        return true;
                    }
                    else{
                        j = 6;
                        while((column - j) > 0){
                            if(board[row][column - j].piece() == 'X'){
                                return true;
                            }
                            j += 2;
                        }
                    }
                }
                //Right
                if(board[row][column + 2].piece() == 'O' && board[row][column + 4].piece() != '-'){
                    if(board[row][column + 4].piece() == 'X'){
                        return true;
                    }
                    else{
                        j = 6;
                        while((column + j) < 17){
                            if(board[row][column + j].piece() == 'X'){
                                return true;
                            }
                            j += 2;
                        }
                    }
                }
                //Diagonal bottom-left
                if(board[row + 1][column - 2].piece() == 'O' && board[row + 2][column - 4].piece() != '-'){
                    if(board[row + 2][column - 4].piece() == 'X'){
                        return true;
                    }
                    else{
                        i = 3;
                        j = 6;
                        while((row + i) < 9 && (column - j) > 0){
                            if(board[row + i][column - j].piece() == 'X'){
                                return true;
                            }
                            i++;
                            j += 2;
                        }
                    }
                }
                //Down
                if(board[row + 1][column].piece() == 'O' && board[row + 2][column].piece() != '-'){
                    if(board[row + 2][column].piece() == 'X'){
                        return true;
                    }
                    else{
                        i = 3;
                        while((row + i) < 9){
                            if(board[row + i][column].piece() == 'X'){
                                return true;
                            }
                            i++;
                        }
                    }
                }
                //Diagonal bottom-right
                if(board[row + 1][column + 2].piece() == 'O' && board[row + 2][column + 4].piece() != '-'){
                    if(board[row + 2][column + 4].piece() == 'X'){
                        return true;
                    }
                    else{
                        i = 3;
                        j = 6;
                        while((row + i) < 9 && (column + j) < 17){
                            if(board[row + i][column + j].piece() == 'X'){
                                return true;
                            }
                            i++;
                            j += 2;
                        }
                    }
                }
                //If all surrounding spaces are empty
                return false;
            }
        }
        else{
            int i, j;
            if(board[row][column].piece() != '-'){
                return false;
            }
            else{
                //Diagonal top-left
                if(board[row - 1][column - 2].piece() == 'X' && board[row - 2][column - 4].piece() != '-'){
                    if(board[row - 2][column - 4].piece() == 'O'){
                        return true;
                    }
                    else{
                        i = 3;
                        j = 6;
                        while((row - i) > 0 && (column - j) > 0){
                            if(board[row - i][column - j].piece() == 'O'){
                                return true;
                            }
                            i++;
                            j += 2;
                        }
                    }
                }
                //Up
                if(board[row - 1][column].piece() == 'X' && board[row - 2][column].piece() != '-'){
                    if(board[row - 2][column].piece() == 'O'){
                        return true;
                    }
                    else{
                        i = 3;
                        while((row - i) > 0){
                            if(board[row - i][column].piece() == 'O'){
                                return true;
                            }
                            i++;
                        }
                    }
                }
                //Diagonal top-right
                if(board[row - 1][column + 2].piece() == 'X' && board[row - 2][column + 4].piece() != '-'){
                    if(board[row - 2][column + 4].piece() == 'O'){
                        return true;
                    }
                    else{
                        i = 3;
                        j = 6;
                        while((row - i) > 0 && (column + j) < 17){
                            if(board[row - i][column + j].piece() == 'O'){
                                return true;
                            }
                            i++;
                            j += 2;
                        }
                    }
                }
                //Left
                if(board[row][column - 2].piece() == 'X' && board[row][column - 4].piece() != '-'){
                    if(board[row][column - 4].piece() == 'O'){
                        return true;
                    }
                    else{
                        j = 6;
                        while((column - j) > 0){
                            if(board[row][column - j].piece() == 'O'){
                                return true;
                            }
                            j += 2;
                        }
                    }
                }
                //Right
                if(board[row][column + 2].piece() == 'X' && board[row][column + 4].piece() != '-'){
                    if(board[row][column + 4].piece() == 'O'){
                        return true;
                    }
                    else{
                        j = 6;
                        while((column + j) < 17){
                            if(board[row][column + j].piece() == 'O'){
                                return true;
                            }
                            j += 2;
                        }
                    }
                }
                //Diagonal bottom-left
                if(board[row + 1][column - 2].piece() == 'X' && board[row + 2][column - 4].piece() != '-'){
                    if(board[row + 2][column - 4].piece() == 'O'){
                        return true;
                    }
                    else{
                        i = 3;
                        j = 6;
                        while((row + i) < 9 && (column - j) > 0){
                            if(board[row + i][column - j].piece() == 'O'){
                                return true;
                            }
                            i++;
                            j += 2;
                        }
                    }
                }
                //Down
                if(board[row + 1][column].piece() == 'X' && board[row + 2][column].piece() != '-'){
                    if(board[row + 2][column].piece() == 'O'){
                        return true;
                    }
                    else{
                        i = 3;
                        while((row + i) < 9){
                            if(board[row + i][column].piece() == 'O'){
                                return true;
                            }
                            i++;
                        }
                    }
                }
                //Diagonal bottom-right
                if(board[row + 1][column + 2].piece() == 'X' && board[row + 2][column + 4].piece() != '-'){
                    if(board[row + 2][column + 4].piece() == 'O'){
                        return true;
                    }
                    else{
                        i = 3;
                        j = 6;
                        while((row + i) < 9 && (column + j) < 17){
                            if(board[row + i][column + j].piece() == 'O'){
                                return true;
                            }
                            i++;
                            j += 2;
                        }
                    }
                }
                //If all remaining spaces are empty
                return false;
            }
        }
    }
}

game::who Othello::winning()const{
    int white, black;
    white = black = 0;
    for(int row = 1; row < 9; row++){
        for(int column = 2; column < 17; column += 2){
            if(board[row][column].piece() == 'X'){
                black++;
            }
            else if(board[row][column].piece() == 'O'){
                white++;
            }
        }
    }
    if(black > white){
        return HUMAN;
    }
    else if(black < white){
        return COMPUTER;
    }
    else{
        return NEUTRAL;
    }
}