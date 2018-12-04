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

		boolean fixedK = false;
		boolean log = false;

		List<Task> ret = new ArrayList<>();

		if (params.getParam("log") != null) {
			log = (boolean) params.getParam("log");
		}

		for (String objectiveFunction : (List<String>) params.getParam("objectiveFunctions")) {
			ObjectiveFunction currFunction = ObjectiveFunctionFactory.getObjectiveFuncion(objectiveFunction);
			Task task = new Task(params.toInteger(params.getParam("hms")),params.toInteger(params.getParam("nIt")),
					(double) params.getParam("minPar"), (double) params.getParam("maxPar"),
					(double) params.getParam("hmcr"), currFunction, log, new Random(), params.toInteger(params.getParam("size"))); 
			ret.add(task);
		}

		return ret;

	}

}
