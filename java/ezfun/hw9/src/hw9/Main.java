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
		canvas.setSize(500,500);
		frame.add(canvas);
		frame.pack();
		frame.setVisible(true);
	}
	
	public void paint(Graphics g) {
		g.setColor(new Color(randInt(0,255),randInt(0,255),randInt(0,255)));
		Rectangle r = new Rectangle(600,0,100,100);
		draw(g,r,0);
		
	}
	
	public void draw(Graphics g, Rectangle r,int level) {
		g.fillRect(r.x, r.y, r.width, r.height);
		level++;
		if(level < 10) {
			Rectangle r0 = new Rectangle(r.x-r.width,r.y+r.height,r.width,r.height);
			draw(g,r0,level);
			Rectangle r1 = new Rectangle(r.x+r.width,r.y+r.height,r.width,r.height);
			draw(g,r1,level);
		}
	}
}
