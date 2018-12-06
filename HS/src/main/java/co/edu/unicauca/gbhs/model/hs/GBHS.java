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

import co.edu.unicauca.gbhs.model.Record;
import co.edu.unicauca.gbhs.model.objectivefunction.ObjectiveFunction;
import java.util.Random;

/**
 *
 * @author Arnold Jair Jimenez Vargas <ajjimenez@unicauca.edu.co>
 */
public interface GBHS {

	/**
	 * 
	 * @param hms
	 * @param maxImprovisations
	 * @param minPar
	 * @param maxPar
	 * @param hmcr
	 * @param function
	 * @param log
	 * @param random
	 * @param size
	 * @return
	 */
    public Record process(int hms, int maxImprovisations, double minPar, double maxPar, double hmcr,
    		ObjectiveFunction function, boolean log, Random random, int size, long id);

    public GBHS newInstance();
}
