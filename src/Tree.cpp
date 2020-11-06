//
// Created by spl211 on 01/11/2020.
//

#include "../header/Tree.h"
#include "queue"
#include "../header/Graph.h"

using namespace std;

Tree ::Tree(int rootLabel):node(rootLabel),children(new vector<Tree*>),usedVertices(new vector <int>)
{}
std::vector<int> Tree::getReleventChildren(std::vector<int> &GraphNeighbor)
{
    std::vector<int> *output=new vector<int>(0);
    for (int ver = 0; ver < GraphNeighbor.size(); ++ver) {
        if(GraphNeighbor[ver]==1 && (*usedVertices)[ver]==0)
        {
             output->push_back(ver);
            (*usedVertices)[ver]=1;
        }
    }

    return *output;
}

Tree * Tree::createTree(const Session &session, int rootLabel) {
    queue<Tree*> *treeQueue = new queue<Tree*>();
    //push root into queue
    treeQueue->push(new Tree(rootLabel));

    ///////DESTROYYYYYY, get graph from session

    const Graph *g = new Graph();

    while (!treeQueue->empty()) {

        Tree *tempRoot = treeQueue->front();
        treeQueue->pop();

        //get the neighbors from a graph function. insert into a tree function in which it builds correct children.
        vector<int> childrenInt = tempRoot->getReleventChildren(*( g->getNeighbor(tempRoot->node)));
        for (int child: childrenInt) {
            Tree *tempTree = new Tree(child);
            treeQueue->push(tempTree);
            tempRoot->addChild(*tempTree);
            childrenInt.push_back(tempTree->node);
        }

    }

}

//check later
void Tree::addChild(const Tree &child) {

    Tree* temp = new Tree (child.node);
    (children)->push_back(temp);
}


