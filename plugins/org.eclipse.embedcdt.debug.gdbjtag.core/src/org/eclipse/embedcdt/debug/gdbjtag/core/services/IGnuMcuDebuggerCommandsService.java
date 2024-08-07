/*******************************************************************************
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License 2.0
 * which accompanies this distribution, and is available at
 * https://www.eclipse.org/legal/epl-2.0/
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *     Liviu Ionescu - initial version
 *******************************************************************************/

package org.eclipse.embedcdt.debug.gdbjtag.core.services;

import java.util.List;
import java.util.Map;

import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Status;

public interface IGnuMcuDebuggerCommandsService {

	public void setAttributes(Map<String, Object> attributes);

	// ------------------------------------------------------------------------

	/**
	 * This step is part of the GROUP_TOP_LEVEL. Cannot use the IGDBJtagDevice
	 * object, it is not available at this moment.
	 *
	 * @param attributes
	 * @param commandsList
	 * @return Status.OK_STATUS or an IStatus object if error.
	 */
	public IStatus addGdbInitCommandsCommands(List<String> commandsList);

	// ------------------------------------------------------------------------

	public IStatus addGnuMcuSelectRemoteCommands(List<String> commandsList);

	public IStatus addGnuMcuResetCommands(List<String> commandsList);

	public IStatus addGnuMcuStartCommands(List<String> commandsList);

	public IStatus addGnuMcuRestartCommands(List<String> commandsList);

	// ------------------------------------------------------------------------

	public IStatus addFirstResetCommands(List<String> commandsList);

	public IStatus addLoadSymbolsCommands(List<String> commandsList);

	public IStatus addLoadImageCommands(List<String> commandsList);

	/**
	 * Used by both FinalLaunchSequence & RestartProcessSequence.
	 *
	 * @param attributes
	 * @param doReset
	 * @param programPath
	 * @param commandsList
	 * @return
	 */
	public IStatus addStartRestartCommands(boolean doReset, List<String> commandsList);

	//ASHLING CUSTOMIZATION - https://gitlab.com/ashling/riscfree/riscfree-ui/-/issues/1745

	//Add functionality "Periodically check PC while halted" option  is selected
	public default IStatus addDisableAllBreakPointsIfTargetStatusCheckEnabled(List<String> commandsList) {
		return Status.OK_STATUS;
	}

	//Add functionality "Periodically check PC while halted" option  is selected
	public default IStatus addEnableAllBreakPointsIfTargetStatusCheckEnabled(List<String> commandsList) {
		return Status.OK_STATUS;
	}

	//ASHLING CUSTOMIZATION - https://gitlab.com/ashling/riscfree/riscfree-ui/-/issues/1745

	public IStatus addSetPcCommands(List<String> commandsList);

	public IStatus addStopAtCommands(List<String> commandsList);

	public IStatus addMstatusCSRResetCommands(List<String> commandsList);

	public IStatus addDCSRResetCommands(String registerValue, List<String> commandsList);

	// ------------------------------------------------------------------------
}
