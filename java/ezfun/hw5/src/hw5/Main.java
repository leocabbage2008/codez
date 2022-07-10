package hw5;
import java.awt.*;
import javax.swing.JFrame;
import java.util.*;
import java.util.concurrent.ThreadLocalRandom;

public class Main extends Canvas{
	public static int randInt(int min, int max) {
	    Random rand = ThreadLocalRandom.current();
	    int randomNum = rand.nextInt((max - min) + 1) + min;

	    return randomNum;
	}
	public static void main(String[] args) {
		JFrame jf = new JFrame();
		Canvas cv = new Main();
		cv.setSize(500, 500);
		jf.add(cv);
		jf.pack();
		jf.setVisible(true);
	}

	public void paint(Graphics g) {
		
		Graphics2D g2 = (Graphics2D) g;
		g2.setStroke(new BasicStroke(5));
		g2.fillRect(0,  0, 1500, 1000);
		
		g2.fillRect(0,  0, 1500, 1000);

		while(true) {
			int i = randInt(0,20);
			g2.setColor(new Color(randInt(0,255),randInt(0,255),randInt(0,255)));
			g2.drawOval(15*randInt(0,20), 15*randInt(0,20), 400-20*randInt(0,20), 400-20*randInt(0,20));
		}

	}
}