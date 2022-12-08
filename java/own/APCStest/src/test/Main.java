package test;

import java.util.Scanner;

class Main {
	public static int gcf(int a, int b) {
		while (a != 0 && b != 0) {
			int temp = a;
			System.out.println(a + " " + b + " " + temp);

			a = b % a;
			b = temp;
		}
		return b;
	}

	public static void main(String[] args) {
		double[] d = { 2, -3, 4, 0.5 };
		Polynomial p = new Polynomial(d);
		System.out.println("The degree of " + p + " is " + p.degree());
		System.out.println("p(-2.5) = " + p.getValue(-2.5));
	}
}