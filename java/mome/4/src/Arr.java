import java.util.*;

public class Arr {
	public static void main(String[] args) {
		
		int[] nums = new int[6];
		
		for(int i = 0; i < nums.length; i++) {
			System.out.print("Enter a number: ");
			Scanner input = new Scanner(System.in);
			nums[i]=input.nextInt();
			System.out.println(nums[i]+" has successfully been added at index "+i);
		}
		
		System.out.println(nums.toString());
	}
}
