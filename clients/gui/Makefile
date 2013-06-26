all:
	cpp -I ../../common GuiClient.jpp > GuiClient.java
	sed -i s/#.*// GuiClient.java
	javac GuiClient.java