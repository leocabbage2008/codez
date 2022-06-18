import java.util.*;

public class Weave {

	public static void main(String[] args) {		
		Scanner input0 = new Scanner(System.in);
		System.out.print("Enter word 1: ");
		String str0 = input0.next();

		Scanner input1 = new Scanner(System.in);
		System.out.print("Enter a word 2: ");
		String str1 = input1.next();
		
		
		String result = "";
		
		int len0 = str0.length();
		int len1 = str1.length();
		
		boolean larger = len1>len0;

		for(int i = 0; i < Math.min(len0, len1); i++) {
			result += "" + str0.charAt(i) + str1.charAt(i);
		}

		if(larger)
			result += (String)str1.substring(len0);
		else
			result += (String)str0.substring(len1);
		
		System.out.println(result);
		
		input0.close();
		input1.close();
	}
}
