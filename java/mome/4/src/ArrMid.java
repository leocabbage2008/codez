import java.util.Arrays;

public class ArrMid {
	public static int[] findMiddle(int[] A) {
		int n = A.length;
		
		if(n%2 == 0) {
			int[] B = new int[2];
			B[0] = A[n/2-1];
			B[1] = A[n/2];
			return B;
		}
		else if (n%2 == 1) {
			int[] B = new int[3];
			B[0] = A[(n-3)/2];
			B[1] = A[(n-1)/2];
			B[2] = A[(n+1)/2];
			return B;
		}
		return null;
	}
	
	public static void printArray(int[] B) {
		for(int i = 0; i < B.length; i++) {
			System.out.print(B[i]+" ");
		}
		System.out.println();
	}
	
	public static void main(String[] args) {
		int[] A1 = { 1, 2, 3, 4, 5, 100, 1000};
		printArray(findMiddle(A1)); //output: 2 3 4
		int[] A2 = { 1, 2, 3, 4, 5, 6 };
		printArray(findMiddle(A2)); //output: 3 4
		System.out.println( Arrays.toString(A1) );
	}
}
