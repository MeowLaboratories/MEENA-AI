package meena;

import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Scanner;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;

public class Meena implements msgListener
{

    static SPPClient hand;
    static SPPClient rover;

    public Meena()
    {
        System.out.println("BT Remote Desktop");
        System.out.println("Connecting with Robots...");
        hand = new SPPClient(this, "98d3317030db");
        System.out.println("HAND BT MAC:" + hand.remoteMac);
        boolean success = hand.connect();
        System.out.println("HAND Connection: " + success);

        rover = new SPPClient(this, "98d331fc1472");
        System.out.println("Rover BT MAC:" + rover.remoteMac);
        success = rover.connect();
        System.out.println("Rover Connection: " + success);
    }

    public static void main(String[] args)
    {
        new Meena();
        WiseMeow lara = new WiseMeow();

        String res;
        String[] temp = new String[100];
        String str;

        int i, l, k;

        WiseMeow kevin = new WiseMeow();

        System.out.println("Hi, I am Meena!");
        //voice.speak("Hi , I am kevin...... I am a intellectual chatbot... ask me anything.");

        Scanner s1 = new Scanner(System.in);

        while (true) {

            //test
            //test ends
            System.out.println("You: ");//get the query to search

            str = s1.nextLine();
            str.toLowerCase();

            System.out.print("Meena: ");

            if (str.contains("bring") && str.contains("glass")) {
                hand.sendLine("b");
                System.out.println("ok boss");
            } else if (str.contains("take") && str.contains("glass")) {
                hand.sendLine("t");
                System.out.println("ok boss");
            } else if (str.contains("light on")) {
                hand.sendLine("o");
                System.out.println("ok boss");
            } else if (str.contains("light off")) {
                hand.sendLine("n");
                System.out.println("ok boss");
            } else {
                res = kevin.chat(str);

                System.out.println(res);
                //voice.speak(res);

                l = res.length();
            }

        }
    }

    @Override
    public void onNewLine(String line)
    {
        //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void onJoy(boolean[] buttons, int analog)
    {
        //To change body of generated methods, choose Tools | Templates.
    }

    public void BT_SEND(String mac, String data)
    {
        SPPClient hand;
        SPPClient rover;
        if (mac.contains("rover")) {
            rover = new SPPClient(this, "98d331fc1472");
            System.out.println("Rover BT MAC:" + rover.remoteMac);
            boolean success = rover.connect();
            System.out.println("Rover Connection: " + success);

            rover.sendLine(data);

        } else {
            // System.out.println("Connecting with Robots...");
            hand = new SPPClient(this, "98d3317030db");
            System.out.println("HAND BT MAC:" + hand.remoteMac);
            boolean success = hand.connect();
            System.out.println("HAND Connection: " + success);
            hand.sendLine(data);
        }
    }

}
