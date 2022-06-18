package hw1;

public class Main {
	public static int sumTo(int n) {
		return n*(n+1)/2;
	}
	public static void main(String[] args) {
//		Question 1:
		for(int i = 1; i<=9; i++) {
			for(int n = 0; n <= 9-i; n++) {
				System.out.print(' ');
			}
			for(int j = 0; j <= 2*i-1; j++) {
				System.out.print(i);
			}
			System.out.println();
		}
		System.out.println("--------------------");
		for(int i = 1; i<=9; i++) {
			for(int n = 0; n <= 9-i; n++) {
				System.out.print(' ');
			}
			for(int j = 1; j <= i; j++) {
				System.out.print(j);
				System.out.print(j);
			}
			System.out.println();
		}
		System.out.println("--------------------");
//		Question 2:
		for(int k = 0; k <= 750; k++) {
			System.out.print(k);
			System.out.print(' ');
		}
		System.out.println();
		System.out.println("The sum is: "+sumTo(750));
	}
}
