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
    string hex_input_string = "1c0111001f010100061a024b53535009181c";
    string hex_xor_key = "686974207468652062756c6c277320657965";


    // bu problemlere yol acar mı ?
    if ( hex_input_string.size() % 2 != 0 ) {
        cout << "stringi even yap" << endl;
        hex_input_string.insert(0, "0");
    }

    vector<cpbyte> input_bytes = hex2byte( hex_input_string );
    vector<cpbyte> xor_key_bytes = hex2byte( hex_xor_key );
    vector<cpbyte> output = fixed_xor(input_bytes, xor_key_bytes);

    for ( auto i: output ) cout << i;
    cout << endl;

    return 0;
}
