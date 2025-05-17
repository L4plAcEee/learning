import java.awt.Color;
import java.awt.Dimension;
import java.awt.HeadlessException;
import java.awt.Toolkit;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JFrame;

@SuppressWarnings("serial")
public class SnakeFrame extends JFrame {
	
	private SnakePanel snakePanel;

	public SnakeFrame() throws HeadlessException {
		this("");
	}

	public SnakeFrame(String title) throws HeadlessException {
		super(title);
		Toolkit toolkit = Toolkit.getDefaultToolkit();
		Dimension dim = toolkit.getScreenSize();
		this.setBounds((dim.width - C.FRAME_W) / 2, (dim.height - C.FRAME_H) / 2, C.FRAME_W, C.FRAME_H);
		this.snakePanel = new SnakePanel();
		this.setContentPane(this.snakePanel);
		
		this.setVisible(true);
		this.setResizable(false);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		this.addWindowListener(new WindowAdapter() {
			@Override
			public void windowOpened(WindowEvent e) {
				SnakeFrame.this.windowOpened(e);
			}
		});
	}
	
	private void windowOpened(WindowEvent e) {
		this.snakePanel.initSomething();
	}

}
