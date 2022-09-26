package hw15;
import java.awt.*;
import java.awt.event.*;
import javax.swing.Timer;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class Main extends JPanel implements ActionListener, MouseListener {

  Timer t = new Timer(200, this);
  int[] x = new int[100];
  int[] y = new int[100];
  int[] radius = new int[100];
  static int[] rand = new int[100];
  Color[] colors = new Color[100];
  int count = 0;

  public Main() {
    addMouseListener(this);
  }

  public static void main(String[] args) {
	for(int i = 0; i < 100; ++i) {
		rand[i] = (int)(Math.random()*100+5);
	}
    JFrame frame = new JFrame();
    Main c = new Main();
    frame.setPreferredSize(new Dimension(1000, 1000));
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.add(c);
    frame.pack();
    frame.setVisible(true);

  }

  public void paintComponent(Graphics g) {
    for (int i = 0; i < count; i++) {
      g.setColor(Color.WHITE);
      g.fillOval(x[i], y[i], radius[i], radius[i]);
      g.setColor(colors[i]);
      int r = radius[i];
      while (r > 0) {
        g.drawOval(x[i] + (radius[i] - r) / 2, y[i] + (radius[i] - r) / 2, r, r);
        r -= rand[i];
      }
    }
  }

  @Override
  public void mouseClicked(MouseEvent e) {
    // TODO Auto-generated method stub
    int rand = (int)(Math.random() * 400+20);
    radius[count] = rand;
    x[count] = e.getX() - rand / 2;
    y[count] = e.getY() - rand / 2;
    colors[count] = new Color((int)(Math.random() * 255), (int)(Math.random() * 255), (int)(Math.random() * 255));
    count++;
    repaint();
  }

  @Override
  public void mousePressed(MouseEvent e) {
    // TODO Auto-generated method stub

  }

  @Override
  public void mouseReleased(MouseEvent e) {
    // TODO Auto-generated method stub

  }

  @Override
  public void mouseEntered(MouseEvent e) {
    // TODO Auto-generated method stub

  }

  @Override
  public void mouseExited(MouseEvent e) {
    // TODO Auto-generated method stub

  }

  @Override
  public void actionPerformed(ActionEvent e) {
    // TODO Auto-generated method stub

  }
}