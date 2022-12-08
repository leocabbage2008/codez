package hw22;

import java.util.*;
import java.awt.*;

import javax.swing.*;

public class Main extends Canvas {
	int NOC = 36;

	public static void main(String[] args) {
		Frame jf = new JFrame();
		Canvas cv = new Main();
		cv.setBackground(Color.black);
		cv.setSize(1300, 1000);
		jf.add(cv);
		jf.pack();
		jf.setVisible(true);
		//(E)

	}

	public void paint(Graphics g) {
		double n = 360.0 / NOC;
		Random rand = new Random();
		for (int i = 0; i <= NOC; ++i) {
			g.setColor(new Color(rand.nextFloat(), rand.nextFloat(), rand.nextFloat()));
			g.drawOval((int) (500 + Math.cos(i * n * 2 * Math.PI / 360.0) * 150),
					(int) (500 + Math.sin(i * n * 2 * Math.PI / 360.0) * 150), 300, 300);
		}

	}

}