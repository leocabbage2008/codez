import java.util.Scanner;

public class shape {
	public static void main(String[] args) {
		System.out.print("Number: ");
		Scanner ni = new Scanner(System.in);
		final int input = ni.nextInt();
		
		switch(input) {
			case 3:
				System.out.println("Triangle");
				break;
			case 4:
				System.out.println("Square");
				break;
			case 5:
				System.out.println("Pentagon");
				break;
			case 6:
				System.out.println("Hexagon");
				break;
			case 7:
				System.out.println("Septagon");
				break;
			case 8:
				System.out.println("Octagon");
				break;
			case 9:
				System.out.println("Nonagon");
				break;
			case 10:
				System.out.println("Decagon");
				break;
			default:
				System.out.println("Out of range.");
		}
	}
}
