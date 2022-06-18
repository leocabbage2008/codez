import java.util.*;

public class Factor {
	public static int[] getFactors(int n) {
		int c = 0;
		for(int i = 1; i <= n; i++) {
			if(n%i == 0) c++;
		}
		int[] A = new int[c];
		c=0;
		for(int i = 1; i <= n; i++) {
			if(n%i == 0) {
				A[c]=i;
				c++;
			}
		}
		return A;
	}
	public static void main(String[] args) {
		System.out.println(Arrays.toString(getFactors(45)));
	}
}
