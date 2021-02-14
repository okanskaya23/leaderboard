//
//  generate_data.hpp
//  gjg
//
//  Created by Okan Sarp Kaya on 10.02.2021.
//

#ifndef generate_data_hpp
#define generate_data_hpp

#include <stdio.h>
#include "randgen.hpp"
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;
void random_data(int x)
{
    RandGen ran;
    int secret = ran.RandInt(1000);
    int nat_num = ran.RandInt(238);
    string nation[239] ={"AL ", "DZ ", "AS ", "AD ", "AO ", "AI ", "AQ ", "AG ", "AR ", "AM ", "AW ", "AU ", "AT ", "AZ ", "BS ", "BH ", "BD ", "BB ", "BY ", "BE ", "BZ ", "BJ ", "BM ", "BT ", "BO ", "BA ", "BW ", "BR ", "IO ", "VG ", "BN ", "BG ", "BF ", "BI ", "KH ", "CM ", "CA ", "CV ", "KY ", "CF ", "TD ", "CL ", "CN ", "CX ", "CC ", "CO ", "KM ", "CK ", "CR ", "HR ", "CU ", "CW ", "CY ", "CZ ", "CD ", "DK ", "DJ ", "DM ", "DO ", "TL ", "EC ", "EG ", "SV ", "GQ ", "ER ", "EE ", "ET ", "FK ", "FO ", "FJ ", "FI ", "FR ", "PF ", "GA ", "GM ", "GE ", "DE ", "GH ", "GI ", "GR ", "GL ", "GD ", "GU ", "GT ", "GG ", "GN ", "GW ", "GY ", "HT ", "HN ", "HK ", "HU ", "IS ", "IN ", "ID ", "IR ", "IQ ", "IE ", "IM ", "IL ", "IT ", "CI ", "JM ", "JP ", "JE ", "JO ", "KZ ", "KE ", "KI ", "XK ", "KW ", "KG ", "LA ", "LV ", "LB ", "LS ", "LR ", "LY ", "LI ", "LT ", "LU ", "MO ", "MK ", "MG ", "MW ", "MY ", "MV ", "ML ", "MT ", "MH ", "MR ", "MU ", "YT ", "MX ", "FM ", "MD ", "MC ", "MN ", "ME ", "MS ", "MA ", "MZ ", "MM ", "NA ", "NR ", "NP ", "NL ", "AN ", "NC ", "NZ ", "NI ", "NE ", "NG ", "NU ", "KP ", "MP ", "NO ", "OM ", "PK ", "PW ", "PS ", "PA ", "PG ", "PY ", "PE ", "PH ", "PN ", "PL ", "PT ", "PR ", "QA ", "CG ", "RE ", "RO ", "RU ", "RW ", "BL ", "SH ", "KN ", "LC ", "MF ", "PM ", "VC ", "WS ", "SM ", "ST ", "SA ", "SN ", "RS ", "SC ", "SL ", "SG ", "SX ", "SK ", "SI ", "SB ", "SO ", "ZA ", "KR ", "SS ", "ES ", "LK ", "SD ", "SR ", "SJ ", "SZ ", "SE ", "CH ", "SY ", "TW ", "TJ ", "TZ ", "TH ", "TG ", "TK ", "TO ", "TT ", "TN ", "TR ", "TM ", "TC ", "TV ", "VI ", "UG ", "UA ", "AE ", "GB ", "US ", "UY ", "UZ ", "VU ", "VA ", "VE ", "VN ", "WF ", "EH ", "YE ", "ZM ", "ZW "};
    ofstream out;
    string filename="data.txt";
    out.open(filename);
    for(int i = 0 ; i < x ; i++)
    {
        secret =ran.RandInt(1000);
        nat_num = ran.RandInt(238);
        out<<"name"<<to_string(i)<<" "<<nation[nat_num]<<" "<<secret<<endl;
    }
    out.close();
    
}


#endif /* generate_data_hpp */
