package hw36;

import java.awt.*;
import javax.swing.JFrame;

public class Main extends Canvas {
	public static void main(String[] args) {
		JFrame frame = new JFrame("My Drawing");
		Canvas canvas = new Main();
		canvas.setSize(400, 400);
		frame.add(canvas);
		frame.pack();
		frame.setVisible(true);
	}

	public void paint(Graphics g) {
		drawTriangle(g, new Point(200, 0), new Point(0, 200), new Point(400, 200), 3);
	}

	public void drawTriangle(Graphics g, Point a, Point b, Point c, int level) {
		if (level == 0) {
//			g.setColor(Color.white);
			int px[] = { a.x, b.x, c.x };
			int py[] = { a.y, b.y, c.y };
			g.fillPolygon(px, py, 3);
		} else {
			g.setColor(Color.black);
			drawTriangle(g, a, new Point((a.x + b.x) / 2, (a.y + b.y) / 2), new Point((a.x + c.x) / 2, (a.y + c.y) / 2),
					level - 1);
			drawTriangle(g, new Point((a.x + b.x) / 2, (a.y + b.y) / 2), b, new Point((b.x + c.x) / 2, (b.y + c.y) / 2),
					level - 1);
			drawTriangle(g, new Point((a.x + c.x) / 2, (a.y + c.y) / 2), new Point((c.x + b.x) / 2, (c.y + b.y) / 2), c,
					level - 1);
		}
	}
}