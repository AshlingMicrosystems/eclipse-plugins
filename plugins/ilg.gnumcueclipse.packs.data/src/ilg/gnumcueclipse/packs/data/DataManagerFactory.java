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
 *     Liviu Ionescu - initial implementation.
 *******************************************************************************/

package ilg.gnumcueclipse.packs.data;

import ilg.gnumcueclipse.packs.core.data.IPacksDataManager;
import ilg.gnumcueclipse.packs.core.data.IPacksDataManagerFactory;

public class DataManagerFactory implements IPacksDataManagerFactory {

	public DataManagerFactory() {
		;
	}

	@Override
	public IPacksDataManager createDataManager() {

		// Return the static manager object
		return DataManager.getInstance();
	}

	@Override
	public void dispose() {
		;
	}

}