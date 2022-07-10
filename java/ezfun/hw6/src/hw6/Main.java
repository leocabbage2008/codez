package hw6;
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
        JFrame frame = new JFrame("My Drawing");
        Canvas canvas = new Main();
        canvas.setSize(500, 500);
        frame.add(canvas);
        frame.pack();
        frame.setVisible(true);
    }
    public void paint(Graphics g) {
    	g.fillRect(0, 0, 500, 500);
    	for(int i = 0; i < 13; i++) {
    		for(int j = 0; j < 13; j++) {
    			g.setColor(new Color(randInt(0,255),randInt(0,255),randInt(0,255)));
    			g.fillRect(i*37,j*37,30,30);
    		}
    	}
    	g.setColor(new Color(255,255,0));
    	g.fillOval(0, 0, 200, 200);
    	g.setColor(new Color(0,0,255));
    	g.fillOval(50, 50, 20, 20);
    	g.fillOval(130, 50, 20, 20);
    	g.setColor(new Color(255,0,0));
    	g.fillRect(60, 120, 80, 10);
    }


}  