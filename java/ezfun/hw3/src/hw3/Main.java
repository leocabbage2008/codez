package hw3;

public class Main {
	public static void table(int n) {
		System.out.print("* |");
		for(int i = 1; i<=n; i++) {
			System.out.print("\t"+i);
		}
		System.out.println();
		for(int i = 0; i<n; i++) {			
			System.out.print("--------");
		}
		System.out.println();
		for(int i = 1; i<=n; i++) {
			System.out.print(i+" |");
			for(int j = 1; j<=n; j++) {
				System.out.print("\t"+i*j);
			}
			System.out.println();
		}
	}
	public static int gcd(int a, int b) {
		if(b==0) return a;
		return gcd(b,a%b);
		
	}
	public static void main(String[] args) {
		table(100);
		System.out.println(gcd(20,30));
	}
}
