/*
 * Copyright (C) 2016 Arnold Jair Jimenez Vargas <ajjimenez@unicauca.edu.co>.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301  USA
 */
package co.edu.unicauca.gbhs.model;

import co.edu.unicauca.gbhs.model.hs.GBHS;
import co.edu.unicauca.gbhs.model.objectivefunction.ObjectiveFunction;
import co.edu.unicauca.gbhs.model.objectivefunction.ObjectiveFunctionFactory;
import co.edu.unicauca.gbhs.model.task.Task;
import java.util.Map;
import java.util.Random;
import java.util.concurrent.Callable;

/**
 *
 * @author Arnold Jair Jimenez Vargas <ajjimenez@unicauca.edu.co>
 */
public class GBHSExperimenter implements Callable<Result>, Experimenter {

    private int hms;
    private int maxImprovisations;
    private int nExp;
    private double minPar;
    private double maxPar;
    private double hmcr;
    private ObjectiveFunction function;
    private Random random;
    private GBHS algorithm;
    private Record[] results;
    private boolean log;
    private int size;
    private long seed;
    private long parentId;

    public GBHSExperimenter(Task task) throws Exception {
        this.hms = task.getHms();
        this.maxImprovisations = task.getMaxImprovisations();
        this.nExp = task.getnExp();
        this.minPar = task.getMinPar();
        this.maxPar = task.getMaxPar();
        this.hmcr = task.getHmcr();
        this.function = task.getFunction();
        if (task.getSeed() != 0) {
            this.random = new Random(task.getSeed());
        } else {
            this.random = new Random();
        }
        this.seed = task.getSeed();
        this.algorithm = task.getAlgorithm();
        this.results = new Record[nExp];
        this.log = task.isLog();
        this.size = task.getSize();
        this.parentId = task.getId();

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



	public int getnExp() {
		return nExp;
	}



	public void setnExp(int nExp) {
		this.nExp = nExp;
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



	public ObjectiveFunction getFunction() {
		return function;
	}



	public void setFunction(ObjectiveFunction function) {
		this.function = function;
	}



	public Random getRandom() {
		return random;
	}



	public void setRandom(Random random) {
		this.random = random;
	}



	public GBHS getAlgorithm() {
		return algorithm;
	}



	public void setAlgorithm(GBHS algorithm) {
		this.algorithm = algorithm;
	}



	public Record[] getResults() {
		return results;
	}



	public void setResults(Record[] results) {
		this.results = results;
	}



	public boolean isLog() {
		return log;
	}



	public void setLog(boolean log) {
		this.log = log;
	}

	public int getSize() {
		return size;
	}

	public void setSize(int size) {
		this.size = size;
	}

	public long getSeed() {
		return seed;
	}

	public void setSeed(long seed) {
		this.seed = seed;
	}

	public long getParentId() {
		return parentId;
	}

	public void setParentId(long parentId) {
		this.parentId = parentId;
	}

	@Override
    public synchronized Result experiment() {
        Result ret = new Result();
        double mean = 0;
        for (int i = 0; i < nExp; i++) {
            GBHS currAlgorithm = algorithm.newInstance();
            Record cSolucion = currAlgorithm.process(hms, maxImprovisations, minPar, maxPar, hmcr, function, log, random, size, this.parentId + i);
            results[i] = cSolucion;
            mean += cSolucion.getFitness();
        }
        
        mean /= nExp;
    	
        ret.setHms(this.hms);
        ret.setMaxImprovisations(this.maxImprovisations);
        ret.setMinPar(this.minPar);
        ret.setMaxPar(this.maxPar);
        ret.setHmcr(this.hmcr);
        ret.setFunction(this.function.toString());
        ret.setSize(this.size);
        ret.setnExp(this.nExp);
        ret.setSeed(this.seed);
        ret.setMean(mean);
        return ret;
    }

    
    @Override
    public Result call() throws Exception {
        return this.experiment();
    }

}
