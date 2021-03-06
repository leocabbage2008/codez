import java.util.*;

public class WordTriangle {

	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		System.out.print("Please enter a word: ");
		String word = kb.next();
		kb.close();
		
		int n = word.length();
		for(int r = 0; r < n-1; r++) {
			for(int c = 0; c < n-1-r; c++) {
				System.out.print(" ");
			}
			
			if(r != 0) {				
				System.out.print(word.charAt(r));
				for(int c = 0; c < 2*r-1; c++) {
					System.out.print(" ");
				}
				System.out.print(word.charAt(r));
			} else {
				System.out.print(word.charAt(r));
			}
			
			System.out.println();
		}
		for (int c = 0; c < n; c++) {
			System.out.print(word.charAt(n-c-1));
		}
		System.out.print(word.substring(1));
	}
}
