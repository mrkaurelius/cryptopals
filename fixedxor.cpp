#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

typedef int8_t byte;


using namespace std;


vector<byte> hex2byte( string inp ){
    vector<byte> ret;

     for (int i = 0; i < inp.size(); i+=2) {
         string sub_string = inp.substr(i, 2);
         ret.push_back(strtol(sub_string.c_str(), nullptr, 16));
     }

    return ret;
}

vector<byte> fixed_xor(vector<byte> key,vector<byte> inp){
    vector<byte> ret;

    for (int i = 0; i < inp.size(); ++i) {
        ret.push_back(key[i] ^ inp[i]);
    }

    return ret;
}


int main(int argc, char *argv[])
{

    // fonksyon cagirmalarinda "best practice" ları implement et
    // degiskenlerin referanslarını fonksyonlara gondermek ne kadar fark ettirir ?
    string hex_input_string = "1c0111001f010100061a024b53535009181c";
    string hex_xor_key = "686974207468652062756c6c277320657965";


    // bu problemlere yol acar mı ?
    if ( hex_input_string.size() % 2 != 0 ) {
        std::cout << "stringi even yap" << std::endl;
        hex_input_string.insert(0, "0");
    }

    vector<byte> input_bytes = hex2byte( hex_input_string );
    vector<byte> xor_key_bytes = hex2byte( hex_xor_key );
    vector<byte> output = fixed_xor(input_bytes, xor_key_bytes);

    for ( auto i: output ) std::cout << i;
    std::cout << std::endl;

    return 0;
}
