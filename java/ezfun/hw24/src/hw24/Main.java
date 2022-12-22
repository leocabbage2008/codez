package hw24;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.Timer;
import java.util.TimerTask;

public class Main extends JFrame {
	JLabel timeLabel;
	long startTime;
	long time;
	Timer t;

	public Main() {

		setSize(500, 300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		setLayout(new GridLayout(2, 1));

		JPanel p1 = new JPanel();
		timeLabel = new JLabel("Press Start to begin timing.");
		p1.add(timeLabel);
		add(p1);

		JPanel p2 = new JPanel(new GridLayout(1, 2));
		JButton startButton = new JButton("Start");
		JButton stopButton = new JButton("Stop");
		startButton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				boolean condition = timeLabel.getText().compareTo("Press Start to begin timing.") == 0;
				if (condition) {
					startTime = e.getWhen();
				} else
					startTime = time;
				t = new Timer();
				startButton.setEnabled(false);
				stopButton.setEnabled(true);
				t.schedule(new TimerTask() {
					public void run() {
						if (condition) {
							timeLabel.setText(time / 60000 + " minutes: " + time / 1000 + " seconds: " + time % 1000
									+ " milliseconds");
							long currentTime = System.currentTimeMillis();
							time = ((currentTime - startTime));
						} else {
							timeLabel.setText(time / 60000 + " minutes: " + time / 1000 + " seconds: " + time % 1000
									+ " milliseconds");
							time = startTime;
							startTime += 10;
						}
					}
				}, 0, 10);

			}

		});

		stopButton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				startButton.setEnabled(true);
				stopButton.setEnabled(false);
				t.cancel();
			}

		});
		p2.add(startButton);
		p2.add(stopButton);
		add(p2);

		setVisible(true);
	}

	public static void main(String[] args) {
		new Main();
		//(B)
	}

}
