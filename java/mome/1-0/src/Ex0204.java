
public class Ex0204 {
	public static int getSum(int a, int b) {
		int sum = a + b;
		return sum;
	}
	
	public static int getDiff(int a, int b) {
		int diff = a - b;
		return diff;
	}
	public static void main(String[] args) {
		int x = 1, y = 2;
		
		int sum = x+y, diff = x-y;
		
		System.out.println("i = " + x);
		System.out.println("j = " + y);
		System.out.println("sum = " + getSum(x,y));
		System.out.println("diff = " + getDiff(x,y));
		System.out.println("sum = " + sum);
		System.out.println("diff = " + diff);
	}
}
