package co.edu.unicauca.gbhs.model.objectivefunction;

import java.util.Random;

import co.edu.unicauca.gbhs.model.Record;

public class Schwefel implements ObjectiveFunction {

	private double minValue;
	private double maxValue;
	private int evaluationCount;

	public Schwefel() {
		this.minValue = -500;
		this.maxValue = 500;
		this.evaluationCount = 0;
	}

	@Override
	public boolean minimizes() {
		return true;
	}

	@Override
	public double calculate(Record record) {
		double ret = 0;
		double sum = 0;

		int i = 0;

		for (i = 0; i < record.getData().length; i++) {
			sum = sum + record.getData()[i] * Math.sin(Math.sqrt(Math.abs(record.getData()[i])));
		}

		ret = 418.9829 * record.getData().length - sum;

		this.evaluationCount++;
		return ret;
	}

	@Override
	public ObjectiveFunction newInstance() {
		return new Schwefel();
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
		return "Schwefel";
	}

	public int getEvaluationCount() {
		return this.evaluationCount;
	}

}
