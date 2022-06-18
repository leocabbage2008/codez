import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class file {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner foo = new Scanner(new File("foo.txt"));
		while(foo.hasNextLine()) {			
			System.out.println(foo.next());
		}
		foo.close();
	}
}
