package test;

public class gcf {
	public static int gcf(int a, int b) {
		if(a==b) return a;
		if(b<=a) return gcf(a-b,b);
		else return gcf(a,b-a);
	}
	public static void main(String[] args) {
		System.out.println(gcf(11,20));
	}
}
