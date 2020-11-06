#include <iostream>
#include "fstream"
#include "../json/json.hpp"
#include "../header/Tree.h"
#include "../header/Graph.h"
#include "../header/Session.h"

using json  = nlohmann::json;
using namespace std;


int main(int argc, char** argv){
    std::cout << "Hello, World!" << std::endl;
    //if(argc != 2){
     //   cout << "usage cTrace <config_path>" << endl;
     //   return 0;
   // }

  ifstream i("../json/config1.json");
  json j;
  j<<i;

    //create edges, Graph builder in Session
    vector<vector<int>> matrix;
    for( auto elem:j["graph"])
    {
        matrix.push_back(elem);

    }
    string l="../json/config1.json";
    Session m(l);

   //  std::cout <<m.getTreeType() << std::endl;

      Graph *g = new Graph(matrix);
     g->infectNode(3);
     std::cout << g->isInfected(3) << std::endl;
     std::cout <<g->isInfected(4)<< std::endl;

     Tree::createTree(m,2);


  //  std::cout << j["graph"].size() << std::endl;
   /*for( auto elem:j["graph"])
   {
        //std::cout << elem << std::endl;

   }
*/

    //Session sess(argv[1]);
    //sess.simulate();
    return 0;
}

