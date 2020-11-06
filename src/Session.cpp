//
// Created by spl211 on 06/11/2020.
//
#include "../header/Session.h"
#include <iostream>
#include "fstream"
#include "../json/json.hpp"



using json  = nlohmann::json;
using namespace std;

Graph Session::getGraph()const {

    return this->g;
}

Session:: Session(const std::string &path):g() {

    ifstream i("../json/config1.json");
    json j;
    j<<i;
    vector<vector<int>> matrix;
    for( auto elem:j["graph"])
    {
        matrix.push_back(elem);

    }
    g= Graph(matrix);



    string tree = j["tree"];
    if (tree=="M")
        treeType=MaxRank;
    else if(tree=="R")
        treeType=Root;
    else if(tree=="C")
        treeType= Cycle;
    else
         std::cout <<" exception, wrong tree type " << std::endl;






}
