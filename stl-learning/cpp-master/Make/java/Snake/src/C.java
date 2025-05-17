import java.awt.Color;

public final class C {
	// 格子行列数
	public static final int LINE_NUM = 20;
	
	// 格子宽度
	public static final int UNIT_WIDTH = 20;
	
	// Frame的宽度
	public static final int FRAME_W = LINE_NUM * UNIT_WIDTH + 16;
	
	// Frame的高度
	public static final int FRAME_H = LINE_NUM * UNIT_WIDTH + 39; 
	
	// 速度 范围为1~10
	public static final int SPEED = 5;
	
	// 背景颜色
	public static final Color BGCOLOR = Color.GRAY;
	
	// 格子线颜色
	public static final Color GRIDCOLOR = new Color(120, 120, 120);
	
	// 蛇身颜色
	public static final Color SNAKECOLOR = Color.BLACK;
	
	// 食物颜色
	public static final Color FOODCOLOR = Color.GREEN;
}
