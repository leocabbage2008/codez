import java.util.*;
import java.awt.*;
import javax.swing.*;

public class Main extends Canvas {
	public static void main(String[] args) {
		Frame jf = new JFrame();
		Canvas cv = new Main();
		cv.setBackground(Color.black);
		cv.setSize(1000, 800);
		jf.add(cv);
		jf.pack();
		jf.setVisible(true);
		

	}

	public void paint(Graphics g) {
		int x = 500, y = 500, size = 120;;
		g.setColor(Color.green);
//		for(int i = 1; i <= size; ++i) 
//			g.drawPolygon(new int[] {(int)(x-Math.sqrt(3)*i),(int)(x+Math.sqrt(3)*i),x}, new int[] {y+i,y+i,y-2*i}, 3);
		for (int i = 0; i < 360; ++i) 
			g.drawLine(x, y, x + (int)(size * Math.cos(i)+0.5)/2, y + (int)(size * Math.sin(i)+0.5)/2);
		
	}

}