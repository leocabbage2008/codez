package hw35;

import java.awt.*;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class Main extends JPanel {
	public static void main(String[] args) {
		Main b = new Main();
		JFrame j = new JFrame();
		j.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		j.setSize(700, 700);
		j.add(b);
		j.setVisible(true);
	}

	public void paintComponent(Graphics g) {
//		layers(1, g);
		for (int i = 0; i < 20; ++i) {
			for (int j = 0; j < i; ++j) {
				g.drawRect(500 - (25 * i) + 50 * j, 20 * i, 50, 20);
			}
		}
	}

//	public void layers(int layer, Graphics g) {
//		for (int i = 0; i < layer; i++)
//			g.drawRect(500 - (25 * layer) + 50 * i, 20 * layer, 50, 20);
//		if (layer < 20)
//			layers(layer + 1, g);
//	}

}

//(A)