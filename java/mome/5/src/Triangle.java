
public class Triangle {
	public static void main(String[] args) {
		int n = 10; 
		
		for(int r = 1; r <= n; r++) {
			
			for(int c = 1; c <= -r + n + 1; c++) {
				System.out.print("+");
			}
			System.out.println();
		}
		
		for(int r = 1; r <= n; r++) {
			for(int c = 1; c <= -r + n; c++) {
				System.out.print(" ");
			}
			for (int c = 1; c <= r; c++) {
				System.out.print("+");
			}
			System.out.println();
		}
		
		for(int r = 0; r < n; r++) {
			for(int i = 0; i < n-r;i++) {
				System.out.print(" ");
			}
			for(int i = 0; i < 2*r-1; i++) {
				System.out.print("+");
			}
			System.out.println();
		}
		System.out.println();
		System.out.println();
		for(int r = 0; r < n; r++) {
			if(r == n/2) continue;
			if(r>n/2) {				
				for(int i = 0; i < -Math.abs(r-n/2)+n/2-1;i++) {
					System.out.print(" ");
				}
			}
			else {
				for(int i = 0; i < -Math.abs(r-n/2)+n/2;i++) {
					System.out.print(" ");
				}
			}
			for(int i = 0; i < Math.abs(2*(Math.floor(n/2)-r)-1); i++) {
				System.out.print("+");
			}
			System.out.println();
		}
	}
}
