package test;

import java.util.Scanner;

public class Main {
	public static String rotate(String s, int n) {
		if (n == 0)
			return s;
		else if (n > 0)
			return s.substring(s.length() - n) + s.substring(0, s.length() - n);
		else
			return s.substring(-n) + s.substring(0, -n);

	}

	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		while (true) {
			System.out.println(rotate(kb.next(), kb.nextInt()));
		}
	}
}
