
public class Rsq {
	public static void main(String[] args) {
		double n = Math.sqrt(5);
		double max = 0;
		
		for(int i = 1; i < Double.MAX_VALUE; i++) {
			for(int j = 1; j < Double.MAX_VALUE; j++) {
				double x = ((double)i)/((double)j);
				if(max<x && x<n) {
					max = x;
				}
			}	
		}
		System.out.println(n);
		System.out.println(max);
	}
}
