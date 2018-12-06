package co.edu.unicauca.gbhs.model.objectivefunction;

/**
 *
 * @author Arnold Jair Jimenez Vargas <ajjimenez@unicauca.edu.co>
 */
public class ObjectiveFunctionFactory {

	public static ObjectiveFunction getObjectiveFuncion(String function) {
		switch (function) {
		case "ackley":
			return new Ackley();
		case "griewank":
			return new Griewank();
		case "powellSum":
			return new PowellSum();
		case "rastrigin":
			return new Rastrigin();
		case "schwefel":
			return new Schwefel();
		case "sphere":
			return new Sphere();
		}
		return null;
	}
}
