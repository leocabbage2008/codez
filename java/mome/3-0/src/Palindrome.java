import java.util.*;

public class Palindrome {

	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		System.out.print("Please enter a word: ");
		String str1 = kb.nextLine();
		kb.close();

		String str2 = "";
		
		for(int i = 1; i <= str1.length(); i++) {
			str2+=str1.charAt(str1.length()-i);
		}
		
		System.out.print("It is ");
		if(!(str1.equals(str2))) {
			System.out.print("not ");
		}
		System.out.print("a palindrome.");
	}
}
