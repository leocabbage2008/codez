import java.util.*;

public class Rectangles {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		System.out.println("Plz enter x1 and x2:");
		int x1 = kb.nextInt();
		int x2 = kb.nextInt();
		
		System.out.println("Plz enter y1 and y2:");
		int y1 = kb.nextInt();
		int y2 = kb.nextInt();
		
		System.out.println("Plz enter x3 and x4:");
		int x3 = kb.nextInt();
		int x4 = kb.nextInt();
		
		System.out.println("Plz enter y3 and y4:");
		int y3 = kb.nextInt();
		int y4 = kb.nextInt();
		kb.close();
		
		int largerX = Math.max(x1, x2);
		int smallerX = Math.min(x1, x2);
		int largerY = Math.max(y1, y2);
		int smallerY = Math.min(y1, y2);
		
		int c = 0;
		
		for(int i = smallerX; i <= largerX; i++) {
			for(int j = smallerY; j <= largerY; j++) {
				c++;
			}
		}
		System.out.println(c);
	}
}
