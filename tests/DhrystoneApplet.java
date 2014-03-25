import java.applet.Applet;
import java.awt.Panel;
import java.awt.Label;
import java.awt.Button;
import java.awt.TextArea;
import java.awt.TextField;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class DhrystoneApplet extends Applet
    implements ExitObserver, ActionListener {

    TextField runsText;
    Button startButton;

    public void init() {
	setLayout(new BorderLayout());
	
	TextArea ta = new TextArea();
	ta.setEditable(false);
	add(ta, BorderLayout.CENTER);
	new Msg(ta);
	
	Panel p = new Panel();
	p.setLayout(new FlowLayout());

	p.add(new Label("Number of runs:"));

	runsText = new TextField();
	runsText.setText("10000000");
	p.add(runsText);

	startButton = new Button("Run benchmark");
	startButton.addActionListener(this);
	p.add(startButton);

	add(p, BorderLayout.SOUTH);
    }

    public void actionPerformed(ActionEvent ev) {
	disableButtons();
	dhry dh = new dhry();
	dh.setExitObserver(this);
	try {
	    dh.Number_Of_Runs = Long.valueOf(runsText.getText()).longValue();
	} catch (NumberFormatException e) {
	}
	Thread dt = new Thread(dh);
	dt.start();
    }

    void disableButtons() {
	startButton.setEnabled(false);
    }

    /**
     * ExitObserver stuff
     */
    public void exitNotify()  {
	startButton.setEnabled(true);
    }

}
