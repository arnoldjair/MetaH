package co.edu.unicauca.gbhs.model.objectivefunction;

import java.util.Random;

import co.edu.unicauca.gbhs.model.Record;

public class Rastrigin implements ObjectiveFunction {

	private double minValue;
	private double maxValue;
	private int evaluationCount;

	public Rastrigin() {
		this.minValue = -5.12;
		this.maxValue = 5.12;
		this.evaluationCount = 0;
	}

	@Override
	public boolean minimizes() {
		return true;
	}

	@Override
	public double calculate(Record record) {
		double ret = 0;

		int i = 0;

		double sum = 0;

		for (i = 0; i < record.getData().length; i++) {
			sum = sum + Math.pow((double) record.getData()[i], 2)
					- 10 * Math.cos(2 * Math.PI * (double) record.getData()[i]);
		}

		ret = 10 * record.getData().length + sum;

		this.evaluationCount++;
		return ret;
	}

	@Override
	public ObjectiveFunction newInstance() {
		return new Rastrigin();
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
		return "Rastrigin";
	}

	public int getEvaluationCount() {
		return this.evaluationCount;
	}

}
