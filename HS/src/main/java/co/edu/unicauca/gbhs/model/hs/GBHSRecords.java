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
package co.edu.unicauca.gbhs.model.hs;

import java.io.File;
import java.util.Collections;
import java.util.Comparator;
import java.util.Date;
import java.util.List;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

import co.edu.unicauca.gbhs.model.Record;
import co.edu.unicauca.gbhs.model.RecordComparator;
import co.edu.unicauca.gbhs.model.objectivefunction.ObjectiveFunction;
import co.edu.unicauca.gbhs.service.Config;
import co.edu.unicauca.gbhs.utils.Report;

/**
 *
 * @author Arnold Jair Jimenez Vargas <ajjimenez@unicauca.edu.co>
 */
public class GBHSRecords implements GBHS {

	@Override
	public synchronized Record process(int hms, int maxImprovisations, double minPar, double maxPar, double hmcr,
			ObjectiveFunction function, boolean log, Random random, int size, long id) {

		try {
			int curHms;
			File resultFolder = Config.getInstance().getResultFolder();
			File resultado = new File(resultFolder, function.toString() + "_" + (new Date()) + "_" + id + ".txt");
			String logPath = resultado.getAbsolutePath();
			Report report = new Report(logPath);
			List<Record> harmonyMemory;
			double par;
			GBHSUtils utils = new GBHSUtils();

			Comparator<Record> recordComparator = new RecordComparator(function.minimizes());
			harmonyMemory = utils.generateHarmonyMemory(hms, size, function, random, recordComparator);

			curHms = harmonyMemory.size();

			if (log) {
				report.writeHarmonyMemory(harmonyMemory, "Initial Harmony Memory");
			}

			int cIt = 0;
			while(function.getEvaluationCount() < maxImprovisations) {
				par = minPar + ((maxPar - minPar) / maxImprovisations) * cIt;
				int n = size;
				double[] newData = new double[n];
				Record newSolution = new Record();

				for (int i = 0; i < n; i++) {
					double num = random.nextDouble();
					if (num <= hmcr) {
						int pos = random.nextInt(curHms);
						newData[i] = harmonyMemory.get(pos).getData()[i];

						if (random.nextDouble() < par) {
							newData[i] = harmonyMemory.get(pos).getData()[random.nextInt(n)];
						}
					} else {
						newData[i] = function.getRandomValue(random);
					}
				}

				newSolution.setData(newData);

				newSolution.setFitness(function.calculate(newSolution));

				if (curHms < hms) {
					harmonyMemory.add(newSolution);
					curHms++;
				} else {
					utils.replaceSolution(harmonyMemory, newSolution, recordComparator);
				}

				Collections.sort(harmonyMemory, recordComparator);

				if (log) {
					report.writeHarmonyMemory(harmonyMemory, "Harmony Memory iteration " + cIt);
				}
				System.out.println(cIt);
				cIt++;
			}

			report.close();
			return harmonyMemory.get(0);
		} catch (Exception ex) {
			Logger.getLogger(GBHSRecords.class.getName()).log(Level.SEVERE, null, ex);
			return null;
		}
	}

	@Override
	public GBHS newInstance() {
		return new GBHSRecords();
	}

	@Override
	public String toString() {
		return "Records";
	}

}
