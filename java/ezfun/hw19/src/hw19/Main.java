package hw19;
import java.awt.*; 
import java.awt.event.*; 
import javax.swing.*;
import java.net.MalformedURLException;
import java.net.URL;

public class Main extends JFrame {
	int dogCount, catCount;
	public Main() throws MalformedURLException {
		JButton buttons[] = new JButton[2]; 

		JLabel jl1 = new JLabel("Result");
		jl1.setFont(new Font("Serif", Font.PLAIN, 40));

		Container c1 = getContentPane();
		c1.setLayout(new GridLayout(2,1));


		JPanel p1 = new JPanel(new GridLayout(1, 2));

		//add your code here
		ImageIcon i0 = new ImageIcon(new ImageIcon(new URL("https://www.thedogandfriends.com/assets/img/index/img-hero_dog.png")).getImage().getScaledInstance(300, 300, Image.SCALE_DEFAULT));
		ImageIcon i1 = new ImageIcon(new ImageIcon(new URL("https://m.media-amazon.com/images/I/71+mDoHG4mL.png")).getImage().getScaledInstance(300, 300, Image.SCALE_DEFAULT));
		buttons[0] = new JButton(i0);
		buttons[1] = new JButton(i1);
		buttons[0].addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
            	dogCount++;
            	jl1.setText("Dogs:"+dogCount+" Cats:"+catCount);
            }
		});
		buttons[1].addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
            	catCount++;
            	jl1.setText("Dogs:"+dogCount+" Cats:"+catCount);
            }
		});
		p1.add(buttons[0]);
		p1.add(buttons[1]);
		add(p1);
		
		JPanel p2 = new JPanel(new FlowLayout());
		p2.add(jl1);
		add(p2);

		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
		setSize(1000, 1000);
		setVisible(true); 

	}
	public static int mystery(int x) {
		if (x == 0)
			return 2;
		else return 2 * mystery(x-1);
	}
	public static void main(String[] args) throws MalformedURLException {
		System.out.println(mystery(6));
		new Main();
	}
}

