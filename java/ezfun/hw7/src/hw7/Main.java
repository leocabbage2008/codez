package hw7;
import java.awt.*;
import javax.swing.JFrame;

public class Main extends Canvas{
	public static void main(String[] args) {
		JFrame frame = new JFrame("drawing");
		Canvas canvas = new Main();
		canvas.setSize(500,500);
		frame.add(canvas);
		frame.pack();
		frame.setVisible(true);
		int[] array = {15,71,12,24,29};
		int even = 0;
		int odd = 0;
		for(int i = 0; i < array.length; i++) {
			if(array[i]%2==0) even+=1;
			else odd+=1;
		}
		System.out.println(even);
		System.out.println(odd);
	}
	
	public void paint(Graphics g) {
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 2; j++) {
				if((i+j)%2==0) {
					g.setColor(new Color(245,175,175));
					g.fillOval(100*i, 100*j+27, 40, 40);
					g.fillOval(100*i+25, 100*j+10, 40, 40);
					g.fillOval(100*i-25, 100*j+10, 40, 40);
					g.fillOval(100*i-15, 100*j-20, 40, 40);
					g.fillOval(100*i+15, 100*j-20, 40, 40);
					g.setColor(new Color(255,250,5));
					g.fillOval(100*i, 100*j, 40, 40);
					g.setColor(new Color(165,252,164));
					g.drawArc(100*i,100*j+50, 60, 250, 0, 70);
				}
			}
		}
	}
}
