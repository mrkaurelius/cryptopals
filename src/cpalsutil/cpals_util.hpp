#include <vector>

namespace  cpals_util
{

  typedef uint8_t cpbyte;
  
  int score_message(std::vector <cpbyte> inp); // change function name
  std::vector<cpbyte> single_byte_xor(uint8_t key,std::vector<cpbyte> inp);
  std::vector<cpbyte> hex2byte(std::string inp);
  std::string byte2base64str(std::vector<cpbyte> inp);
  std::vector<cpbyte> fixed_xor(std::vector<cpbyte> key,std::vector<cpbyte> inp);

  // message_score_pair
  typedef struct mspair_t {
    int score;
    std::vector <cpbyte> message;
  }mspair_t;


}