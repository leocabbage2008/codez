
public class Limerick extends Poem{
	private int[] lines = {9,9,6,6,9};
	
	@Override
	public int numLines() {
		// TODO Auto-generated method stub
		return 5;
	}

	@Override
	public int getSyllables(int k) {
		// TODO Auto-generated method stub
		return lines[k];
	}
	
}
