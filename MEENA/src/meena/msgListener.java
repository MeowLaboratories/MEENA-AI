
package meena;


public interface msgListener {
    
    public void onNewLine(String line);
    public void onJoy(boolean[] buttons, int analog);
}