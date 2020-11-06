//
// Created by spl211 on 01/11/2020.
//

#include "../header/Tree.h"
#include "queue"
#include "../header/Graph.h"
#include "../header/Session.h"

using namespace std;

Tree ::Tree(int rootLabel):node(rootLabel),children(new vector<Tree*>)
{

}
std::vector<int> Tree::getReleventChildren( std::vector<int> &GraphNeighbor, vector<int> &usedVertices)
{
    std::vector<int> *output=new vector<int>(0);
    for (int ver = 0; ver < GraphNeighbor.size(); ++ver) {
        if(GraphNeighbor[ver]==1 && (usedVertices)[ver]==0)
        {
             output->push_back(ver);
            (usedVertices)[ver]=1;
        }
    }

    return *output;
}

Tree * Tree::createTree(const Session &session, int rootLabel) {

    vector<int> usedVertices(session.getGraph().getSize());
    for (int i = 0; i < session.getGraph().getSize(); ++i) {
        usedVertices[i]=0;
    }
    queue<Tree*> *treeQueue = new queue<Tree*>();
    //push root into queue
    Tree *AbrahamTheRoot = new Tree(rootLabel);
    treeQueue->push(AbrahamTheRoot);
    Graph g=session.getGraph();

    ///////DESTROYYYYYY, get graph from session
    usedVertices[rootLabel]=1;
    while (!treeQueue->empty()) {

        Tree *tempRoot = treeQueue->front();
        treeQueue->pop();

       vector<int> child1= g.getNeighbor(tempRoot->node);
        //get the neighbors from a graph function. insert into a tree function in which it builds correct children.
        vector<int> childrenInt = tempRoot->getReleventChildren(child1,usedVertices);
        for (int child: childrenInt) {

            Tree *tempTree = new Tree(child);
            treeQueue->push(tempTree);
            tempRoot->addChild(tempTree);
            //childrenInt.push_back(tempTree->node);
        }

    }
    return AbrahamTheRoot;

}

//check later
void Tree::addChild(const Tree *child) {


    (children)->push_back(const_cast<Tree *&&>(child));
}


