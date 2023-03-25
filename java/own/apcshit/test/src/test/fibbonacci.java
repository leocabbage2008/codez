package test;

public class fibbonacci {
	public static long fibonacci(int n) {
		if (n == 1 || n == 2)
			return 1;
		int a = 1, b = 1;
		for (int i = 0; i < n - 2; ++i) {
			int temp = b;
			b += a;
			a = temp;
		}
		return a;
	}

	public static void main(String[] args) {
		for (int i = 0; i < 10; ++i)
			System.out.println(fibonacci(i));
	}
}
