import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.LinkedList;
import java.util.function.Consumer;

import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.Timer;

@SuppressWarnings("serial")
public class SnakePanel extends JPanel {
	
	private JLabel infoStart;
	private JLabel infoOver;
	
	private boolean inited;
	private boolean gameOver;
	private boolean gamePause;
	private boolean gameStart;
	
	private int direction;
	private int food;
	private int nextNode;
	private LinkedList<Integer> snakeNodes;
	
	private Timer timer;

	public SnakePanel() {
		this.setBackground(C.BGCOLOR);
		this.setLayout(null);
		this.setFocusable(true);
		this.addKeyListener(new KeyAdapter() {
			@Override
			public void keyPressed(KeyEvent e) {
				SnakePanel.this.keyPressed(e);
			}
		});
		
		Font font = new Font("黑体", Font.BOLD, 28);
		this.infoOver = new JLabel("游戏结束");
		this.infoOver.setHorizontalAlignment(JLabel.CENTER);
		this.infoOver.setFont(font);
		this.infoStart = new JLabel("按空格键开始或暂停游戏");
		this.infoStart.setHorizontalAlignment(JLabel.CENTER);
		this.infoStart.setFont(font);
		this.add(this.infoOver);
		this.add(this.infoStart);
		this.hideInfo();
		this.gameStart = false;
		
		this.direction = 1;
		
		this.snakeNodes = new LinkedList<>();
		this.food = -1;
		
		this.timer = new Timer(1000 / C.SPEED, new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				SnakePanel.this.snakeMove();
			}
		});
	}
	
	private void generateFood() {
		do {
			this.food = (int)(Math.random() * C.LINE_NUM * C.LINE_NUM);
		} while(this.snakeNodes.contains(this.food));
	}
	
	private void showInfo() {
		if(this.gameOver) {
			this.infoOver.setVisible(true);
		}
		this.infoStart.setVisible(true);
	}
	
	private void hideInfo() {
		this.infoOver.setVisible(false);
		this.infoStart.setVisible(false);
	}
	
	
	@Override
	public void paint(Graphics g) {
		super.paint(g);
		if(!this.inited) {
			this.initPaint(g);
			this.inited = true;
		}
		
	}
	
	private void initPaint(Graphics g) {
		g.setColor(C.GRIDCOLOR);
		
		for(int i = 0; i <= C.LINE_NUM; i++) {
			g.drawLine(0, i * C.UNIT_WIDTH, this.getWidth(), i * C.UNIT_WIDTH);
			g.drawLine(i * C.UNIT_WIDTH, 0, i * C.UNIT_WIDTH, this.getHeight());
		}
		
		// ？？？我当时为什么要用forEach这个写法？不是有简单写法？？？
		this.snakeNodes.forEach(new Consumer<Integer>() {
			@Override
			public void accept(Integer t) {
				SnakePanel.this.paintUnit(g, C.SNAKECOLOR, t);
			}
		});
		this.paintUnit(g, C.FOODCOLOR, this.food);
	}
	
	private void paintUnit(Graphics g, Color color, int pos) {
		g.setColor(color);
		g.fillRect(X(pos) + 1, Y(pos) + 1, C.UNIT_WIDTH - 1, C.UNIT_WIDTH - 1);
	}
	
	private int X(int pos) {
		return pos % C.LINE_NUM * C.UNIT_WIDTH;
	}
	
	private int Y(int pos) {
		return pos / C.LINE_NUM * C.UNIT_WIDTH;
	}
	





	private void keyPressed(KeyEvent e) {
		int temDirect = this.direction;
		switch (e.getKeyCode()) {
		case KeyEvent.VK_SPACE:
			if(!this.gameStart) {
				this.hideInfo();
				this.snakeNodes.clear();
				this.snakeNodes.add(3);
				this.snakeNodes.add(2);
				this.snakeNodes.add(1);
				this.direction = 1;
				this.nextNode = 4;
				this.generateFood();
				this.gameOver = false;
				this.gamePause = false;
				this.gameStart = true;
				this.inited = false;
				this.update(this.getGraphics());
			} else if (!this.gameOver) {
				this.gamePause = !this.gamePause;
			}
			if(!this.timer.isRunning()) {
				this.inited = false;
				this.timer.start();
			}
			break;
			
		case KeyEvent.VK_LEFT:
			this.setDirection(-1);
			break;
			
		case KeyEvent.VK_UP:
			this.setDirection(-C.LINE_NUM);
			break;
			
		case KeyEvent.VK_RIGHT:
			this.setDirection(1);
			break;
			
		case KeyEvent.VK_DOWN:
			this.setDirection(C.LINE_NUM);
			break;

		default:
			break;
		}
	}

	private void setDirection(int direction) {
		if (this.gameOver || this.gamePause) {
			return ;
		}
		int currentDirection = this.snakeNodes.get(0) - this.snakeNodes.get(1);
		this.direction = (direction == -currentDirection) ? currentDirection : direction;
	}

	private void snakeMove() {
		this.nextNode = this.snakeNodes.get(0) + this.direction;
		this.judgeOver();
		if(this.gameOver || this.gamePause) {
			this.timer.stop();
			return ;
		}
		this.snakeNodes.addFirst(this.nextNode);
		this.paintUnit(this.getGraphics(), C.SNAKECOLOR, this.nextNode);
		if(this.nextNode == this.food) {
			this.generateFood();
			this.paintUnit(this.getGraphics(), C.FOODCOLOR, this.food);
		} else {
			this.paintUnit(this.getGraphics(), C.BGCOLOR, this.snakeNodes.removeLast());
		}
		
	}

	private void judgeOver() {
		boolean hitSelf = this.snakeNodes.contains(this.nextNode);
		boolean hitWall = (this.nextNode < 0) || (this.nextNode > (C.LINE_NUM * C.LINE_NUM))
							|| ((this.direction == 1) && (this.nextNode % C.LINE_NUM == 0))
							|| ((this.direction == -1) && (this.nextNode % C.LINE_NUM == C.LINE_NUM - 1));
		if(hitSelf || hitWall) {
			this.gameOver = true;
			this.gameStart = false;
			this.gamePause = false;
			this.showInfo();
		}
	}

	public void initSomething() {
		this.infoOver.setBounds(0, 0, this.getWidth(), 30);
		this.infoStart.setBounds(0, 40, this.getWidth(), 30);
		this.showInfo();
	}











}
