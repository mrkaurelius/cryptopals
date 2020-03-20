#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <fstream>

#include "cpalsutil/cpals_util.hpp"

using namespace cpals_util;
using namespace std;

bool compareScore(mspair_t a, mspair_t b)
{
  return (a.score > b.score);
}

void bulk_score( string inp ){
  string hex_string = inp;
  vector <cpbyte> byte_string = hex2byte(hex_string);
  vector <mspair_t> pairs;

  for (uint i = 0; i < 256; ++i) {
    vector <cpbyte> iter = single_byte_xor(i, byte_string);
    if ( int score = score_message(iter) ) {
      mspair_t tmp;
      tmp.message = iter;
      tmp.score = score;
      pairs.push_back(tmp);
    }
  }

  if( pairs.size() == 0 ){
    return;
  }

  sort(pairs.begin(), pairs.end(), compareScore);
  for (int i = 0; i < pairs.size(); ++i) {
    for (char m: pairs[i].message)
      cout << m;
    cout << ", score: " << pairs[i].score << endl;
    if (i == 4) {
      break;
    }
  }

}

int main(int argc, char *argv[])
{

  // Now that the party is jumping
  // 7b5a4215415d544115415d5015455447414c155c46155f4058455c5b523f

  // open file get lines as string and send bulk score
  ifstream file("../4.txt");
  // 
  string str;
  while (getline(file, str)) {
    cout << "------------------------------------------------------------\n" << str << "\n";
    bulk_score( str );
  }

  return 0;
}