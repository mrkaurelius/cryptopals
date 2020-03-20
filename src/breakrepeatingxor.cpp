#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <b64/decode.h>
#include <cstring>
#include <fstream>

#include "cpalsutil/cpals_util.hpp"

using namespace std;
using namespace cpals_util;


// calc hamming distance in bit wise 
int one_bit_count(int inp){
  int ret = 0;
  for (int i = 0; i < 8; ++i) {
    int bit = (inp >> i) & 0x01;
    if (bit)
      ret++;
  }
  return ret;
}

int hamming_distance( string str1, string str2 ){
  if ( str1.size() != str2.size() ) {
    std::cout << "strings sizes not equal" << std::endl;
    exit(EXIT_FAILURE);
  }

  int hamming_diff = 0;
  for (int i = 0; i < str1.size(); ++i) {
   hamming_diff += one_bit_count( str1[i] ^ str2[i] );
  }
  return hamming_diff;
}

// keysize 2 to 40
int main(int argc, char *argv[])
{
  //base64::decoder D;
  //char * inp = (char *)"ZGVuZW1l";
  //char * out = (char *)malloc(sizeof(char) * BUFSIZ);
  //D.decode(inp, strlen(inp), out);
  
  std::ifstream file("6.txt");
  string line;
 
  // BURADA KALDIM
  //std::cout << hamming_distance("this is a test","wokka wokka!!!") << std::endl;
  std::cout << hamming_distance("this is a test","wokka wokka!!!") << std::endl;

  return 0;
}