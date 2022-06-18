public class order {
	public static void main(String[] args) {
		int x = 1, y = 2, z = 3;
		
		int v1 = Math.max(x, Math.max(y, z));
		int v3 = Math.min(x, Math.max(z, z));
		int v2 = x+y+z-v1-v3;
		
		System.out.println(v1+" "+v2+" "+v3);
	}
}
