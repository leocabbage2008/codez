
public class Eucd {
	public static void main(String[] args) {
		int m = 12;
		int n = 18;
		
		int r;
		do {
			r = n % m;
			n = m; 
			m = r;
		} while(r > 0);
		System.out.println(n);
	}
}
