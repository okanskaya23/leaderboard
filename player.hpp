//
//  player.hpp
//  gjg
//
//  Created by Okan Sarp Kaya on 10.02.2021.
//

#ifndef player_hpp
#define player_hpp
#include <stdio.h>
#include <string>

using namespace std;
struct player
{
public:
    int rank;
    string display_name;
    int points;
    string country;
    int color;
    player *left, *right, *parent, *next;
    explicit player( int x, string dpn){
        points= x;
        display_name = dpn;
    }
    



};
#endif /* player_hpp */
