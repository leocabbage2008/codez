
public class Main {
	public static void printStars(int n) {
		for (int i = 0; i < n; ++i) {
			System.out.print("*");
		}
		System.out.println();
	}

	public static void printTriangle(int n) {
		if (n == 0) {
			return;
		} else {
			printTriangle(n - 1);
			printStars(n);
		}
	}

	public static void main(String[] args) {
		printTriangle(5);
	}
}
