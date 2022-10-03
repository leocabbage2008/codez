package hw15;

public class Main {
	public static void printDiamond(int n) {
		for(int i = 1; i <= n; i+=2) {
			for(int k = 0; k < (n-i)/2; k++) System.out.print(" ");
			for(int j = 0; j < i; j++) {				
				System.out.print((char)(j+65));
			}
			System.out.println();
		}
		for(int i = n-2; i > 0; i-=2) {
			for(int k = 0; k < (n-i)/2; k++) System.out.print(" ");
			for(int j = 0; j < i; j++) {				
				System.out.print((char)(j+65));
			}
			System.out.println();
		}
	}
	public static void main(String args[]) {
		printDiamond(15);
	}
}