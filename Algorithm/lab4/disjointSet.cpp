#include <iostream>
#include <vector>

using namespace std;

struct node {
    int parent;
    int weight = 0;
};

int findParent(vector<node> &disjointSet, int nodeIndex) {
    int currIndex = nodeIndex;
    while(disjointSet.at(currIndex).parent != currIndex) {
        currIndex = disjointSet.at(currIndex).parent;
    }
    return currIndex;
}

void disjointUnion(vector<node> &disjointSet ,int firstNodeIndex, int secondNodeIndex) {
    int firstNodeParentIndex = findParent(disjointSet, firstNodeIndex);
    int secondNodeParentIndex = findParent(disjointSet, secondNodeIndex);
    if(disjointSet.at(firstNodeParentIndex).weight > disjointSet.at(secondNodeParentIndex).weight) {
        disjointSet.at(secondNodeIndex).parent = firstNodeParentIndex;
        disjointSet.at(firstNodeParentIndex).weight += disjointSet.at(secondNodeIndex).weight + 1;
        cout << disjointSet.at(secondNodeIndex).weight + 1 << endl;
    } else {
        disjointSet.at(firstNodeIndex).parent = secondNodeParentIndex;
        disjointSet.at(secondNodeParentIndex).weight += disjointSet.at(firstNodeIndex).weight + 1;
    }
}

int main() {
    vector<node> disjointSet;

    int numOfNodes = 6;

    for(int i = 0; i < numOfNodes; i++)
    {
        node newNode;
        newNode.parent = i;
        disjointSet.push_back(newNode);
    }

    int firstNodeIndex;
    int secondNodeIndex;

    cin >> firstNodeIndex;
    cin >> secondNodeIndex;
    while(firstNodeIndex != -1 || secondNodeIndex != -1) {
        disjointUnion(disjointSet, firstNodeIndex, secondNodeIndex);
        cin >> firstNodeIndex;
        cin >> secondNodeIndex;
    }

    int count = 0;
    for(auto currNode : disjointSet)
    {
        cout << count++ << " Parent: " << currNode.parent << " Weight: " << currNode.weight << endl;
    }

    return 0;
}