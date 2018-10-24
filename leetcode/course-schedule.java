class Solution {
    private boolean dfs(boolean[][] adj, boolean[] vis, int vertex, HashSet<Integer> vertexs) {
        if(vertexs.contains(vertex)){
            vertexs.clear();
            return false;
        }
        vertexs.add(vertex);
        for (int i = 0; i < adj[vertex].length; ++i) {
            if (adj[vertex][i]) {
                if(vertexs.contains(i)){
                    return false;
                }
                if (vis[i] == false) {
                    vis[i] = true;
                    if(dfs(adj, vis, i, new HashSet<>(vertexs)) == false){
                        return false;
                    }
                }
            }
        }
        vertexs.clear();
        return true;
    }

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        boolean[][] adj = new boolean[numCourses][numCourses];
        for(int i = 0; i < adj.length; ++i){
            Arrays.fill(adj[i], false);
        }
        for (int i = 0; i < prerequisites.length; ++i) {
            adj[prerequisites[i][0]][prerequisites[i][1]] = true;
        }
        HashSet<Integer> vertexs = new HashSet<>();
        boolean[] visited = new boolean[numCourses];
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == false) {
                visited[i] = true;
                if(dfs(adj, visited, i, vertexs) == false)
                    return false;
            }
        }
        return true;
    }
}
