import java.util.*;

public class CountLetters {
	public static void main(String[] args) {
		int[] res = new int[26];
		
		System.out.print("Enter a word: ");
		Scanner kb = new Scanner(System.in);
		String word = kb.nextLine().toLowerCase();
		kb.close();
		
		for(int i = 0; i < word.length(); i++) {
			res[((int)word.charAt(i))-97]+=1;
		}
		
		for(int i = 0; i < res.length; i++) {
			System.out.print(res[i]+" ");
		}
		
	}
}
