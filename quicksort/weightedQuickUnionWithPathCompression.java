//java union find
//detail interpretation: https://segmentfault.com/a/1190000012898131
class weightedQuickUnionWithPathCompression{
    private int[] ids;
    private int[] sizes;
    public weightedQuickUnionWithPathCompression(int n) {
        ids = new int[n];
        sizes = new int[n];
        for(int i = 0; i < n; i++) {
            ids[i] = i;
            sizes[i] = 1;
        }
    }
    public int root(int a, int b) {
        int root = a;
        while(ids[root] != root) {
            root = ids[root];
        }
        while(a != root) { //connect sub element directly to root
            int temp = ids[a];
            ids[a] = root;
            a = temp;
        }
        return root;
    }
    public boolean find(int a, int b) {
        return root(a) == root(b);
    }
    public boolean union(int a, int b) {
        int rootA = ids[a];
        int rootB = ids[b];
        if(sizes[rootA] > sizes[rootB]) {
            ids[rootB] = rootA;
            sizes[rootA] += sizes[rootB];
        } else {
            ids[rootA] = ids[rootB];
            sizes[rootB] += sizes[rootA];
        }
    }
 }

