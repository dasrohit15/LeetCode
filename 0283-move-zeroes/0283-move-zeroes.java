class Solution {
    static void swap(int[]arr,int i ,int j){
        int temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }

    public void moveZeroes(int[] arr) {
        int i=0;
        for(int j=0;j<arr.length;j++){
            if(arr[j]!=0){
                swap(arr,i,j);
                i++;
            }
        }
    }
}