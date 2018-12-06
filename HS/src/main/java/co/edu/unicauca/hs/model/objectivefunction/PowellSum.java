package co.edu.unicauca.hs.model.objectivefunction;

import java.util.Random;

import co.edu.unicauca.hs.model.Record;

public class PowellSum implements ObjectiveFunction {

	private double minValue;
	private double maxValue;

	public PowellSum() {
		this.minValue = -1;
		this.maxValue = 1;
	}

	@Override
	public boolean minimizes() {
		return true;
	}

	@Override
	public double calculate(Record record) {
		double ret = 0;

		  for (int i = 0; i < record.getData().length; ++i) {
		    ret += Math.pow(Math.abs(record.getData()[i]), i + 2);
		  }

		  return ret;
	}

	@Override
	public ObjectiveFunction newInstance() {
		return new PowellSum();
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
		return "PowellSum";
	}

}
