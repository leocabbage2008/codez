
public class Complex {
	private double a;
	private double b;

	public Complex(double a1, double b2) {
		a = a1;
		b = b2;
	}

	public Complex(double a1) {
		a = a1;
		b = 0;
	}

	public double abs() {
		return Math.sqrt(a * a + b * b);
	}

	public Complex add(Complex other) {
		double ca = a + other.a;
		double cb = b + other.b;
		return new Complex(ca, cb);
	}
	
	public Complex add(double other) {
		return new Complex(a+other, b);
	}

	public Complex multiply(Complex other) {
		double ca = a * other.a - b * other.b;
		double cb = b * other.a + a * other.b;
		return new Complex(ca, cb);
	}
	
	public Complex multiply(double other) {
		return new Complex(a*other,b*other);
	}
	
	public String toString() {
		return a+"+"+b+"i";
	}
}
