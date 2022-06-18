import java.util.*;

public class Name {

	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		System.out.print("Please enter a word: ");
		String full = kb.nextLine();
		
		String dup = "";
		
		for(int i = 0; i < full.length(); i++) {
			dup+=full.charAt(i)+full.charAt(i);
		}
		
		System.out.println(dup);
		
		kb.close();
	}
}
