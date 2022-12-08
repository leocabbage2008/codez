package test;

public class Polynomial {
	private static String p = "";

	public Polynomial(double[] a) {
		for (int i = 0; i < a.length; ++i) {
			p += a[i] + " ";
		}
		p = p.trim();
	}

	public int degree() {
		return p.split(" ").length;
	}

	public double getValue(double x) {
		double s = 0;
		int i = 0;
		for (String t : p.split(" ")) {
			s += Math.pow(x, i) * Double.parseDouble(t);
			i++;
		}
		return s;
	}

	public String toString() {
		String[] d = p.split(" ");
		String s = "";
		for (int i = 0; i < p.split(" ").length - 1; ++i) {
			s += d[i] + "x^" + (i + 1);
			if (Double.parseDouble(d[i]) > 0)
				s += "+";
			else
				s += "-";

		}
		s += d[p.split(" ").length - 1] + "x^" + (p.split(" ").length);
		return s;
	}
}
