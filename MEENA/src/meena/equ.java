package meena;

import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Port;

import edu.cmu.sphinx.api.Configuration;
import edu.cmu.sphinx.api.LiveSpeechRecognizer;
import edu.cmu.sphinx.api.SpeechResult;

//import ribofakeclientlib.RiboClientLib;
public class equ
{

    //static String robotIP = "localhost";
    //static RiboClientLib ribolib;
    // Logger
    private Logger logger = Logger.getLogger(getClass().getName());
    static SPPClient hand;

    // Variables
    private String result;

    // Threads
    Thread speechThread;
    Thread resourcesThread;

    // LiveRecognizer
    private LiveSpeechRecognizer recognizer;

    String r = null;

    /**
     * Constructor
     */
    public equ()
    {

        // Loading Message
        logger.log(Level.INFO, "Loading..\n");

        // Configuration
        Configuration configuration = new Configuration();

        // Load model from the jar
        configuration.setAcousticModelPath("resource:/edu/cmu/sphinx/models/en-us/en-us");
        configuration.setDictionaryPath("resource:/edu/cmu/sphinx/models/en-us/cmudict-en-us.dict");

        // if you want to use LanguageModelPath disable the 3 lines after which
        // are setting a custom grammar->
        // configuration.setLanguageModelPath("resource:/edu/cmu/sphinx/models/en-us/en-us.lm.bin")
        // Grammar
        configuration.setGrammarPath("grammars");
        configuration.setGrammarName("grammar");
        configuration.setUseGrammar(true);

        try {
            recognizer = new LiveSpeechRecognizer(configuration);
        } catch (IOException ex) {
            logger.log(Level.SEVERE, null, ex);
        }

        // Start recognition process pruning previously cached data.
        recognizer.startRecognition(true);

        // Start the Thread
        startSpeechThread();
        startResourcesThread();
    }

    /**
     * Starting the main Thread of speech recognition
     */
    protected void startSpeechThread()
    {

        // alive?
        if (speechThread != null && speechThread.isAlive()) {
            return;
        }

        // initialise
        speechThread = new Thread(() -> {
            logger.log(Level.INFO, "You can start to speak...\n");
            try {
                while (true) {
                    /*
                     * This method will return when the end of speech is
                     * reached. Note that the end pointer will determine the end
                     * of speech.
                     */
                    SpeechResult speechResult = recognizer.getResult();
                    if (speechResult != null) {

                        result = speechResult.getHypothesis();
                        //System.out.println("You said: [" + result + "]\n");
                        // logger.log(Level.INFO, "You said: " + result + "\n")
                        r = result.toString();

                    } else {
                        logger.log(Level.INFO, "I can't understand what you said.\n");
                    }

                }
            } catch (Exception ex) {
                logger.log(Level.WARNING, null, ex);
            }

            logger.log(Level.INFO, "SpeechThread has exited...");
        });

        // Start
        speechThread.start();

    }

    /**
     * Starting a Thread that checks if the resources needed to the
     * SpeechRecognition library are available
     */
    protected void startResourcesThread()
    {

        // alive?
        if (resourcesThread != null && resourcesThread.isAlive()) {
            return;
        }

        resourcesThread = new Thread(() -> {
            try {

                // Detect if the microphone is available
                while (true) {
                    if (AudioSystem.isLineSupported(Port.Info.MICROPHONE)) {
                        // logger.log(Level.INFO, "Microphone is available.\n")
                    } else {
                        // logger.log(Level.INFO, "Microphone is not
                        // available.\n")

                    }

                    // Sleep some period
                    Thread.sleep(350);
                }

            } catch (InterruptedException ex) {
                logger.log(Level.WARNING, null, ex);
                resourcesThread.interrupt();
            }
        });

        // Start
        resourcesThread.start();
    }

    /**
     * Takes a decision based on the given result
     */
    /**
     * Java Main Application Method
     *
     * @param args
     */
    public static void VoiceCom(SPPClient client)
    {

        int a, b, c, x1, x2;

        equ obj = new equ();

        hand = client;

        try {
            Thread.sleep(500);
        } catch (InterruptedException ex) {
            Logger.getLogger(equ.class.getName()).log(Level.SEVERE, null, ex);
        }

        while (true) {

            System.out.println("What do you wanna do?");
            System.out.println("solve equation??");
            System.out.println("command home ?");
            a = getcommand(obj);

            if (a == 1) {
                equ(obj);
            } else if (a == 2) {
                HomeCommand(obj, hand);
            }
        }
    }

    private static int getcommand(equ obj)
    {
        while (true) {

            try {
                Thread.sleep(500);
            } catch (InterruptedException ex) {
                Logger.getLogger(equ.class.getName()).log(Level.SEVERE, null, ex);
            }
            obj.r = null;
            System.out.println("tell me my command");
            while (obj.r == null) {
                try {
                    Thread.sleep(500);
                } catch (InterruptedException ex) {
                    Logger.getLogger(equ.class.getName()).log(Level.SEVERE, null, ex);
                }
            }

            System.out.println("command is " + obj.r);
            System.out.println("is it correct? say yes to continue and no to give input again");

            String temp = obj.r.toString();
            obj.r = null;
            while (obj.r == null) {
                try {
                    Thread.sleep(500);
                } catch (InterruptedException ex) {
                    Logger.getLogger(equ.class.getName()).log(Level.SEVERE, null, ex);
                }
            }

            if (obj.r.contains("yes")) {
                obj.r = temp;
                break;
            } else {
                continue;
            }

        }

        if (obj.r.contains("solve equation")) {
            return 1;
        } else if (obj.r.contains("command home")) {
            return 2;
        } else {
            return 5;
        }
    }

    private static void equ(equ obj)
    {
        String temp;
        while (true) {

            try {
                Thread.sleep(500);
            } catch (InterruptedException ex) {
                Logger.getLogger(equ.class.getName()).log(Level.SEVERE, null, ex);
            }
            obj.r = null;
            System.out.println("what type of equation do u wanna solve??");
            System.out.println("linear equation");
            System.out.println("quadratic equation");
            while (obj.r == null) {
                try {
                    Thread.sleep(500);
                } catch (InterruptedException ex) {
                    Logger.getLogger(equ.class.getName()).log(Level.SEVERE, null, ex);
                }
            }

            System.out.println("equation is " + obj.r);
            System.out.println("is it correct? say yes to continue and no to give input again");

            temp = obj.r.toString();
            obj.r = null;
            while (obj.r == null) {
                try {
                    Thread.sleep(500);
                } catch (InterruptedException ex) {
                    Logger.getLogger(equ.class.getName()).log(Level.SEVERE, null, ex);
                }
            }

            if (obj.r.contains("yes")) {
                obj.r = temp;
                break;
            } else {
                continue;
            }

        }
        if (temp == "linear equation") {
            equ.eqOne(obj);
        } else if (temp == "quadratic equation") {
            equ.eqTwo(obj);
        }
    }

    private static int getVal(equ obj, String st)
    {
        while (true) {

            try {
                Thread.sleep(500);
            } catch (InterruptedException ex) {
                Logger.getLogger(equ.class.getName()).log(Level.SEVERE, null, ex);
            }
            obj.r = null;
            if (st.contains("variable")) {
                System.out.println("tell me number of variables");
            } else {
                System.out.println("tell me value of " + st);
            }

            while (obj.r == null) {
                try {
                    Thread.sleep(500);
                } catch (InterruptedException ex) {
                    Logger.getLogger(equ.class.getName()).log(Level.SEVERE, null, ex);
                }
            }

            System.out.println("value of " + st + " is " + obj.r);
            System.out.println("is it correct? say yes to continue and no to give input again");

            String temp = obj.r.toString();
            obj.r = null;
            while (obj.r == null) {
                try {
                    Thread.sleep(500);
                } catch (InterruptedException ex) {
                    Logger.getLogger(equ.class.getName()).log(Level.SEVERE, null, ex);
                }
            }

            if (obj.r.contains("yes")) {
                obj.r = temp;
                break;
            } else {
                continue;
            }

        }

        if (obj.r.contains("one")) {
            return 1;
        }
        if (obj.r.contains("two")) {
            return 2;
        }
        if (obj.r.contains("three")) {
            return 3;
        }
        if (obj.r.contains("four")) {
            return 4;
        }
        if (obj.r.contains("five")) {
            return 5;
        }
        if (obj.r.contains("five")) {
            return 5;
        }
        if (obj.r.contains("six")) {
            return 6;
        }
        if (obj.r.contains("seven")) {
            return 7;
        }
        if (obj.r.contains("eight")) {
            return 8;
        }
        if (obj.r.contains("nine")) {
            return 9;
        }
        if (obj.r.contains("ten")) {
            return 9;
        }

        return 0;
    }

    private static void eqOne(equ obj)
    {
        while (true) {
            int a, b, c, x1, x2;

            System.out.println("hey we are going to solve simple quadratic equation");

            a = getVal(obj, "a");
            b = getVal(obj, "b");
            c = getVal(obj, "c");

            x1 = (int) (-b + Math.sqrt((b * b) + (4 * a * c)));
            x1 = x1 / (2 * a);

            x2 = (int) (-b - Math.sqrt((b * b) + (4 * a * c)));
            x2 = x2 / (2 * a);

            System.out.println(x1);
            System.out.println(x2);

            System.out.println("Want to continue solving this type of equation? say yes or no");

            if (getYN(obj) == false) {
                break;
            }
        }
    }

    private static void eqTwo(equ obj)
    {
        while (true) {
            int a, b, c, x1, x2;

            System.out.println("hey we are going to solve simple linear equation");

            a = getVal(obj, "variables");

            double[][] mat = new double[a][a];
            double[][] constants = new double[a][1];
            for (int i = 0; i < a; i++) {
                String value1 = "a";
                int j;
                String value2 = "0";
                for (j = 0; j < a; j++) {
                    int charValue = value1.charAt(0);
                    String next = String.valueOf((char) (charValue + j));

                    int charValue2 = value2.charAt(0);
                    String next2 = String.valueOf((char) (charValue2 + i));

                    String s = next + next2;
                    int n = getVal(obj, s);
                    mat[i][j] = (double) n;
                }
                int charValue2 = value2.charAt(0);
                String next2 = String.valueOf((char) (charValue2 + i));
                int charValue = value1.charAt(0);
                String next = String.valueOf((char) (charValue + j));
                String x = next + next2;
                int m = getVal(obj, x);
                constants[i][0] = (double) m;
            }
            invert ob = new invert();
            double inverted_mat[][] = ob.inverts(mat);

            double result[][] = new double[a][1];
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < 1; j++) {
                    for (int k = 0; k < a; k++) {
                        result[i][j] = result[i][j] + inverted_mat[i][k] * constants[k][j];
                    }
                }
            }
            System.out.println("The product is:");
            //speak("The product is");
            for (int i = 0; i < a; i++) {
                System.out.println(result[i][0] + " ");
                String s = String.format("%lf", result[i][0]);
                //speak(s);
            }

            System.out.println("Want to continue solving this type of equation? say yes or no");

            if (getYN(obj) == false) {
                break;
            }
        }
    }

    private static boolean getYN(equ obj)
    {

        String temp = obj.r.toString();
        obj.r = null;
        while (obj.r == null) {
            try {
                Thread.sleep(200);
            } catch (InterruptedException ex) {
                Logger.getLogger(equ.class.getName()).log(Level.SEVERE, null, ex);
            }
        }

        if (obj.r.contains("yes")) {
            return true;
        } else {
            return false;
        }
    }

    public static void HomeCommand(equ obj, SPPClient hand)
    {

        String temp;
        while (true) {

            while (true) {

                try {
                    Thread.sleep(500);
                } catch (InterruptedException ex) {
                    Logger.getLogger(equ.class.getName()).log(Level.SEVERE, null, ex);
                }
                obj.r = null;
                System.out.println("what do you wanna do??");
                while (obj.r == null) {
                    try {
                        Thread.sleep(500);
                    } catch (InterruptedException ex) {
                        Logger.getLogger(equ.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }

                System.out.println("you said " + obj.r);
                System.out.println("is it correct? say yes to continue and no to give input again");

                temp = obj.r.toString();
                obj.r = null;
                while (obj.r == null) {
                    try {
                        Thread.sleep(500);
                    } catch (InterruptedException ex) {
                        Logger.getLogger(equ.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }

                if (obj.r.contains("yes")) {
                    obj.r = temp;
                    break;
                } else {
                    continue;
                }
            }
            if (temp.contains("light") && temp.contains("on")) {
                hand.sendLine("o");
            } else if (temp.contains("light") && temp.contains("off")) {
                hand.sendLine("n");
            } else if (temp.contains("bring") && temp.contains("glass")) {
                hand.sendLine("b");
            } else if (temp.contains("take") && temp.contains("glass")) {
                hand.sendLine("t");
            }
            
             
              System.out.println("Want to continue? say yes to continue and no to go to chat bot");

                temp = obj.r.toString();
                obj.r = null;
                while (obj.r == null) {
                    try {
                        Thread.sleep(500);
                    } catch (InterruptedException ex) {
                        Logger.getLogger(equ.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }

                if (obj.r.contains("yes")) {
                    continue;
                } else {
                    break;
                }
        }
    }
    /*private static void speak(String res)
     {
        
     int x = res.length();

     if (ribolib.isRobotFree) {
     System.out.println(res);
     ribolib.doSpeakOnRibo(res);

     } else {
     System.out.println("robot is busy");
     }

     try {
     Thread.sleep(x*150);
     } catch (InterruptedException ex) {
     Logger.getLogger(equ.class.getName()).log(Level.SEVERE, null, ex);
     }
     }*/
}
