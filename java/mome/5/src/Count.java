import java.util.*;

public class Count {
	public static void main(String[] args) {
		int[] mLengths = {31,28,31,30,31,30,31,31,30,31,30,31};
		int sum = 0;
		
		Scanner _m = new Scanner(System.in);
		System.out.print("Input m: ");
		int m = _m.nextInt();
		
		Scanner _d = new Scanner(System.in);
		System.out.print("Input d: ");
		int d = _d.nextInt();

		Scanner _m1 = new Scanner(System.in);
		System.out.print("Input m1: ");
		int m1 = _m1.nextInt();
		
		Scanner _d1 = new Scanner(System.in);
		System.out.print("Input d1: ");
		int d1 = _d1.nextInt();
		
		for(int i = m1; i <= m1+1; i++) {
			sum += mLengths[i];
		}

		sum+=d1-d-1;
		
		System.out.println(sum);
	}
}
