import java.util.*;
import java.io.*;

public class read {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner file = new Scanner(new File("bruh.in"));
		
		double min1 = Double.MAX_VALUE;
		double max1 = -Double.MAX_VALUE;
		double sum1 = 0;
		
		double min2 = Double.MAX_VALUE;
		double max2 = -Double.MAX_VALUE;
		double sum2 = 0;
		int n = file.nextInt();
		for(int j = 0; j < n; j++) {
			double i1 = file.nextDouble();
			if(i1 < min1) min1 = i1;
			if(i1 > max1) max1 = i1;
			sum1 += i1;
			
			double i2 = file.nextDouble();
			if(i2 < min2) min2 = i2;
			if(i1 > max2) max2 = i2;
			sum2+=i2;
		}
		PrintWriter output = new PrintWriter(new File("bruh.out"));
		output.println("Min values: " + min1 + " " + min2);
		output.println("Max values: " + max1 + " " + max2);
		output.println("Mean values: " + sum1/((double)n) + " " + sum2/((double)n));

		file.close();
		output.close();
	}
}
