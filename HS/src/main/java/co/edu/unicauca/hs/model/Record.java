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
package co.edu.unicauca.hs.model;

import java.util.Random;

/**
 *
 * @author Arnold Jair Jimenez Vargas <ajjimenez@unicauca.edu.co>
 */
public class Record {

    private double[] data;
    private double fitness;

    public double getFitness() {
		return fitness;
	}

	public void setFitness(double fitness) {
		this.fitness = fitness;
	}

	public Record() {
    	
    }

	public double[] getData() {
		return data;
	}

	public void setData(double[] data) {
		this.data = data;
	}
	
	public static Record randomRecord(Random random, double min, double max, int n) {
		double[] data = new double[n];
		for(int i = 0; i < n; i++) {
			data[i] = min + random.nextDouble() * (max - min);
		}
		Record ret = new Record();
		ret.setData(data);
		return ret;
	}
    
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append("[");
		for(int i = 0; i < this.data.length; i++) {
			sb.append(this.data[i]);
			if(i != this.data.length - 1) {
				sb.append(",");
			}
		}
		sb.append("]");
		return sb.toString();
	}
}
