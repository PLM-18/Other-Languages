class Main{
    public static void main(String[] args) {
        int[] array = new int[]{2,1,2,0};
        increment(array);
        for(int value : array){
            System.out.print(value+" ");
        }
        System.out.println("\n");
    }

    static void increment(int[] array){
        for(int i = array.length-1; i >= 0; i--){
            if(array[i] == 2){
                array[i] = 0;
            }else{
                array[i]++;
                break;
            }
        }
    }
}