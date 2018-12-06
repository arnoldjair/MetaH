package co.edu.unicauca.hs.model.objectivefunction;

import java.util.Random;

import co.edu.unicauca.hs.model.Record;

public class Griewank implements ObjectiveFunction {

	private double minValue;
	private double maxValue;

	public Griewank() {
		this.minValue = -600;
		this.maxValue = 600;
	}

	@Override
	public boolean minimizes() {
		return true;
	}

	@Override
	public double calculate(Record record) {
		double ret = 0;
		double sum_squares = 0;
		double product = 1;

		int i = 0;

		for (i = 0; i < record.getData().length; i++) {
			sum_squares = sum_squares + Math.pow(record.getData()[i], 2);
			product = product * Math.cos(record.getData()[i] / Math.sqrt(i + 1));
		}

		sum_squares = sum_squares / 4000;
		ret = sum_squares - product + 1;

		return ret;
	}

	@Override
	public ObjectiveFunction newInstance() {
		return new Griewank();
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
		return "Griewank";
	}

}
