package co.edu.unicauca.gbhs.model.objectivefunction;

import java.util.Random;

import co.edu.unicauca.gbhs.model.Record;

public class Sphere implements ObjectiveFunction {

	private double minValue;
	private double maxValue;
	private int evaluationCount;

	public Sphere() {
		this.minValue = -100;
		this.maxValue = 100;
		this.evaluationCount = 0;
	}

	@Override
	public boolean minimizes() {
		return true;
	}

	@Override
	public double calculate(Record record) {
		double ret = 0;
		for (int i = 0; i < record.getData().length; ++i) {
			ret += Math.pow(record.getData()[i], 2);
		}
		
		this.evaluationCount++;
		return Math.sqrt(ret);
	}

	@Override
	public ObjectiveFunction newInstance() {
		return new Sphere();
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
		return "Sphere";
	}
	
	public int getEvaluationCount() {
		return this.evaluationCount;
	}

}
