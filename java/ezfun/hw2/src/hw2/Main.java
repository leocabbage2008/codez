package hw2;
import java.util.Scanner;
import java.util.Random;

public class Main {
	public static int getRand(int n) {
		System.out.print("Player "+n+": press Enter to roll the die");
		Scanner in = new Scanner(System.in);
		String input = in.nextLine();
		if(input=="") {
			Random ra = new Random();
			int rand = ra.nextInt(5);
			rand+=1;
			System.out.println("You got a "+rand);
			return rand;
		}
		return -1;

	}
	public static int Average() {
		int sum = 0;
		System.out.println("How many numbers you will enter to compute the average: ");
		Scanner num = new Scanner(System.in);
		int n = num.nextInt();
		System.out.println("Please enter "+n+" numbers: ");
		Scanner in = new Scanner(System.in);
		String input = in.nextLine();
		String[] split = input.split("\\s+");
		for(String i : split) {
			sum+=Integer.parseInt(i);
		}
		System.out.println(sum);
		System.out.println((float) sum/ (float) n);
		return sum/n;
		
	}
	public static void main(String[] args) {
		System.out.println("Game Starts...");
		int p1 = getRand(1);
		int p2 = getRand(2);
		if(p1 == -1) {
			p1 = getRand(1);
		}
		
		if(p2 == -1) {
			p2 = getRand(2);
		}
		
		if(p1>p2) {
			System.out.println("The winner is: Player 1");
		}
		else if(p1 == p2) {
			System.out.println("It's a tie!");
		}
		else {
			System.out.println("The winner is: Player 2");
		}
		System.out.println("-------------------------------");
		Average();
		
	}
}
