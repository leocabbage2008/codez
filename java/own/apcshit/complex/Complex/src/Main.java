import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		System.out.println("input: ");
		Scanner kb = new Scanner(System.in);
		double a = kb.nextDouble();
		double b = kb.nextDouble();
		kb.close();
		Complex c = new Complex(a,b);
		System.out.println(c.add(new Complex(1,2)));
		System.out.println(c.multiply(new Complex(1,2)));
	}
}
