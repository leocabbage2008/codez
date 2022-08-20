package test;

import java.util.Arrays;

public class Main {
    public static int[] remove(int[] arr, int n){
    	int[] arr_new = new int[arr.length-1];
        for(int i=0, k=0;i<arr.length;i++){
            if(i!=n){
                arr_new[k]=arr[i];
                k++;
            }
        }
        return arr_new;
    }
    public static int largestPerimeter(int[] nums) { 
        Arrays.sort(nums);
        for(int i = 0; i < nums.length / 2; i++){
            int temp = nums[i];
            nums[i] = nums[nums.length - i - 1];
            nums[nums.length - i - 1] = temp;
        }
        System.out.println(Arrays.toString(nums));
		for(int x = 0; x < nums.length; x++){
            int[] arr0 = remove(nums,x);
            for(int y = 0; y < nums.length-1; y++){
                int[] arr1 = remove(arr0,y);
                for(int z = 0; z < nums.length-2; z++){
                    int a = nums[x];
                    int b = arr0[y];
                    int c = arr1[z];
                    if((a+b>c)&&(a+c>b)&&(b+c>a)){
                        return a+b+c;
                    }
                }
            }
        }
        return 0;
	}
    public static void main(String[] args) {
    	int[] nums = {1,2,4,235,546,54,865,576,56,34,354,354,354,4567,5678,5678,345,63456,2345,24352345};
    	System.out.println(largestPerimeter(nums));
    }
}
