package co.edu.unicauca.gbhs.model;

public class Result implements Comparable<Result> {

	private double results[];
	private int hms;
	private int maxImprovisations;
	private double minPar;
	private double maxPar;
	private double hmcr;
	private String function;
	private int size;
	private int nExp;
	private long seed;
	private double mean;

	public double[] getResults() {
		return results;
	}

	public void setResults(double[] results) {
		this.results = results;
	}

	public int getHms() {
		return hms;
	}

	public void setHms(int hms) {
		this.hms = hms;
	}

	public int getMaxImprovisations() {
		return maxImprovisations;
	}

	public void setMaxImprovisations(int maxImprovisations) {
		this.maxImprovisations = maxImprovisations;
	}

	public double getMinPar() {
		return minPar;
	}

	public void setMinPar(double minPar) {
		this.minPar = minPar;
	}

	public double getMaxPar() {
		return maxPar;
	}

	public void setMaxPar(double maxPar) {
		this.maxPar = maxPar;
	}

	public double getHmcr() {
		return hmcr;
	}

	public void setHmcr(double hmcr) {
		this.hmcr = hmcr;
	}

	public String getFunction() {
		return function;
	}

	public void setFunction(String function) {
		this.function = function;
	}

	public int getSize() {
		return size;
	}

	public void setSize(int size) {
		this.size = size;
	}

	public int getnExp() {
		return nExp;
	}

	public void setnExp(int nExp) {
		this.nExp = nExp;
	}

	public long getSeed() {
		return seed;
	}

	public void setSeed(long seed) {
		this.seed = seed;
	}

	public double getMean() {
		return mean;
	}

	public void setMean(double mean) {
		this.mean = mean;
	}

	@Override
	public int compareTo(Result arg0) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append(this.hms).append("\t").append(this.maxImprovisations).append("\t").append(this.minPar).append("\t")
				.append(this.maxPar).append("\t").append(this.hmcr).append("\t").append(this.function).append("\t")
				.append(this.size).append("\t").append(this.nExp).append("\t").append(this.seed).append("\t").append(this.mean)
				.append("\t");
		return sb.toString();
	}

	public static String getFields() {
		StringBuilder sb = new StringBuilder();
		sb.append("hms").append("\t").append("maxImprovisations").append("\t").append("minPar").append("\t")
				.append("maxPar").append("\t").append("hmcr").append("\t").append("function").append("\t")
				.append("size").append("\t").append("nExp").append("\t").append("seed").append("\t").append("mean")
				.append("\t");
		return sb.toString();
	}

}
