public abstract class Poem {
	public abstract int numLines();

	public abstract int getSyllables(int k);

	public void printRhythm() {
		for (int i = 0; i < numLines(); ++i) {
			System.out.print("ta");
			for (int j = 1; j < getSyllables(i); ++j) {
				System.out.print("-ta");
			}
			System.out.println();
		}
	}
}