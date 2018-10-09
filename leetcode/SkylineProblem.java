class Solution{
    private void processPoint(int[] points, ArrayList<int[]> as, TreeMap<Integer, ArrayList<int[]>> tm){
        for(int i = 0; i < points.length; ++i){
            for(int j = 0; j < as.size(); ++j){
                int[] t = as.get(j);
                if(points[i]<t[0])
                    break;
                if(points[i] >= t[0] && points[i] <= t[1]){
                    ArrayList<int[]> al;
                    if(tm.containsKey(points[i])){
                        al = tm.get(points[i]);
                    }
                    else {
                        al = new ArrayList<>();
                    }
                    al.add(t);
                    tm.put(points[i], al);
                }
            }
        }
    }
    public int calcValue(Integer point, ArrayList<int[]> Buildings){
        int height = 0;
        boolean all = true;
        for(int i = 0; i < Buildings.size(); ++i){
            if(Buildings.get(i)[1] != point){
                all = false;
            }
        }
        if(all){
            return height;
        }
        for(int i = 0; i < Buildings.size(); ++i){
            if(Buildings.get(i)[2] > height && Buildings.get(i)[1] != point){
                height = Buildings.get(i)[2];
            }
        }
        return height;
    }
    private boolean isIgnored(ArrayList<int[]> bs, int x1, int x2, int h){
        for(int[] point : bs){
            if(x1 >= point[0] && x2 <= point[1])
                if(h < point[2])
                    return true;

        }
        return false;
    }
    public List<int[]> getSkyline(int[][] buildings) {
        List<int[]> skyline = new ArrayList<>();
        ArrayList<int[]> as = new ArrayList<>();
        ArrayList<Integer> set = new ArrayList<>();
        for(int i = 0; i < buildings.length; ++i){
            if(false == isIgnored(as, buildings[i][0], buildings[i][1], buildings[i][2])){
                as.add(buildings[i]);
            }
        }

        int[] points = new int[as.size()*2];
        int index = 0;
        for(int[] p : as){
           points[index++] = p[0];
           points[index++] = p[1];
        }
        Arrays.sort(points);
        TreeMap<Integer, ArrayList<int[]>> tm = new TreeMap<>();
        processPoint(points, as, tm);

        for(Integer point : tm.keySet()){
            int[] v2 = new int[2];
            v2[0] = point;
            v2[1] = calcValue(point, tm.get(point));
            if(skyline.size() == 0 || skyline.get(skyline.size()-1)[1] != v2[1]) {
                skyline.add(v2);
            }
        }
        return skyline;
    }
}
