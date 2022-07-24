package hw8;
import java.awt.*;
import javax.swing.JFrame;

public class Main extends Canvas{
	public static void main(String[] args) {
		JFrame frame = new JFrame("drawing");
		Canvas canvas = new Main();
		canvas.setSize(500,500);
		frame.add(canvas);
		frame.pack();
		frame.setVisible(true);
	}
	
	public void paint(Graphics g) {
		g.setColor(Color.RED);
		draw(g,0,0,10);
		draw0(g,968,0,145);
	}
	public void draw(Graphics g, double x, double y, double r) {
		if (r<100) {
			System.out.println(r);
			g.fillOval((int)(x),(int)(y),(int)(2*r), (int)(2*r));
			draw(g, x+2*r,y,r*1.2);
		}
	}
	public void draw0(Graphics g, double x, double y, double r) {
		if (r>10) {
			g.fillOval((int)(x),(int)(y),(int)(r), (int)(r));
			draw0(g, x+r,y,r*5/6);
		}
	}
}
