package test;

public class Product {
public static int product(int a, int b) {
	if (b == 1)
		return a;
	else
		return a + product(a, b - 1);
}

	public static void main(String[] args) {
		System.out.println(product(5, 3));
	}
}
