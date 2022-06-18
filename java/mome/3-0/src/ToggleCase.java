import java.util.*;

public class ToggleCase {

	public static boolean getCase(char c) {
		return Character.toUpperCase(c) == c;
	}
	
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		System.out.print("Enter a word: ");
		String string = kb.nextLine();
		String string0 = "";
		kb.close();
		
		for(int i = 0; i < string.length(); i++) {
			char c = string.charAt(i);
			if(getCase(c)) {
				string0 += Character.toLowerCase(c);
			}
			else {
				string0 += Character.toUpperCase(c);
			}
		}
		
		System.out.println(string0);
	}
}
