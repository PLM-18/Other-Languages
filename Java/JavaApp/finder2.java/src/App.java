import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import java.awt.Color;

public class App 
{
    public static void MakeFrame(ImageIcon newImage)
    {
        JFrame newFrame = new JFrame();
        JButton newButton = new JButton("Hello");
        newFrame.setTitle("Family Finder");
        newFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        newFrame.setSize(1100,1100);
        newFrame.setVisible(true);
        newButton.add(newFrame);
        //Styling the App elements
        newFrame.setIconImage(newImage.getImage());
        newFrame.getContentPane().setBackground(new Color(250, 250, 250));
    }

    public static ImageIcon importImages()
    {
        ImageIcon newImage = new ImageIcon("logo.png");
        return newImage;
    }

    public static void main(String[] args)
    {
        MakeFrame(importImages());
    }
}
