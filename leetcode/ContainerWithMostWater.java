class Solution{
    public int maxArea(int[] height) {
        int nsolu = 0;
        int[] buf = new int[2];
        buf[1] = -1; // dummy
        for(int i = 0; i < height.length; ++i){
            buf[0] = height[i];
            for(int j = i+1; j < height.length; ++j){
                buf[1] = height[j];
                if(buf[1] != -1){
                    int area = Math.abs(j-i)*Math.min(buf[1], buf[0]);
                    if(area>nsolu)
                        nsolu = area;
                    buf[1] = -1;
                }
            }
        }
        System.out.println(nsolu);
        return nsolu;
    }
}
