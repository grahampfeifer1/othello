/**
 * @file spaces.cc
 * @author your name (you@domain.com)
 * @brief 
 * @date 2022-04-06
 */

#include <iostream>
#include "spaces.h"
#include "colors.h"

using namespace std;

void Spaces::output(ostream& outs)const{
    if(p == '-'){
        outs << B_BLUE << GREEN << piece() << RESET;
    }
    else if(p == 'X'){
        outs << B_BLUE << BLACK << piece() << RESET;
    }
    else if(p == 'O'){
        outs << B_BLUE << WHITE << piece() << RESET;
    }
    else{
        outs << B_CYAN << BLACK << piece() << RESET;
    }
}

void Spaces::flip(){
    if(piece() == 'X'){
        p = 'O';
    }
    else if(piece() == 'O'){
        p = 'X';
    }
    else{
        return;
    }
}