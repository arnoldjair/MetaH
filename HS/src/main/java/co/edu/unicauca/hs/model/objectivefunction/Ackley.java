package co.edu.unicauca.hs.model.objectivefunction;

import java.util.Random;

import co.edu.unicauca.hs.model.Record;

public class Ackley implements ObjectiveFunction {

	private double minValue;
	private double maxValue;

	public Ackley() {
		this.minValue = -32.768;
		this.maxValue = 32.768;
	}

	@Override
	public boolean minimizes() {
		return true;
	}

	@Override
	public double calculate(Record record) {
		double ret = 0;

		double sum_x = 0;
		double sum_cos = 0;

		int i = 0;

		for (i = 0; i < record.getData().length; i++) {
			sum_x = sum_x + Math.pow(record.getData()[i], 2);
			sum_cos = sum_cos + Math.cos(2 * Math.PI * record.getData()[i]);
		}

		ret = -20 * Math.exp(-0.2 * Math.sqrt(sum_x / record.getData().length))
				- Math.exp(sum_cos / record.getData().length) + 20 + Math.exp(1);

		return ret;
	}

	@Override
	public ObjectiveFunction newInstance() {
		return new Ackley();
	}

	@Override
	public double getMinValue() {
		return this.minValue;
	}

	@Override
	public double getmaxValue() {
		return this.maxValue;
	}

	@Override
	public double getRandomValue(Random random) {
		return minValue + random.nextDouble() * (maxValue - minValue);
	}

	public String toString() {
		return "Ackley";
	}

}
