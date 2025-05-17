snake.jar : C.class Main.class SnakeFrame.class SnakePanel.class
	jar -cvfe snake.jar Main *.class

C.class : C.java
	javac C.java

Main.class : Main.java
	javac Main.java

SnakeFrame.class : SnakeFrame.java
	javac SnakeFrame.java

SnakePanel.class : SnakePanel.java
	javac SnakePanel.java

.PHONY: clean
clean:
	rm *.class *.jar