#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

#include "cpalsutil/cpals_util.hpp"

using namespace cpals_util;
using namespace std;

int main(int argc, char *argv[])
{
    // fonksyon cagirmalarinda "best practice" ları implement et
    // degiskenlerin referanslarını fonksyonlara gondermek ne kadar fark ettirir ?
    string input_string = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f";

    if (argc == 2){
        input_string = argv[1];
    }

    // bu problemlere yol acar mı ?
    if ( input_string.size() % 2 != 0 ) {
        cout << "stringi even yap" << endl;
        input_string.insert(0, "0");
    }

    vector<cpbyte> input_bytes = hex2byte( input_string );
    string base64_string = byte2base64str( input_bytes );
    cout << base64_string << endl;
    
    //for ( auto i: input_bytes ) cout << i;

    return 0;
}