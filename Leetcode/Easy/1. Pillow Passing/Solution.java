public class Solution {
    public int passThePillow(int n, int time) {
        int index = n - 1;
        int count = time/index;
        if(count % 2 == 0) return (time % index)+1;
        return Math.abs((time % index)-n);
    }

    public static void main(String[] args){
        Solution solution = new Solution();
        System.out.println(solution.passThePillow(9, 5));
    }
}
