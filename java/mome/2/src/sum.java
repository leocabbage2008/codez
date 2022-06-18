
public class sum {
	public static void main(String[] args) {
		float sum = 0;
		for(int i = 1; i <= 100; i++) {
			sum += Math.sqrt(i);
		}
		System.out.println(sum);
		sum = 0;
		for(int i = 1; i<=999; i++) {
			sum+=1/(Math.sqrt(i)+Math.sqrt(i+1));
		}
		System.out.println(sum);
	}
}
