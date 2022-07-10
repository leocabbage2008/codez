package hw4;

public class Main {
	public static Boolean pal(String a) {
		int n = a.length();
		
		for(int i = 0; i < n; i++) {
			if(!(a.charAt(i) == a.charAt(n-i-1))) {
				return false;
			}
		}
		return true;
	}
	
	public static void table(int row, int col) {
		for(int i = 1; i <= col; i++ ) {
			for(int j = 1; j <= row; j++){
				System.out.print((int)Math.pow(i, j)+"\t");
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args) {
//		test cases
		System.out.println(pal("123321"));
		System.out.println(pal("123331"));
//		test cases
		table(8,8);
	}
}
