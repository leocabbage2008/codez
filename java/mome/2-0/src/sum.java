
public class sum {

	public static void main(String[] args) {
		float sum = 0;
		//(9.1)
		sum=0;
		for(int i = 1; i <= 1000; i++) {
			if(i%2==0) {
				sum+=1/(Math.sqrt(i+1)-Math.sqrt(i));
			}
			else if (i%2==1) {
				sum+=1/(Math.sqrt(i+1)+Math.sqrt(i));
			}
		}
		System.out.println(sum);
		//(9.2)
		sum=0;
		for(int i = 1; i <= 1000; i++) {
			if(i%2==0) {
				sum+=Math.pow(i, 3);
			}
			else if (i%2==1) {
				sum+=Math.pow(i, 2);
			}
		}
		System.out.println(sum);
		//10
		sum=0;
		for(int i = 1; i <= 1000; i++) {
			double sqrt = Math.sqrt(i);
			double cbrt = Math.cbrt(i);
			if((sqrt-Math.floor(sqrt)==0)&&(cbrt-Math.floor(cbrt)==0)) {
				sum += cbrt;
			}
		}
		System.out.println(sum);
	}
}
