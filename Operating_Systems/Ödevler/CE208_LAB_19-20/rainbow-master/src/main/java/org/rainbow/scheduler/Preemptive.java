/*
 * Rainbow - A simulator of processes and resources in a multitasking computer.
 * Copyright (C) 2006. E-mail: piero.dallepezze@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 *
 * File: Preemptive.java
 * Package: scheduler
 * Author: Marin Pier Giorgio, Dalle Pezze Piero
 * Date: 03/02/2006
 * Version: 1.1
 * 
 * Modifies:
 *  - v.1.1 (31/01/2007): English translation. Java6 compatible. (Piero Dalle Pezze)
 *  - v.1.0 (03/02/2006): Codify and documentation.
 */
package org.rainbow.scheduler;

import org.rainbow.data.*;

/**
 * It represents a generic preemptive scheduling policy. In particular it
 * necessary defines a new method minor() to compare two processes.
 * 
 * @author Marin Pier Giorgio
 * @author Dalle Pezze Piero
 * @version 1.1
 */
public interface Preemptive extends SchedulingPolicy {

	/**
	 * It compares the process in execution with the process ready.
	 * 
	 * @param ready
	 *            A process inside the ready queue.
	 * @param inExecution
	 *            The process actually in execution.
	 * @return the process that satisfy the minor condition.
	 */
	public PCB minor(PCB ready, PCB inExecution);

}
