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

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import co.edu.unicauca.hs.model.JsonParams;
import co.edu.unicauca.hs.model.hs.GBHS;
import co.edu.unicauca.hs.model.hs.GBHSRecords;
import co.edu.unicauca.hs.model.objectivefunction.ObjectiveFunction;
import co.edu.unicauca.hs.model.objectivefunction.ObjectiveFunctionFactory;

/**
 *
 * @author Arnold Jair Jimenez Vargas <ajjimenez@unicauca.edu.co>
 */
public class TaskBuilder {

	public static List<Task> buildTasks(JsonParams params) throws Exception {
		if (!params.verifyExperiment()) {
			return null;
		}

		boolean log = false;

		List<Task> ret = new ArrayList<>();

		if (params.getParam("log") != null) {
			log = (boolean) params.getParam("log");
		}
		
		long id = 1;

		for (String objectiveFunction : (List<String>) params.getParam("objectiveFunctions")) {
			ObjectiveFunction currFunction = ObjectiveFunctionFactory.getObjectiveFuncion(objectiveFunction);
			int hms = params.toInteger(params.getParam("hms"));
			int maxImprovisations = params.toInteger(params.getParam("maxImprovisations"));
			double minPar = (double) params.getParam("minPar"); 
			double maxPar = (double) params.getParam("maxPar");
			double hmcr = (double) params.getParam("hmcr"); 
			int size = params.toInteger(params.getParam("size"));
			int nExp = params.toInteger(params.getParam("nExp"));
			long seed = Math.round((double)params.getParam("seed"));
			Task task = new Task(hms, maxImprovisations, minPar, maxPar, hmcr, currFunction, log, size, nExp, seed, new GBHSRecords(), id);
			id++;
			ret.add(task);
		}

		return ret;

	}

}
