#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <b64/decode.h>
#include <cstring>
#include <fstream>

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

vector<byte> ascii2byte ( string inp ){
  vector<byte> ret;

  for (int i = 0; i < inp.size(); i++) {
    ret.push_back((int)inp[i]);
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
 
  //std::cout << hamming_distance("this is a test","wokka wokka!!!") << std::endl;
  std::cout << hamming_distance("this is a test","wokka wokka!!!") << std::endl;

  return 0;
}
