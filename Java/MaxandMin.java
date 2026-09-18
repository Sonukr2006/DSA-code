class MaxandMin{
    public static void main(String[] args) {
        int []arr = {9,6,4,2,3,5,7,0,1};

        int mini = 10;
        int maxi = -1;

        for(int i =0; i < arr.length; i++){
            if(maxi < arr[i])
                maxi = arr[i];
            if(mini > arr[i])
                mini = arr[i];
        }

        System.out.println("Maximum :"+ maxi +" "+ "Minimum: " + mini);
    }
}