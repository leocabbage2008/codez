import java.util.Random;

public class EvenArr {
	public static void main(String[] args) {
		
		Random gen = new Random(1);
		int n = 10;
		int[] A = new int[n];
		int evenCount = 0;
		
		for(int i = 0; i < n; i++) {
			int random = gen.nextInt(100)-50;
			A[i] = random;
			System.out.println(random);
		}
		
		for(int i = 0; i < n; i++) {
			if(A[i]%2==0) evenCount++;
		}
		
		System.out.println(evenCount);
	}
}
