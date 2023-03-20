package test;

public class Main {
	public static String flip() {
		int r = (int) Math.random() * 3;
		if (r % 2 == 0)
			return "tails";
		else
			return "heads";
	}

	public static boolean arePermutations(int[] a, int[] b) {
		for (int i = 0; i < a.length; ++i) {
			boolean state = false;
			for (int j = 0; j < a.length; ++j) {
				if (a[i] - b[j] == 0) {
					state = true;
					break;
				}
			}
			if (state)
				continue;
			else
				return false;
		}
		return true;
	}

	public static void main(String[] args) {
		int[] a = { 1, 4, 3 };
		int[] b = { 3, 2, 1 };
		System.out.println(arePermutations(a, b));
//		int counter = 0;
//		for (int i = 0; i < 100; ++i) {
//			if (flip() == "tails") {
//				counter++;
//			}
//		}
//		System.out.println(counter / 100.0);
	}
}
