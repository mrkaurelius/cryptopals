#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <fstream>

typedef uint8_t byte;

using namespace std;

// message_score_pair
typedef struct mspair_t {
  int score;
  vector <byte> message;
}mspair_t;

vector<byte> hex2byte( string inp ){
  vector<byte> ret;

  for (int i = 0; i < inp.size(); i+=2) {
    string sub_string = inp.substr(i, 2);
    ret.push_back(strtol(sub_string.c_str(), nullptr, 16));
  }

  return ret;
}

vector<byte> single_byte_xor(uint8_t key,vector<byte> inp){
  vector<byte> ret;

  for (int i = 0; i < inp.size(); ++i) {
    ret.push_back(key ^ inp[i]);
  }

  return ret;
}

int score_txt(vector <byte> inp){
  int score = 0;
  string rate = "ETAOINSHRDLU";
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

bool compareScore(mspair_t a, mspair_t b)
{
  return (a.score > b.score);
}

void bulk_score( string inp ){
  string hex_string = inp;
  vector <byte> byte_string = hex2byte(hex_string);

  vector <mspair_t> pairs;

  for (int i = 0; i < 256; ++i) {
    vector <byte> iter = single_byte_xor(i, byte_string);
    if ( int score = score_txt(iter) ) {
      mspair_t tmp;
      tmp.message = iter;
      tmp.score = score;
      pairs.push_back(tmp);
    }
  }

  if( pairs.size() == 0 ){
    return;
  }

  std::sort(pairs.begin(), pairs.end(), compareScore);
  for (int i = 0; i < pairs.size(); ++i) {
    for (char m: pairs[i].message)
      std::cout << m;
    std::cout << ", score: " << pairs[i].score << std::endl;
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
  std::ifstream file("4.txt");
  std::string str;
  while (std::getline(file, str)) {
    std::cout << "------------------------------------------------------------\n" << str << "\n";
    bulk_score( str );
  }

  return 0;
}
