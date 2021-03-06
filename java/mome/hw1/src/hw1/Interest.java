package hw1;

public class Interest {
	public static double addSimpleInterest(double P, double r, int n) {
		return P*(1+r*n);
	}
	
	public static double addCompoundInterest(double P, double r, int n) {
		return Math.pow(P*(1+r),n);
	}
	
	public static void main(String[] args) {
		double P1 = 1000;
		double r1 = 0.04;
		int n1 = 10;
		System.out.println("Account 1");
		System.out.println(addSimpleInterest(P1, r1, n1));
		System.out.println(addCompoundInterest(P1, r1, n1));
		double P2 = 1000;
		double r2 = 0.05;
		int n2 = 10;
		System.out.println("Account 2");
		System.out.println(addSimpleInterest(P2, r2, n2));
		System.out.println(addCompoundInterest(P2, r2, n2));
	}
	
	
}
