class MostContainerWater {
    public static void main(String[] args) {
        int []arr = {1,8,6,2,5,4,8,3,7};

        int i = 0;
        int e = arr.length-1;
        int maxi = 0;

        while(i <= e){
            int lenth = e-i;
            if(arr[i] < arr[e]){
                maxi = Math.max(maxi, arr[i++]*lenth);
            }else{
                maxi = Math.max(maxi, arr[e--]*lenth);
            }
        }

        System.out.println("Most Water : "+ maxi );
    }
}