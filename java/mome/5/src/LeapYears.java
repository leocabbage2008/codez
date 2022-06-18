
public class LeapYears {
	public static void main(String[] args) {
		int c = 0;
		for(int i = 1; i <= 1022; i++) {
			if((c%4 == 0) && ((c%100 != 0) || (c%400 == 0))) {
				c++;
			}
		}
		System.out.println(c);
	}
}
