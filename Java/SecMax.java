class SecMax{
    public static void main(String[] args) {
        int[] arr = {5, 10, 7, -1, 12};

        int mxSec = Integer.MIN_VALUE;
        int mx = Integer.MIN_VALUE;

        for(int i = 0; i < arr.length; i++){
            if(arr[i] > mx){
               mxSec = mx;
               mx = arr[i];
            }else{
                if(arr[i] < mx && arr[i] > mxSec)
                    mxSec = arr[i];
            }
        }
        System.out.println("Maximum ele:" + mx+ " " + "Second Max: " + mxSec);

    }
}