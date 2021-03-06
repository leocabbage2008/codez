package hw2;

public class Main {
	public static int gcd(int a, int b) {
		if(b==0) return a;
		return gcd(b,a%b);
	}
	public static void main(String[] args) {
		//euclidean algorithim solution
		int sum = 0;
		for(int i = 1; i <= 105; i++) {
			if(gcd(i,105)==1) {
				sum++;
				System.out.println(i);
			}
		}
		System.out.println(sum);
	}
}
