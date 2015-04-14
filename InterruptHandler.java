import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeSupport;

public class InterruptHandler {
	PropertyChangeSupport propertyChangeSupport;
	
	public InterruptHandler() {
		this.propertyChangeSupport = new PropertyChangeSupport(this);
	}
	
	public void firePropertyChangeInterruptHandler(String sourceOfInterrupt) {
		propertyChangeSupport.firePropertyChange(sourceOfInterrupt, null, null);
	}
	
	public void addPropertyChangeListener(PropertyChangeListener listener) {
		propertyChangeSupport.addPropertyChangeListener(listener);
	}
}
	