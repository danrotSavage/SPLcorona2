//
// Created by spl211 on 01/11/2020.
//

#include "Tree.h"
#include "queue"
using namespace std;

std::vector<int> Tree::getReleventChildren(std::vector<int> &GraphNeighbor)
{
    std::vector<int>* output=new vector<int>(0);
    for (int ver = 0; ver < GraphNeighbor.size(); ++ver) {
        if(GraphNeighbor[ver]==1&&usedVertices[ver]==0)
        {
             *output->push_back(ver);
             usedVertices[ver]=1;
        }
    }

    return output;
}
Tree * Tree::createTree(const Session &session, int rootLabel)
{

    queue<int>* treeQueue=new queue<int>();
    treeQueue->push(rootLabel);
    while (!treeQueue->empty())
    {
        int x=treeQueue->pop();
        Tree* tempRoot=new Tree(x);
        vector<int> childrenInt= tempRoot->getReleventChildren(x);
        for(int child: childrenInt)
        {
            treeQueue->push(child);
            Tree* tempTree=new Tree(child);
            children.push_back(tempTree);
        }

    }
    for(int ver:getReleventChildren(rootLabel)){

    }
}
