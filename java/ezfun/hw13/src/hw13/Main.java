package hw13;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

class Main extends JPanel implements ActionListener, MouseListener{
  Timer t = new Timer(10, this);
  
  int NUMBALLS = 1000;
  int[] x=new int[NUMBALLS];
  int[] y=new int[NUMBALLS];
  int[] xSpeed=new int[NUMBALLS];
  int[] ySpeed=new int[NUMBALLS];
  int[] radius=new int[NUMBALLS];
  boolean[] show=new boolean[NUMBALLS];
  Color[] colors=new Color[NUMBALLS];
  int c = 0;
  
  public Main() {
	  for (int i =0; i<NUMBALLS; i++) {
		  x[i] = (int) (Math.random()*1000);
		  y[i] = (int) (Math.random()*500);
		  xSpeed[i] = (int) (Math.random()*5+1);
		  ySpeed[i] = (int) (Math.random()*5+1);
		  radius[i] = (int) (Math.random()*100+40);
		  int rval = (int)(Math.random()*255);
		  int gval = (int)(Math.random()*255);
		  int bval = (int)(Math.random()*255);
		  colors[i] = new Color(rval, gval, bval);
		  show[i]=true;
	  }
  }
  
  public static void main(String[] args) {
    Main m = new Main();
    JFrame j = new JFrame();
    j.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    j.setSize(600, 600);
    j.add(m);
    j.setVisible(true);
    j.addMouseListener(m);
    
  }
  

  public void paintComponent(Graphics g) {
    super.paintComponent(g); // paint the background
    g.setFont(new Font("bruh",50,50));
    g.drawString("SCORE: "+c, 200, 100);
    for (int i =0; i<NUMBALLS; i++) {
    	if(show[i]) {    		
    		g.setColor(colors[i]);
    		g.fillOval(x[i], y[i], radius[i], radius[i]);   
    	}
    }
    t.start();
  }
  
  public void actionPerformed(ActionEvent e) {
	  for (int i =0; i<NUMBALLS; i++) {  
		  if(show[i]) {			  
			  x[i] += xSpeed[i];
			  y[i] += ySpeed[i];
			  if (x[i] > 500 || x[i] < 0)
				  xSpeed[i] = -xSpeed[i];
			  if (y[i] > 500 || y[i] <= 0)
				  ySpeed[i] = -ySpeed[i];
		  }
	  }
	  repaint();
  }

	@Override
	public void mouseClicked(MouseEvent e) {
		for(int i = 0; i < NUMBALLS; ++i) {
			if((Math.abs(x[i]-e.getX())<radius[i])&&(Math.abs(y[i]-e.getY())<radius[i])) {				
				show[i]=false;
				c++;
			}
		}
		
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
}