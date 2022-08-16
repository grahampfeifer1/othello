/**
 * @file spaces.h
 * @author Graham Pfeifer
 * @brief 
 * @date 2022-04-05
 */

#include <iostream>

class Spaces{
    public:
        Spaces(){p = '-';}
        void output(std::ostream& outs)const;
        void flip();
        void set_piece(char piece) {p = piece;}
        char piece()const {return p;}
    private:
        char p;
};