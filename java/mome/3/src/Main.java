import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		
		Scanner kb = new Scanner(System.in);
		
		System.out.println("Please enter an number:");
		float x = kb.nextFloat();
		float y = (float)(1 + Math.sqrt(x));
		for(int i = 0; i<200000; i++) {
			y = (float)(1 + Math.sqrt(x));
			x = y;
			System.out.println(y);
		}
		
		kb.close();
	}
}
