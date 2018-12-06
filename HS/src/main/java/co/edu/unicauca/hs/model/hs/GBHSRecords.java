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
package co.edu.unicauca.hs.model.hs;

import co.edu.unicauca.hs.exception.DistanceException;
import co.edu.unicauca.hs.model.Record;
import co.edu.unicauca.hs.model.RecordComparator;
import co.edu.unicauca.hs.model.objectivefunction.ObjectiveFunction;
import co.edu.unicauca.hs.service.Config;
import co.edu.unicauca.hs.utils.Report;
import java.io.File;
import java.util.Collections;
import java.util.Comparator;
import java.util.Date;
import java.util.List;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Arnold Jair Jimenez Vargas <ajjimenez@unicauca.edu.co>
 */
public class GBHSRecords implements GBHS {

	@Override
	public synchronized Record process(int hms, int maxImprovisations, double minPar, double maxPar, double hmcr,
			ObjectiveFunction function, boolean log, Random random, int size) {

		try {
			int repeated = 0;
			int curHms;
			int bad = 0;
			File resultFolder = Config.getInstance().getResultFolder();
			File resultado = new File(resultFolder, function.toString() + "_" + (new Date())+ ".txt");
			String logPath = resultado.getAbsolutePath();
			Report report = new Report(logPath);
			List<Record> harmonyMemory;
			double par;
			GBHSUtils utils = new GBHSUtils();

			Comparator<Record> recordComparator = new RecordComparator(function.minimizes());
			harmonyMemory = utils.generateHarmonyMemory(hms, function, random, recordComparator);

			curHms = harmonyMemory.size();

			if (log) {
				report.writeHarmonyMemory(harmonyMemory, "Initial Harmony Memory");
			}

			for (int cIt = 0; cIt < maxImprovisations; cIt++) {
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
				} else if (!utils.replaceSolution(harmonyMemory, newSolution, recordComparator)) {
					bad++;
				}

				Collections.sort(harmonyMemory, recordComparator);

				if (log) {
					report.writeHarmonyMemory(harmonyMemory, "Harmony Memory iteration " + cIt);
				}

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
