/*
 * Copyright (C) 2016 Pivotal Software, Inc..
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
package co.edu.unicauca.hs.model.task;

import java.util.Map;
import java.util.Random;

import co.edu.unicauca.hs.model.hs.GBHS;
import co.edu.unicauca.hs.model.objectivefunction.ObjectiveFunction;

/**
 *
 * @author Arnold Jair Jimenez Vargas <ajjimenez@unicauca.edu.co>
 */
public class Task {

	private int hms;
	private int maxImprovisations;
	private double minPar;
	private double maxPar;
	private double hmcr;
	private ObjectiveFunction function;
	private boolean log;
	private int size;
	private int nExp;
	private long seed;
	private GBHS algorithm;
	private long id;

	public Task(int hms, int maxImprovisations, double minPar, double maxPar, double hmcr, ObjectiveFunction function,
			boolean log, int size, int nExp, long seed, GBHS algorithm, long id) {
		this.hms = hms;
		this.maxImprovisations = maxImprovisations;
		this.minPar = minPar;
		this.maxPar = maxPar;
		this.hmcr = hmcr;
		this.function = function;
		this.log = log;
		this.size = size;
		this.nExp = nExp;
		this.seed = seed;
		this.algorithm = algorithm;
		this.id = id;
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

	public ObjectiveFunction getFunction() {
		return function;
	}

	public void setFunction(ObjectiveFunction function) {
		this.function = function;
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

	public GBHS getAlgorithm() {
		return algorithm;
	}

	public void setAlgorithm(GBHS algorithm) {
		this.algorithm = algorithm;
	}

	public long getId() {
		return id;
	}

	public void setId(long id) {
		this.id = id;
	}
	
}
