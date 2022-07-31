package hw9;
import java.awt.*;
import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;

import javax.swing.JFrame;

public class Main extends Canvas{
	public static int randInt(int min, int max) {
	    Random rand = ThreadLocalRandom.current();
	    int randomNum = rand.nextInt((max - min) + 1) + min;

	    return randomNum;
	}
	public static void main(String[] args) {
		JFrame frame = new JFrame("drawing");
		Canvas canvas = new Main();
		canvas.setSize(800,800);
		frame.add(canvas);
		frame.pack();
		frame.setVisible(true);
	}
	
	public void paint(Graphics g) {
		draw(g,400,400,300,0);
		
	}
	
	public void draw(Graphics g, int x, int y, int r,int level) {
		if(level!=0) {			
			g.drawOval(x, y, r, r);
		}
		level++;
		if(level<5) {
			draw(g,x+r/4,y+3*r/4,r/2,level);
			draw(g,x+3*r/4,y+r/4,r/2,level);
			draw(g,x+r/4,y-r/4,r/2,level);
			draw(g,x-r/4,y+r/4,r/2,level);
		}
	}
}
