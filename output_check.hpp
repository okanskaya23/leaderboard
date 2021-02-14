//
//  output_check.hpp
//  Good_job_games
//
//  Created by Okan Sarp Kaya on 11.02.2021.
//

#ifndef output_check_hpp
#define output_check_hpp

#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>
#include "player.hpp"
#include <exception>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <vector>
using std::exit;
using std::memcmp;
using std::exception;
using std::ios;
using std::ifstream;
using std::cout;
using std::cerr;
using std::endl;
using namespace std;

//-!!!inefficent code use wisely
//sort data with c++ sort function in order to catch incorrect sorting operation done

class temp{
public:


    string nation;
    string name;
    int point;

};
bool comp(const temp &a, const temp &b)
{
    return a.point < b.point;
}
ifstream correct_data(){
    vector<temp> list;
    ifstream tempdata;
    string filename="data.txt";
    tempdata.open(filename.c_str());
    string line;
    int points;
    string nation , name , id;

    while(getline(tempdata, line)){
        stringstream col(line);
        col>>name>>nation>>points;
        temp temp;
        temp.nation = nation;
        temp.point = points;
        temp.name = name;
        list.push_back(temp);
        
    }
    sort(list.begin(),list.end(),comp);
    ofstream tempofstream;
    string filename1="correct_data.txt";
    tempofstream.open(filename1.c_str());
    for(int i = (int)list.size()-1 ; 0 <= i ; i--){
        tempofstream<<list[i].name<<endl;
        //cout<<list[i].point<<endl;
    }
    ifstream a;
    string fn = "correct_data.txt";
    a.open(fn);
    return a;
}

//checks if two files are equal in order the check output
bool equalFiles(ifstream& in1, ifstream& in2)
{
    ifstream::pos_type size1, size2;

    size1 = in1.seekg(0, ifstream::end).tellg();
    in1.seekg(0, ifstream::beg);

    size2 = in2.seekg(0, ifstream::end).tellg();
    in2.seekg(0, ifstream::beg);

    if(size1 != size2)
        return false;

    static const size_t BLOCKSIZE = 4096;
    size_t remaining = size1;

    while(remaining)
    {
        char buffer1[BLOCKSIZE], buffer2[BLOCKSIZE];
        size_t size = std::min(BLOCKSIZE, remaining);

        in1.read(buffer1, size);
        in2.read(buffer2, size);

        if(0 != memcmp(buffer1, buffer2, size))
            return false;

        remaining -= size;
    }

    return true;
}
#endif /* output_check_hpp */

