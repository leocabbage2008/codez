package test;

public class countPaths {
public static String removeConsecutiveDuplicateChars(String str) {
	if(str.length()<=1) return str;
	if(str.charAt(0)==str.charAt(1)) {
		return removeConsecutiveDuplicateChars(str.substring(1));
	} else {
		return str.charAt(0)+removeConsecutiveDuplicateChars(str.substring(1));
	}
}
	public static void main(String[] args) {
		System.out.println(removeConsecutiveDuplicateChars("AABBCCDEFFFFG"));
//		System.out.println(removeCosecutiveDuplicates("AABBBCDDDEEFFFFFG"));
	}
}
