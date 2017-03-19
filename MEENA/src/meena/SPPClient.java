package meena;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import javax.bluetooth.RemoteDevice;
import javax.microedition.io.Connector;
import javax.microedition.io.StreamConnection;

public class SPPClient {

//    String remoteMac = "201306134612";
    //String remoteMac = "98d331400e00";
    String remoteMac;

    StreamConnection con;
    PrintWriter writer;
    BufferedReader reader;

    boolean isConnected = false;

    msgListener listener;

    SPPClient(msgListener listener, String mac) {
        this.listener = listener;
        this.remoteMac = mac;
    }

    public boolean connect() {
        try {
            String url = "btspp://" + remoteMac + ":1";
            con = (StreamConnection) Connector.open(url);
            reader = new BufferedReader(new InputStreamReader(con.openInputStream()));
            writer = new PrintWriter(con.openOutputStream());

            RemoteDevice dev = RemoteDevice.getRemoteDevice(con);
            System.out.println("Serverd:" + dev.getBluetoothAddress() + "\r\n" + "Connection Established!" + "\r\n");
        } catch (Exception ex) {
            System.out.println(ex);
            return false;
        }

        new sppListener().start();

        return true;
    }

   public class sppListener extends Thread {

        public void run() {
            isConnected = true;
            if (con != null) {
                while (isConnected) {
                    try {
                        String str = reader.readLine();
                        System.out.println("Received=" + str);
                        listener.onNewLine(str);
                    } catch (Exception ex) {
                        isConnected = false;
                    }
                }
            }
        }
    }

    public void sendLine(String line) {
        writer.println(line);
        writer.flush();
    }

    public void close() {
        try {
            reader.close();
            writer.close();
            con.close();
        } catch (Exception ex) {
        }
    }
}
