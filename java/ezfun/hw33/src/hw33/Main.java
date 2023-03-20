package hw33;

public class Main {
	public static void r(int[] a) {
		for (int i = 1; i < a.length; ++i) {
			int o = a[i];
			int z = i - 1;
			while (z >= 0 && a[z] < o) {
				a[z + 1] = a[z];
				z--;
			}
			a[z + 1] = o;
		}
	}

	public static void main(String[] args) {
		int N = 10;
		int[][] p = new int[N + 1][N];
		int[] a = { 5, 3, 6, 1, 4, 2, 7 };
		p[0][0] = 0;
		for (int i = 1; i < N; ++i) {
			p[i][0] = 1;
			p[i][i] = 1;
			for (int j = 1; j < i + 1; ++j) {
				p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < i; ++j) {
				System.out.print(p[i][j] + " ");
			}
			System.out.println();
		}
		r(a);
		boolean state = true;
		for (int i = 0; i < a.length - 1; ++i) {
			if (a[i] - a[i + 1] != 1) {
				state = false;
				break;
			}
		}
		System.out.println(state);
	}
}
