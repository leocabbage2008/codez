package hw31;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.Random;

public class Main extends JFrame {

	int numButtons;
	JButton buttons[];
	String buttonSymbols[];
	int targetX, targetY, moves=10;

	public Main() {
		setTitle("Treasure Game");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(new GridLayout(0, 10));
		setPreferredSize(new Dimension(1000, 500));

		numButtons = 100;
		buttons = new JButton[numButtons];
		buttonSymbols = new String[numButtons];

		Random r = new Random();
		targetX = r.nextInt(10);
		targetY = r.nextInt(10);
		for (int i = 0; i < numButtons; ++i) {
			int ra = i / 10;
			int ca = i % 10;
			buttons[i] = new JButton("?");
			buttons[i].setFocusPainted(false);
			buttons[i].setOpaque(true);
			buttons[i].setBorderPainted(false);
			buttons[i].addActionListener(new ButtonListener());
			if (ra == targetX || ca == targetY)
				buttonSymbols[i] = "!";
			else
				buttonSymbols[i] = ".";
			add(buttons[i]);
		}
		pack();
		setVisible(true);

	}

	private class ButtonListener implements ActionListener {

		public void actionPerformed(ActionEvent e) {
			for (int i = 0; i < numButtons; ++i) {
				if (buttons[i] == e.getSource()) {
					if(moves==0) {
						for(int j = 0; j < numButtons; ++j) {
							int r = j / 10;
							int c = j % 10;
							int distance = (int) (Math.sqrt((r - targetX) * (r - targetX) + (c - targetY) * (c - targetY)));
							if (distance == 0)
								buttons[j].setBackground(Color.YELLOW);
							else
								buttons[j].setBackground(Color.RED);
							buttons[j].setEnabled(false);
							buttons[j].setText(String.valueOf(distance));
						}
					}
					int r = i / 10;
					int c = i % 10;
					int distance = (int) (Math.sqrt((r - targetX) * (r - targetX) + (c - targetY) * (c - targetY)));
					if (distance == 0)
						buttons[i].setBackground(Color.YELLOW);
					else
						buttons[i].setBackground(Color.RED);
					buttons[i].setText(String.valueOf(distance));
					buttons[i].setEnabled(false);
					moves--;
				}
			}
		}
	}

	public static void main(String[] args) {
		new Main();
	}
}
//(D)
//(A)