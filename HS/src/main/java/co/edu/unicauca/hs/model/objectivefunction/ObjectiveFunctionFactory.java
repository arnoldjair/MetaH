package co.edu.unicauca.hs.model.objectivefunction;

/**
 *
 * @author Arnold Jair Jimenez Vargas <ajjimenez@unicauca.edu.co>
 */
public class ObjectiveFunctionFactory {

	public static ObjectiveFunction getObjectiveFuncion(String function) {
		switch (function) {
		case "sphere":
			return new Sphere();
		case "ackley":
			return new Ackley();
		}
		return null;
	}
}
