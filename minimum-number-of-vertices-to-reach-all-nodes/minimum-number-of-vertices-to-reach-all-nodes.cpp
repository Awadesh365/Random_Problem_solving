class Solution {
public:
  // POD:- 
// Learned about how to write sols for graphs
vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
{
    // List ot signify if the vertex has an incoming edge or not.
    vector<bool> isIncomingEdgExst(n, false);
    for(vector<int>&edge :edges)
        isIncomingEdgExst[edge[1]] = true;

    vector<int> reqNodes;
    for (int i = 0;i<n;i++){
        // store all the nodes that don't have an incoming edge.
        if(!isIncomingEdgExst[i]){
            reqNodes.push_back(i);
        }
    }
    return reqNodes;
}
};