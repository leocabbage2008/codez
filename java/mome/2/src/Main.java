
public class Main {
	public static void main(String[] args) { 
		long sum = 0L;
		for(long j = 2L; j<=2_000_000; j=j+2) {
			sum=sum + (long)Math.pow(j, 2);
		}
		System.out.println(sum);
	}
}
