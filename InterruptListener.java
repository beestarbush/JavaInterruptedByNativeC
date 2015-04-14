import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;

public class InterruptListener implements PropertyChangeListener {

	@Override
	public void propertyChange(PropertyChangeEvent evt) {
		System.out.println(evt.getPropertyName());
		System.out.println(System.nanoTime());
	}
}