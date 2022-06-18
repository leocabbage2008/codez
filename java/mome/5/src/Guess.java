import java.util.*;

public class Guess {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		
		System.out.println("Guess an integer between 1 and 10.");
		System.out.println("You have 3 chances.");
		
		int target = (int)(Math.random()*10)+1;
		
		int trial = 0; 
		while(trial<3) {
			int guess = kb.nextInt();
			if(guess > target) {
				System.out.println("Too big.");
			} else if(guess < target) {
				System.out.println("Too small.");
			} else {
				System.out.println("Correct.");
				break;
			}
			trial++;
		}
		if(trial==3) {
			System.out.println("You lose.");
		}
	}
}
