import java.util.*;
import java.io.*;

public class Line {
	public static void main(String[] args) throws IOException{
		PrintWriter output = new PrintWriter(new File("sample.out"));
		Scanner in = new Scanner(new File("sample.txt"));
		int c = 1;
		
		while(in.hasNextLine()) {
			output.println(c + ":\t" + in.nextLine());
			c++;
		}
		output.close();
		
	}
}
