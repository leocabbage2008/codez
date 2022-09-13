package hw12;
import java.awt.*;
import javax.swing.JFrame;
import javax.swing.Timer;
import javax.swing.JPanel;
import java.awt.event.*;
import java.util.Arrays;

public class Main extends JPanel implements ActionListener{
	Timer t = new Timer(10, this);
	static int[] x = new int[100], velX = new int[100];
	static int[] y = new int[100], velY = new int[100]; 
	static Color[] currentColor = new Color[100];
	static int WIDTH=1000;
	static int HEIGHT=1000;
	
	public static void main (String[] args) {
		for(int i = 0; i < 100; ++i) {
			x[i]=(int)(Math.random()*WIDTH);
			y[i]=(int)(Math.random()*HEIGHT);
		}
		Arrays.fill(velX, 5);
		Arrays.fill(velY, 10);
		for(int i = 0; i < 100; ++i) {			
			currentColor[i] = new Color((int) (Math.random()*255), (int) (Math.random()*255), 0);
		}
		Main m = new Main(); 
		JFrame j = new JFrame();
		j.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		j.setSize(WIDTH, HEIGHT);
		j.add(m);
		j.setVisible(true);
	}
	
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		for(int i = 0; i < 100; i++) {			
			g.setColor(currentColor[i]);
			g.fillOval(x[i], y[i], 100, 100);
		}
		t.start();
	}
	
	public void actionPerformed(ActionEvent e) {
		for(int i = 0; i < 100; ++i) {			
			x[i] += velX[i];    // move my ball
			y[i] += velY[i];    // move my ball
			if ( x[i] > WIDTH-50  || x[i]<0 )
				velX[i] = -velX[i];		
			if ( y[i] > HEIGHT-50  || y[i]<0 )
				velY[i] = -velY[i];
		}
		repaint();
	}
}