package hw11;
import java.awt.*;
import javax.swing.JFrame;
import java.lang.Math;

public class Main extends Canvas{
	public static void main(String[] args) {
		JFrame frame = new JFrame("drawing");
		Canvas canvas = new Main();
		canvas.setSize(800,800);
		frame.add(canvas);
		frame.pack();
		frame.setVisible(true);
		decToBin(5200);
	}
	public static int helper(int x) {
		int n = 0;
		while(true) {
			if((Math.pow(2, n))>x) {
				return n-1;
			}
			n++;
		}
	}
	public static void decToBin(int x) {
		long res = 0L;
		while(true) {
			if(x==0) break;
			int n = helper(x);
			x-=Math.pow(2, n);
			res+=Math.pow(10, n);
		}
		System.out.println(res);
	}
	public void paint(Graphics g) {
		for(int i = 0; i < 50; i++) {			
			g.drawArc(0, 0, 500, 500+i*20, 270, 90);
		}
		for(int i = 0; i < 50; i++) {			
			g.drawArc(0, 0, 500+i*20, 500, 270, 90);
		}
		for(int i = 0; i < 50; i++) {			
			g.drawArc(0, 250, 500+i*20, 500, 0, 90);
		}
		for(int i = 0; i < 50; i++) {			
			g.drawArc(250, 0, 500, 500+i*20, 180, 90);
		}
		for(int i = 0; i < 50; i++) {			
			g.drawArc(250, 250, 500, 500+i*20, 180, 90);
		}
		for(int i = 0; i < 50; i++) {			
			g.drawArc(250-i*20, 250, 500+i*20, 500, 90, 90);
		}
		for(int i = 0; i < 50; i++) {			
			g.drawArc(250, 250-i*20, 500, 500+i*20, 90, 90);
		}
		for(int i = 0; i < 50; i++) {			
			g.drawArc(250-20*i, 0, 500+i*20, 500, 180, 90);
		}
		for(int i = 0; i < 50; i++) {	
			g.drawArc(0, 250-20*i, 500, 500+i*20, 0, 90);			
		}
		g.setColor(new Color(255,255,255));
		g.fillRect(0, 0, 250, 1000);
		g.fillRect(0, 0, 1000, 250);
		g.fillRect(500, 0, 500, 1000);
		g.fillRect(0, 500, 500, 1000);
	}
}
