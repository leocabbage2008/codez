package hw20;

import java.awt.*;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class Main extends JPanel {

	static Color[] color = { Color.red, Color.orange, Color.yellow, Color.green, Color.blue, Color.pink,
			Color.magenta };

	public static void main(String[] args) {
		JFrame frame = new JFrame();
		Main c = new Main();
		frame.setPreferredSize(new Dimension(500, 500));
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.add(c);
		frame.pack();
		frame.setVisible(true);
	}

	public void paintComponent(Graphics g) {
		int n = 0;
		for(Color c:color) {
			g.setColor(c);
			g.fillArc(100+25*n, 100+25*n, 350-50*n, 350-50*n, 0, 180);
			n++;
		}
		//E
	}

}
