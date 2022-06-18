
public class ArrDiff {
	public static void main(String[] args) {
		int[] A = {2,3,4,12,34,23,3,};
		int min = A[0], max = A[0]; 		
		for(int i = 0; i < A.length; i++) {
			final int n = A[i];
			if(n>max) max = n;
			if(n<min) min = n;
		}
		
		System.out.println(max-min);
	}
}
