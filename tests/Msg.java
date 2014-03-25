import java.awt.*;
import java.io.*;

public class Msg extends OutputStream {
    TextArea textarea;
    public static PrintStream out;

    Msg(TextArea ta) {
	textarea = ta;
	out = new PrintStream(this, true);
    }
 
    /**
     * java.io.OutputStream stuff
     */
    public void write(int b) throws IOException {
	if (textarea == null) {
	    System.out.write(b);
	} else {
	    textarea.append("" + (char)b);
	}
    }
}
