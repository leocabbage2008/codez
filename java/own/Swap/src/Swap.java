import java.util.Scanner;

public class Swap {
	public static int swapDigits(int n) {
		int u = n%10;
		int t = (n%100-u)/10;
		return 100*(n/100)+10*u+t;
	}
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		while(true) {			
			int n = kb.nextInt();
			if((99 > n && n > 0 && (n%10==0))) {
				System.out.println("0"+swapDigits(n));
			} else {			
				System.out.println(swapDigits(n));
			}
		}
	}
}
