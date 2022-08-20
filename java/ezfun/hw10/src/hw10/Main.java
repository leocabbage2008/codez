package hw10;

import java.awt.*;
import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;
import javax.swing.JFrame;
import java.util.ArrayList;

public class Main extends Canvas{

	int HEIGHT=1000;
	int WIDTH=1000;
	public static void main(String[] args) {
		
		JFrame frame = new JFrame("My Graph");
		Canvas c = new Main();
		c.setSize(1000, 1000);
		frame.add(c);
		frame.pack();
		frame.setVisible(true);
		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;
		ArrayList<Integer> list = new ArrayList(100);
		ArrayList<Integer> revList = new ArrayList(100);
		for(int i = 0; i < 100; i++) {
			list.add(randInt(-1000,1000));
		}
		for(int i = 0; i < 99; i++) {
			if(max<list.get(i)) {
				max=list.get(i);
			}
		}
		for(int i = 0; i < 99; i++) {
			if(list.get(i)<min) {
				min=list.get(i);
			}
		}
		for(int i = 99; 0<i; i--) {
			revList.add(list.get(i));
		}
		System.out.println(min);
		System.out.println(max);
		System.out.println(list);
		System.out.println(revList);
	
	}
	public static int randInt(int min, int max) {
		Random rand = ThreadLocalRandom.current();
		int randomNum = rand.nextInt((max - min) + 1) + min;
		
		return randomNum;
	}
	
	public void paint(Graphics g) {	
		for(int i = 0; i<399; i++) {
			g.setColor(new Color(randInt(0,255),randInt(0,255),randInt(0,255)));
			triangle(g);
		}
	}
	
	public void triangle(Graphics g) {
		int x = randInt(0,WIDTH);
		int y = randInt(0,HEIGHT);
		int size = randInt(10,100);
		int xpoints[] = {(int)(x-size*Math.sqrt(3)),(int)(x+size*Math.sqrt(3)),x};
		int ypoints[] = {y-1,y-1,(int)(y+2*size*Math.sqrt(3))};
		int npoints = 3;
		g.fillPolygon(xpoints, ypoints, npoints);
	}
}