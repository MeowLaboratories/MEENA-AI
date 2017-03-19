package meena;

import java.awt.BorderLayout;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class RoverGUI extends JFrame implements KeyListener
{

    //JTextField keyText = new JTextField();
    JLabel keyLabel = new JLabel("Press A to move left");

    private JPanel contentPane;
    static SPPClient rover;

    /**
     * Launch the application.
     */
    public static void main(String[] args)
    {
        EventQueue.invokeLater(new Runnable()
        {
            public void run()
            {
                try {
                    RoverGUI frame = new RoverGUI(rover);
                    frame.setVisible(true);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }

    /**
     * Create the frame.
     */
    public RoverGUI(SPPClient client)
    {
        this.rover = client;
        addKeyListener(this);
        setFocusable(true);
        setFocusTraversalKeysEnabled(false);

        //keyText.setBounds(5, 236, 424, 20);
        //keyText.addKeyListener(this);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(100, 100, 450, 300);
        contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        setContentPane(contentPane);
        contentPane.setLayout(null);
        contentPane.setLayout(null);
        keyLabel.setBounds(5, 5, 424, 14);
        getContentPane().add(keyLabel);
        //getContentPane().add(keyText);

        JLabel lblPressWTo = new JLabel("Press W to move forward");
        lblPressWTo.setBounds(5, 30, 380, 14);
        contentPane.add(lblPressWTo);

        JLabel lblPressDTo = new JLabel("Press D to move right");
        lblPressDTo.setBounds(5, 55, 271, 14);
        contentPane.add(lblPressDTo);

        JLabel lblPressSTo = new JLabel("Press S to move back");
        lblPressSTo.setBounds(5, 79, 271, 14);
        contentPane.add(lblPressSTo);
        
        JLabel lblPressSpaceTo = new JLabel("Press Space to go back to chat MODE");
        lblPressSpaceTo.setBounds(5, 104, 271, 14);
        contentPane.add(lblPressSpaceTo);

        

        /*JButton btnChangeBack = new JButton("Change Back");
         btnChangeBack.addActionListener(new ActionListener() {
         public void actionPerformed(ActionEvent e) {
         dispose();
         lara_the_wise_gui chatscreen = new lara_the_wise_gui();
         chatscreen.setVisible(true);
         }
         });
         btnChangeBack.setBounds(200, 214, 181, 23);
         contentPane.add(btnChangeBack);*/
    }

    @Override
    public void keyPressed(KeyEvent e)
    {
        int keyCode = e.getKeyCode();
        //servo
        if (keyCode == KeyEvent.VK_W) {

            rover.sendLine("a");
        } else if (keyCode == KeyEvent.VK_S) {

            rover.sendLine("c");
        } else if (keyCode == KeyEvent.VK_E) {

            rover.sendLine("b");
        } else if (keyCode == KeyEvent.VK_R) {

            rover.sendLine("d");
        } //chakka
        else if (keyCode == KeyEvent.VK_UP) {

            rover.sendLine("f");
        } else if (keyCode == KeyEvent.VK_DOWN) {

            rover.sendLine("z");
        } else if (keyCode == KeyEvent.VK_RIGHT) {

            rover.sendLine("x");
        } else if (keyCode == KeyEvent.VK_LEFT) {

            rover.sendLine("y");
        } else if (keyCode == KeyEvent.VK_SPACE) {
            dispose();
            ChatGUI chatscreen = new ChatGUI();
            chatscreen.setVisible(true);
        }

        try {
            Thread.sleep(1);
            rover.sendLine("m");
        } catch (InterruptedException ex) {
            Logger.getLogger(RoverGUI.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

@Override
        public void keyReleased(KeyEvent e) {
        // TODO Auto-generated method stub
       
    }
 
    @Override
        public void keyTyped(KeyEvent e) {
        // TODO Auto-generated method stub
       
    }
}
