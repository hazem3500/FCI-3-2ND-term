#include <iostream>
#include <vector>

using namespace std;

class node {
    public:
    vector<int> edges;
    node(){};
};

int main() {
    vector<node> graph;

    int firstNodeValue = 0;
    int secondNodeValue = 0;

    for(int i = 0; i < 5; i++)
    {
        node tempNode = node();
        graph.push_back(tempNode);
    }
    

        cin >> firstNodeValue;
        cin >> secondNodeValue;
    while((firstNodeValue != -1 || secondNodeValue != -1) && !(firstNodeValue > graph.size() || secondNodeValue > graph.size())) {
        graph.at(firstNodeValue).edges.push_back(secondNodeValue);
        graph.at(secondNodeValue).edges.push_back(firstNodeValue);
        cin >> firstNodeValue;
        cin >> secondNodeValue;
    }

    for(int i = 0; i < graph.size(); i++)
    {
        cout << i << ": ";
        for(int j = 0; j < graph.at(i).edges.size(); j++)
        {
            cout << graph.at(i).edges.at(j) << " ";
        }
        cout << endl;
    }
    

    cout << "End";
    return 0;
}