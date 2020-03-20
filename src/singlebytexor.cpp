#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

#include "cpalsutil/cpals_util.hpp"

using namespace std;
using namespace cpals_util;


bool compareScore(mspair_t a, mspair_t b)
{
  return (a.score > b.score);
}

int main(int argc, char *argv[])
{

  string hex_string = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
  vector <cpbyte> byte_string = hex2byte(hex_string);

  vector <mspair_t> pairs;
  for (int i = 0; i < 256; ++i) {
    vector <cpbyte> iter = single_byte_xor(i, byte_string);
    if ( int score = score_message(iter) ) {
      mspair_t tmp;
      tmp.message = iter;
      tmp.score = score;
      pairs.push_back(tmp);
    }
  }

  std::sort(pairs.begin(), pairs.end(), compareScore);

  for (int i = 0; i < 5; ++i) {
    for (char m: pairs[i].message)
      std::cout << m;

    std::cout << ", score: " << pairs[i].score << std::endl;
  }

  return 0;
}