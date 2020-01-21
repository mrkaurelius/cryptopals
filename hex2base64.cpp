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
         // printf("%d-%x-%c\n",ret[i/2],ret[i/2],ret[i/2]);
     }

    return ret;
}

string byte2base64str( vector<byte> inp ){
    string base64_string;
    static const unsigned char base64_table[65] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    // 1. baytı 2 saga kaydır 1. 00XXXXXX
    // 1. baytı 0x03 ile & ile 4 sola kaydır | 2. baytı 4 saga kaydır  
    // 00XX0000 | 0000XXXX  
    //  2. baytı 0x0f ile & 2 sola kaydır | 3. baytı 6 saga kaydır 
    // XXXXXXXX & 00001111 = 0000XXXX << 2 => 00XXXX00 | 000000XX
    // 3. baytın son 6 altı biti 
    
    int offset = inp.size() % 3;
    if( offset == 2 ) {
        inp.push_back(0x00);
    }
    if( offset == 1 ) {
        inp.push_back(0x00);
        inp.push_back(0x00);
    }
    
    for (int i = 0; i < inp.size(); i+=3) {
        unsigned char b64_char1 = base64_table[inp[i] >> 2];
        unsigned char b64_char2 = base64_table[((inp[i] & 0x03) << 4 | (inp[i+1]>>4))];
        unsigned char b64_char3 = base64_table[((inp[i+1]&0x0f) << 2 | (inp[i+2]>>6))];
        unsigned char b64_char4 = base64_table[inp[i+2] & 0x3f];
        base64_string.push_back(b64_char1);
        base64_string.push_back(b64_char2);
        base64_string.push_back(b64_char3);
        base64_string.push_back(b64_char4);
    }

    if(offset == 2){
    base64_string[base64_string.size()-1] = '=';
    }
    if(offset == 1){
    base64_string[base64_string.size()-1] = '=';
    base64_string[base64_string.size()-2] = '=';
    }

    return base64_string;
}

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
        std::cout << "stringi even yap" << std::endl;
        input_string.insert(0, "0");
    }

    vector<byte> input_bytes = hex2byte( input_string );
    string base64_string = byte2base64str( input_bytes );
    std::cout << base64_string << std::endl;
    
    //for ( auto i: input_bytes ) std::cout << i;

    return 0;
}
