class DisjointSet{
public:
    int n;
    vector<int> size, parent;

    DisjointSet(int n){
        this->n = n;
        size.resize(n, 1);
        parent.resize(n);
        for (int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    void findUnion(int u, int v){
        int upar_u = findUltimateParent(u), upar_v = findUltimateParent(v);
        if (upar_u == upar_v) return;
        if (size[upar_u] < size[upar_v]){
            parent[upar_u] = upar_v;
            size[upar_v] = size[upar_v] + size[upar_u];
        } else {
            parent[upar_v] = upar_u;
            size[upar_u] = size[upar_u] + size[upar_v];
        }
    }

    int findUltimateParent(int node){
        if (node == parent[node]){
            return node;
        } else {
            return parent[node] = findUltimateParent(parent[node]);
        }
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {

        DisjointSet *ds = new DisjointSet(c);
        vector<int> active(c, true);
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> group;
        vector<int> ans;

        for (auto it : connections){
            int u = it[0]-1, v = it[1]-1;
            ds->findUnion(u, v);
        }

        for (int i=0; i<c; i++){
            group[ds->findUltimateParent(i)].push(i);
        }

        for (auto it : queries){
            int queryType = it[0], station = it[1]-1;
            if (queryType == 1){
                if (active[station]){
                    ans.push_back(station+1);
                } else {
                    bool flag = false;
                    while (group[ds->findUltimateParent(station)].size()>0){
                        int top = group[ds->findUltimateParent(station)].top();
                        if (active[top]){
                            ans.push_back(top+1);
                            flag = true;
                            break;
                        } else {
                            group[ds->findUltimateParent(station)].pop();
                        }
                    }
    
                    if (flag==false){
                        ans.push_back(-1);
                    }
                }
            } else {
                active[station] = false;
            }
        }

        return ans;
    }
};