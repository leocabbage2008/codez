package hw32;

import java.awt.*;
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.text.BadLocationException;
import javax.swing.text.Document;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Main extends JFrame {

	private JTextField amountField = new JTextField(12);
	private Document amountText = amountField.getDocument();
	private JTextArea report = new JTextArea(8, 40);

	public Main() {
		setSize(500, 500);
		JPanel topPanel = new JPanel();
		topPanel.add(new JLabel("Amount:"));
		topPanel.add(amountField);
		amountField.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				int q =(int) Math.floor(Integer.valueOf(amountField.getText())/25);
//				int d = Math.floor()
			}

		});
		getContentPane().add(topPanel, BorderLayout.NORTH);
		getContentPane().add(new JScrollPane(report));

		setBackground(Color.LIGHT_GRAY);
		setTitle("Changer");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);

	}

	public static void main(String[] args) {
		new Main();

	}
}
