import java.util.*;

public class String0 {
	
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		
		System.out.print("Please enter a word: ");
		String word = kb.next();
		
		System.out.println(word.substring(0,2).equals(word.substring(word.length()-2)));
		
		kb.close();
	}
}
