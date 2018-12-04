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
import co.edu.unicauca.hs.model.objectivefunction.ObjectiveFunction;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Arnold Jair Jimenez Vargas <ajjimenez@unicauca.edu.co>
 */
public class GBHSUtils {

    public List<Record> generateHarmonyMemory(int hms, ObjectiveFunction function, Random random, Comparator<Record> comparator) throws DistanceException, Exception {
        List<Record> harmonyMemory = new ArrayList<>();

        for (int i = 0; i < hms; i++) {
        	
            Record tmp = Record.randomRecord(random, function.getMinValue(), function.getmaxValue(), hms);
            double fitness = function.calculate(tmp);

            if (Double.isNaN(fitness)) {
                i--;
                continue;
            }
            if (Double.isInfinite(fitness)) {
                i--;
                continue;
            }
            tmp.setFitness(fitness);
        }
        Collections.sort(harmonyMemory, comparator);
        return harmonyMemory;
    }
    
    public boolean repeatedSolution(Record newSolution,
            Comparator recordComparator, List<Record> harmonyMemory) {

        int hms = harmonyMemory.size();
        for (int i = 0; i < hms; i++) {
        	//TODO: add precision
            if (recordComparator.compare(harmonyMemory.get(i), newSolution) == 0) {
                if (harmonyMemory.get(i).getData().equals(newSolution.getData())) {
                    return true;
                }
            }
        }
        return false;
    }

    public boolean replaceSolution(List<Record> ma, Record ns, Comparator c) {
        int hms = ma.size();
        if (c.compare(ns, ma.get(hms - 1)) == -1) {
            ma.set(hms - 1, ns);
            return true;
        }
        return false;
    }

    public boolean uniformMemory(List<Record> harmonyMemory) {
        int hms = harmonyMemory.size();
        double mean = 0;
        double deviation = 0;
        for (Record Record : harmonyMemory) {
            mean += Record.getFitness();
        }
        mean /= hms;
        for (Record Record : harmonyMemory) {
            deviation += Math.pow(Record.getFitness() - mean, 2);
        }
        deviation /= (hms - 1);
        deviation = Math.sqrt(deviation);
        return deviation <= 0.05 * mean;
    }

    public List<Record> regenerateMemory(List<Record> records, int maxIt, ObjectiveFunction function, Comparator<Record> recordComparator,
            Random random) throws DistanceException, Exception {
        int hms = records.size();
        List<Record> ret = generateHarmonyMemory(hms - 2, function, random, recordComparator);

        ret.add(records.get(0));
        ret.add(records.get(1));

        Collections.sort(ret, recordComparator);
        return ret;
    }

}
