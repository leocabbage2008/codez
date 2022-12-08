package hw23;

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
import java.util.*;

public class Main extends JFrame implements MouseMotionListener {
	String c = "black";
	JSlider penSize;

	public Main() {
		addMouseMotionListener(this);
		setSize(800, 800);
		setLayout(new FlowLayout());
		JButton b1, b2, b3;
		b1 = new JButton("Red");
		add(b1);
		b1.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				c = "red";
			}
		});
		b2 = new JButton("Blue");
		add(b2);
		b2.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				c = "blue";
			}
		});
		b3 = new JButton("Random");
		add(b3);
		b3.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				c = "random";
			}
		});
		penSize = new JSlider(0, 100);
		add(penSize);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
	}

	@Override
	public void mouseDragged(MouseEvent e) {// draw dots
		Graphics g = getGraphics();
		if (c.equals("red"))
			g.setColor(Color.red);
		else if (c.equals("blue"))
			g.setColor(Color.blue);
		else if (c.equals("random"))
			g.setColor(
					new Color((int) (Math.random() * 255), (int) (Math.random() * 255), (int) (Math.random() * 255)));
		g.fillOval(e.getX(), e.getY(), penSize.getValue(), penSize.getValue());
	}

	public void mouseMoved(MouseEvent e) {
	}

	public static void main(String[] args) {
		new Main();
		//(A)
	}

}