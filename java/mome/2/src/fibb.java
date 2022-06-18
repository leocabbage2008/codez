
public class fibb {
	
	public static void main(String[] args) {
		
		long x = 1L;
		long y = 1L;
		System.out.println(1 + "\t" + x);
		System.out.println(2 + "\t" + y);
		
		for(int j = 3; j<=50; j++) {
			long z = x+y;
			
			System.out.println(j + "\t" + z);
			
			x = y;
			y = z;
		}
	}
}
