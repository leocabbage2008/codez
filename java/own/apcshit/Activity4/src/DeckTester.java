/**
 * This is a class that tests the Deck class.
 */
public class DeckTester {

	/**
	 * The main method in this class checks the Deck operations for consistency.
	 *	@param args is not used.
	 */
	public static void main(String[] args) {
		String[] ranks = {"A","B","C"};
		String[] suits = {"star","cloud","moon","sun"};
		int[] values = {4,3,2};
		Deck d = new Deck(ranks, suits, values);
		System.out.println(d);
		d.shuffle();
		System.out.println(d);
		System.out.println(d.deal()+" "+d.deal()+" "+d.deal());
		System.out.println(d);
		d.shuffle();
		System.out.println(d);
	}
}