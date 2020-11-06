#include <iostream>
#include "fstream"
#include "../json/json.hpp"
#include "../header/Tree.h"

using json  = nlohmann::json;
using namespace std;


int main(int argc, char** argv){
    std::cout << "Hello, World!" << std::endl;


   // if(argc != 2){
    //    cout << "usage cTrace <config_path>" << endl;
      //  return 0;
  //  }


  ifstream i("../json/config1.json");
  json j;
  j<<i;
   cout <<j["graph"]<< endl;

    //Session sess(argv[1]);
    //sess.simulate();
    return 0;
}

