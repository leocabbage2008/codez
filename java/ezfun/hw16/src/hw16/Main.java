package hw16;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class Main extends JFrame{
	public JTextField count1,count2,count3;
	public int[] c = {0,1,2};
	public JButton button1;
	
	public static void add1(int[] i) {
		i[0]++;
		i[1]++;
		i[2]++;
	}
	public Main() {
		Container cp = getContentPane();
		cp.setLayout(new FlowLayout());
		cp.add(new JLabel("Counter"));	
		count1 = new JTextField(10);
		cp.add(count1);
		count2 = new JTextField(10);
		cp.add(count2);
		count3 = new JTextField(10);
		cp.add(count3);
		
		button1 = new JButton("Count");
		cp.add(button1);
		button1.addActionListener(new ActionListener() {
			
			public void actionPerformed(ActionEvent e) {
				add1(c);
				System.out.println(count1.getText());
				count1.setText(c[0]+" ");
				count2.setText(c[1]+" ");
				count3.setText(c[2]+" ");
			}
		});
		
		setSize(500,200);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new Main();
		int min = Integer.MAX_VALUE;
		Scanner kb = new Scanner(System.in);
		String s = kb.nextLine();
		kb.close();
		ArrayList<String[]> a = new ArrayList<String[]>();
		for(int i = 0; i < s.length(); i++) {
			String[] t = {Character.toString(s.charAt(i)), Integer.toString(i)};
			a.add(t);
		}
        Collections.sort(a,new Comparator<String[]>() {
            public int compare(String[] strings, String[] otherStrings) {
                return strings[0].compareTo(otherStrings[0]);
            }
        });
        for(int i = 0; i < a.size()-1; i++) {
        	if(a.get(i)[0].charAt(0)!=a.get(i+1)[0].charAt(0)) {
        		if(Integer.parseInt(a.get(i)[1])<min) {
        			min=Integer.parseInt(a.get(i)[1]);
        		}
        	}
        }
        System.out.println(min);
	}
}
