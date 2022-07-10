import java.util.*;

public class Rps {
	public static void main(String[] args) {
		System.out.println("Welcome to Rock, Paper, Scissors game!");
		System.out.println("Your play: r = rock; p = paper; s = scissors");
		
		Scanner kb = new Scanner(System.in);
		System.out.println("Number of rounds a player needs to win to claim victory: ");
		int rounds = kb.nextInt();
		int cwin = 0;
		int hwin = 0;
		int roundsPlayed = 0;
		char[] choices = {'r', 'p', 's'};
		
		do {
			Random rand = new Random();
			Scanner input = new Scanner(System.in);
			System.out.println("What do you play? (r/p/s)");
			
			char choice = kb.next().charAt(0);
			int index = 0;
			for(int i = 0; i < choices.length; i++) {
				if(choice==choices[i]) {
					index=i;
				}
			}
			
			int randIndex = rand.nextInt(3);
			char random = choices[randIndex];
			
			if(index == 2 && randIndex == 0) {
				cwin++;
			} else if(index == 0 && randIndex == 2) {
				hwin++;
			} else if(randIndex > index) {
				cwin++;
			} else if(index > randIndex) {
				hwin++;
			}
			
			System.out.println("Computer: " + cwin + "\t You: " + hwin);;
			roundsPlayed++;
		} while(!(cwin==rounds || hwin==rounds));
		
		if(hwin>cwin) {
			System.out.println("You won the game!");
		}
		else {
			System.out.println("You lost the game!");
		}
		System.out.println("You played " + roundsPlayed + " rounds.");
	}
}
