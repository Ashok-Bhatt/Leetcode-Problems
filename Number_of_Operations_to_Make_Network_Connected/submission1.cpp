class DisJointSet{
private:
    int n;
    vector<int> ranks, parent;

public:
    DisJointSet(int n){
        ranks.resize(n, 0);
        parent.resize(n);
        this->n = n;
        for (int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int findUltimateParent(int node){
        if (node == parent[node]) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    int findNoOfComponents(){
        int ans = 0;
        for (int i=0; i<n; i++){
            if (i==parent[i]){
                ans++;
            }
        }
        return ans;
    }

    void unionByRank(int u, int v){
        int upar_u = findUltimateParent(u), upar_v = findUltimateParent(v);
        if (ranks[upar_u] > ranks[upar_v]){
            parent[upar_v] = upar_u;
        } else if (ranks[upar_u] < ranks[upar_v]){
            parent[upar_v] = upar_u;
        } else {
            parent[upar_v] = upar_u;
            ranks[upar_u]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int e = connections.size();
        DisJointSet* ds = new DisJointSet(n);

        if (e < n-1) return -1;

        for (int i=0; i<e; i++){
            int u = connections[i][0], v = connections[i][1];
            if (ds->findUltimateParent(u) == ds->findUltimateParent(v)) continue;
            ds->unionByRank(u, v);
        }

        int components = ds->findNoOfComponents();
        return components-1;
    }
};