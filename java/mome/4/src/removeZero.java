import java.util.Arrays;

public class removeZero {
	public static void main(String[] args) {
		int[] A = {0,4,0,2,3,40,5,0,23};
		int n = A.length;
		int z = 0;
		for(int i = 0; i < n; i++) {
			if(A[i] == 0) z++;
		}
		int[] B = new int[n-z];
		int c = 0;
		
		for(int i = 0; i < n; i++) {
			if(!(A[i] == 0)) {
				B[c] = A[i];
				c++;
			}
		}
		System.out.println(Arrays.toString(B));
	}
}
