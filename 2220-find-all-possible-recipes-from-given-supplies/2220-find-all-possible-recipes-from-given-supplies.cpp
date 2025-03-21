class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int id = 0;
        unordered_map<string, int> m; // name -> id
        for (auto &r : recipes) m[r] = id++;
        for (auto &v : ingredients) {
            for (auto &s : v) {
                if (m.count(s) == 0) m[s] = id++;
            }
        }
        vector<vector<int>> G(id);
        vector<int> indegree(id);
        for (int i = 0; i < recipes.size(); ++i) {
            for (auto &s : ingredients[i]) {
                G[m[s]].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for (auto &s : supplies) q.push(m[s]);
        vector<string> ans;
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int v : G[u]) {
                if (--indegree[v] == 0) {
                    q.push(v);
                    ans.push_back(recipes[v]);
                }
            }
        }
        return ans;
    }
};