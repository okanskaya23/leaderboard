//
//  main.cpp
//  gjg
//
//  Created by Okan Sarp Kaya on 9.02.2021.
//
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <chrono>
#include <vector>
#include <unordered_map>
#include<curl/curl.h>
#include "generate_data.hpp"
#include "OSRBT.hpp"
#include "player.hpp"
//#include "queue.h"
#include "output_check.hpp"

#define M 1000000
#define test
#define new_data
using namespace std;




int main()
{
#ifdef new_data
    random_data(M);
#endif
    
    //create a hash table key -> country name  value is countrys leader board
    unordered_map<string, RBTree> country_lb;
    string country_code[239] = {"AL ", "DZ ", "AS ", "AD ", "AO ", "AI ", "AQ ", "AG ", "AR ", "AM ", "AW ", "AU ", "AT ", "AZ ", "BS ", "BH ", "BD ", "BB ", "BY ", "BE ", "BZ ", "BJ ", "BM ", "BT ", "BO ", "BA ", "BW ", "BR ", "IO ", "VG ", "BN ", "BG ", "BF ", "BI ", "KH ", "CM ", "CA ", "CV ", "KY ", "CF ", "TD ", "CL ", "CN ", "CX ", "CC ", "CO ", "KM ", "CK ", "CR ", "HR ", "CU ", "CW ", "CY ", "CZ ", "CD ", "DK ", "DJ ", "DM ", "DO ", "TL ", "EC ", "EG ", "SV ", "GQ ", "ER ", "EE ", "ET ", "FK ", "FO ", "FJ ", "FI ", "FR ", "PF ", "GA ", "GM ", "GE ", "DE ", "GH ", "GI ", "GR ", "GL ", "GD ", "GU ", "GT ", "GG ", "GN ", "GW ", "GY ", "HT ", "HN ", "HK ", "HU ", "IS ", "IN ", "ID ", "IR ", "IQ ", "IE ", "IM ", "IL ", "IT ", "CI ", "JM ", "JP ", "JE ", "JO ", "KZ ", "KE ", "KI ", "XK ", "KW ", "KG ", "LA ", "LV ", "LB ", "LS ", "LR ", "LY ", "LI ", "LT ", "LU ", "MO ", "MK ", "MG ", "MW ", "MY ", "MV ", "ML ", "MT ", "MH ", "MR ", "MU ", "YT ", "MX ", "FM ", "MD ", "MC ", "MN ", "ME ", "MS ", "MA ", "MZ ", "MM ", "NA ", "NR ", "NP ", "NL ", "AN ", "NC ", "NZ ", "NI ", "NE ", "NG ", "NU ", "KP ", "MP ", "NO ", "OM ", "PK ", "PW ", "PS ", "PA ", "PG ", "PY ", "PE ", "PH ", "PN ", "PL ", "PT ", "PR ", "QA ", "CG ", "RE ", "RO ", "RU ", "RW ", "BL ", "SH ", "KN ", "LC ", "MF ", "PM ", "VC ", "WS ", "SM ", "ST ", "SA ", "SN ", "RS ", "SC ", "SL ", "SG ", "SX ", "SK ", "SI ", "SB ", "SO ", "ZA ", "KR ", "SS ", "ES ", "LK ", "SD ", "SR ", "SJ ", "SZ ", "SE ", "CH ", "SY ", "TW ", "TJ ", "TZ ", "TH ", "TG ", "TK ", "TO ", "TT ", "TN ", "TR ", "TM ", "TC ", "TV ", "VI ", "UG ", "UA ", "AE ", "GB ", "US ", "UY ", "UZ ", "VU ", "VA ", "VE ", "VN ", "WF ", "EH ", "YE ", "ZM ", "ZW "};
    for(int i = 0 ; i < 239 ; i++){
        country_lb[country_code[i]];
    }
    //--------------------------------------------------------------------------
    
    unordered_map<string, Node*[2]> users;
    int counter = 0;
    RBTree tree;
    ifstream data;
    string filename="data.txt";
    data.open(filename.c_str());
    string line;
    int points;
    string nation , name , id;
    while(getline(data, line)){
        counter++;
        stringstream col(line);
        col>>name>>nation>>points;
        
        Node* temp0 = tree.Insert(new Node(points,NULL,nation,name));
        Node* temp1 = country_lb[nation].Insert(new Node(points,NULL,nation,name));
        users[name][0]=temp0;
        users[name][1]=temp1;
    }
    

//    for(int i = counter ; 0 < i  ; i-- ){
//        cout<<tree.Select(tree.root, i)->name<<endl;
//
//    }
    
    
    
    
    
    //cout<<endl<<endl<<endl<<endl<<endl<<"------------------------------------------------------"<<endl;
    //tree.Delete(users["name754"][0]);
//    cout<<users["name754"][0]-><<endl;
    //country_lb[users["name754"][0]->nation].Delete(users["name754"][1]);
    
#ifdef test
    auto start = std::chrono::high_resolution_clock::now();
#endif
    ofstream out;
    string name_of_file = "output.txt";
    out.open(name_of_file.c_str());
    for(int i = counter ; 0 < i  ; i-- ){
        if(tree.Select(tree.root, i) != NULL)
            out<<tree.Select(tree.root, i)->name<<endl;
        
    }
#ifdef test
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time taken by function: "<< duration.count()*0.000001 << "seconds" << endl;
#endif
    
//    ifstream outputfile;
//    outputfile.open(name_of_file.c_str());
//    ifstream correct = correct_data();
//    if(equalFiles(correct,outputfile)){
//        cout<<"IT WOOOOOOORKS"<<endl;
//    }
//    tree.InOrderWalk(tree.root);

    
    
    
    cout<<"okan"<<endl;
    
#ifdef test
    auto start1 = std::chrono::high_resolution_clock::now();
#endif
    tree.Insert(new Node(123123,NULL,nation,name));

    
#ifdef test
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);
    cout << "Time taken by function: "<< duration1.count()*0.000001 << "seconds" << endl;
#endif
    
    return 0;
}
