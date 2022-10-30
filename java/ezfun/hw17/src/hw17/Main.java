package hw17;
import java.awt.*;       
import java.awt.event.*; 
import javax.swing.*; 

public class Main extends JFrame {
   private JTextField tfCount;   
   private JTextField tfCount2;
   private JTextField tfCount3; 
   private JButton btnCount;         
   private JButton btnCount2;         
   private int count = 0;
   private int count2 = 0;
   private int count3 = 0;
 
   public Main () {
      Container cp = getContentPane();
      cp.setLayout(new FlowLayout());
      cp.add(new JLabel("Fahrenheit: "));
      tfCount = new JTextField(10);
      cp.add(tfCount);
      
      cp.add(new JLabel("Celsius: "));
      
      tfCount2 = new JTextField(10);
      cp.add(tfCount2);
      
      btnCount = new JButton("F to C");
      cp.add(btnCount);

      btnCount2 = new JButton("C to F");
      cp.add(btnCount2);

      btnCount.addActionListener(new ActionListener() {

          public void actionPerformed(ActionEvent evt) {
              	String s = tfCount.getText();
              	int f = Integer.parseInt(s,10);
              	tfCount2.setText(""+(f-32)*5/9);
              }
       });
      btnCount2.addActionListener(new ActionListener() {

           public void actionPerformed(ActionEvent evt) {
               	String s = tfCount2.getText();
               	int c = Integer.parseInt(s,10);
               	tfCount.setText(""+((c*5/9)+32));
               }
        });
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
      setSize(600, 100);
      setVisible(true);    // show it
   }
 
   public static void main(String[] args) {
      new Main(); 
   }
}