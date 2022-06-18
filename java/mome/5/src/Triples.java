import java.util.*;

public class Triples {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		System.out.print("Enter a number: ");
		int n = kb.nextInt();
		int count = 0;
		
		for(int c = 1; c <= n; c++) {
			for(int b = 1; b <= c; b++) {
				for(int a = 1; a <= b; a++) {
					if(2*a*a+b*b==c*c) {
						count++;
						System.out.println(a+" "+b+" "+c);
					}
				}
			}
		}
		System.out.println(count);
	}
}
