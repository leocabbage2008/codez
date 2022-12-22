package hw25;

import java.util.*;
import java.awt.*;
import javax.swing.*;

public class Main extends Canvas {
	public static void main(String[] args) {

		Frame jf = new JFrame();
		Canvas cv = new Main();
		cv.setBackground(Color.black);
		cv.setSize(1500, 1000);
		jf.add(cv);
		jf.pack();
		jf.setVisible(true);
		//(B)

	}

	public void paint(Graphics g) {
		g.setColor(new Color(255, 255, 255));
		printDots(g, 700, 100, 30);
	}

	public void printDots(Graphics g, int x, int y, int n) {
		for (int i = 0; i < 360 / n; ++i) {
			for (int j = 0; j < n; ++j) {
				g.setColor(new Color((int) (Math.random() * 255), (int) (Math.random() * 255),
						(int) (Math.random() * 255)));
				g.fillOval((int) Math.round(2 * j * Math.cos(i * n * Math.PI / 180.0)) + x,
						(int) Math.round(2 * j * Math.sin(i * n * Math.PI / 180.0)) + y, n / 2, n / 2);
			}
		}
	}

}