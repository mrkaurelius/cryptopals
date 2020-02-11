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


int main(int argc, char *argv[])
{
  //char * inp = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
  string inp = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
  string key = "ICE";

  vector <byte> out;

  for (int i = 0; i < inp.size(); i+=3) {
    out.push_back(inp[i] ^ key[0]);
    out.push_back(inp[i+1] ^ key[1]);
    out.push_back(inp[i+2] ^ key[2]);
  }

  for (int i = 0; i < out.size(); i++) {
    printf("%x",out[i]);
  }
  std::cout << std::endl;

  return 0;
}
