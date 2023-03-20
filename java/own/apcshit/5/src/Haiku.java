
public class Haiku extends Poem{
	private int[] lines = {5,7,5};
	
	@Override
	public int numLines() {
		// TODO Auto-generated method stub
		return 3;
	}

	@Override
	public int getSyllables(int k) {
		// TODO Auto-generated method stub
		return lines[k];
	}
	
}
