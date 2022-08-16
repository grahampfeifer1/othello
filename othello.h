/**
 * @file othello.h
 * @author Graham Pfeifer
 * @brief Declaration of the othello class for the final CS 2401 project
 * @date 2022-04-05
 */

#include <iostream>
#include "game.h"
#include "spaces.h"

using namespace std;
using namespace main_savitch_14;

class Othello:public game{
    public:
        Othello();
        void make_move(const std::string& move);
        void restart();
        game* clone()const;
        void compute_moves(std::queue<std::string>& moves)const;
        void display_status()const;
		int evaluate()const;
		bool is_game_over()const;
		bool is_legal(const std::string& move)const;
        who winning()const;
    private:
        Spaces board[9][18];
};