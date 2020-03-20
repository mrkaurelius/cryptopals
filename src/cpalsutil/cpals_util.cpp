#include <iostream>
#include <string>
#include "cpals_util.hpp"

namespace  cpals_util
{

  int score_message(std::vector <cpbyte> inp){
    int score = 0;
    std::string rate = "ETAOINSHRDLU";
    for (int i = 0; i < inp.size(); ++i) {
      // using is ascii is more sensible ?
      if( isprint( (char)inp[i]) == 0 && inp[i] != '\n'){
        return 0;
      }

      for (int j = 0; j < rate.size(); ++j) {
        if ( toupper((char)inp[i]) == rate[j] ) {
          score += 12 - j;
          break;
        }

      }
    }

    return score;
  }

  std::vector<cpbyte> single_byte_xor(uint8_t key, std::vector<cpbyte> inp){
    std::vector<cpbyte> ret;

    for (int i = 0; i < inp.size(); ++i) {
      ret.push_back(key ^ inp[i]);
    }

    return ret;
  }

  std::vector<cpbyte> hex2byte( std::string inp ){
      std::vector<cpbyte> ret;

      for (int i = 0; i < inp.size(); i+=2) {
          std::string sub_string = inp.substr(i, 2);
          ret.push_back(strtol(sub_string.c_str(), nullptr, 16));
          // printf("%d-%x-%c\n",ret[i/2],ret[i/2],ret[i/2]);
      }

      return ret;
  }

  std::string byte2base64str( std::vector<cpbyte> inp ){
      std::string base64_string;
      static const unsigned char base64_table[65] =
          "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

      // 1. baytı 2 saga kaydır 1. 00XXXXXX
      // 1. baytı 0x03 ile & ile 4 sola kaydır | 2. baytı 4 saga kaydır  
      // 00XX0000 | 0000XXXX  
      //  2. baytı 0x0f ile & 2 sola kaydır | 3. baytı 6 saga kaydır 
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
    

  std::vector<cpbyte> fixed_xor(std::vector<cpbyte> key,std::vector<cpbyte> inp){
      std::vector<cpbyte> ret;

      for (int i = 0; i < inp.size(); ++i) {
          ret.push_back(key[i] ^ inp[i]);
      }

      return ret;
  }

}