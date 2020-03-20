#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

#include "cpalsutil/cpals_util.hpp"

using namespace std;
using namespace cpals_util;


int main(int argc, char *argv[])
{
  //char * inp = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
  string inp = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
  string key = "ICE";

  vector <cpbyte> out;

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
