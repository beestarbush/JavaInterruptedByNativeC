public class StartProgram{

	public native void printText();
	public native void initializeInterruptHandler(InterruptHandler handler);

	static {
		System.loadLibrary("nativeclass");
	}

	public static void main(String[] args) {
		StartProgram program = new StartProgram();
		InterruptHandler handler = new InterruptHandler();
		InterruptListener listener = new InterruptListener();

		handler.addPropertyChangeListener(listener);
		program.initializeInterruptHandler(handler);
		// handler.firePropertyChangeInterruptHandler("Sensor 1");
		program.printText();
	}
}