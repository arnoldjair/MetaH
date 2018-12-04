package co.edu.unicauca.hs.model;

public class Result implements Comparable<Result>{

	private int numExperiments;
	private String objectiveFunction;
	private double results[];
	
	public int getNumExperiments() {
		return numExperiments;
	}



	public void setNumExperiments(int numExperiments) {
		this.numExperiments = numExperiments;
	}



	public String getObjectiveFunction() {
		return objectiveFunction;
	}



	public void setObjectiveFunction(String objectiveFunction) {
		this.objectiveFunction = objectiveFunction;
	}



	public double[] getResults() {
		return results;
	}



	public void setResults(double[] results) {
		this.results = results;
	}



	@Override
	public int compareTo(Result arg0) {
		// TODO Auto-generated method stub
		return 0;
	}

}
