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

package org.eclipse.embedcdt.debug.gdbjtag.ui.viewmodel;

import org.eclipse.cdt.dsf.debug.ui.viewmodel.SteppingController;
import org.eclipse.cdt.dsf.gdb.internal.ui.viewmodel.GdbViewModelAdapter;
import org.eclipse.cdt.dsf.service.DsfSession;
import org.eclipse.cdt.dsf.ui.viewmodel.IVMProvider;
import org.eclipse.debug.internal.ui.viewers.model.provisional.IPresentationContext;
import org.eclipse.embedcdt.debug.gdbjtag.ui.viewmodel.peripherals.PeripheralsVMProvider;
import org.eclipse.embedcdt.internal.debug.gdbjtag.ui.render.peripherals.PeripheralsView;

import com.ashling.riscfree.debug.cacheview.ui.dsf.CacheViewVMProvider;
import com.ashling.riscfree.debug.cacheview.ui.view.CacheView;
import com.ashling.riscfree.debug.cacheview.ui.view.TLBView;
import com.ashling.riscfree.globalvariable.view.dsf.ui.GlobalVariableVMProvider;
import com.ashling.riscfree.globalvariable.view.views.GlobalVariablesView;
import com.ashling.riscfree.trace.core.TraceViewVMProviderManager;

@SuppressWarnings("restriction")
public class GnuMcuViewModelAdapter extends GdbViewModelAdapter {

	// ------------------------------------------------------------------------

	protected GnuMcuViewModelAdapter(DsfSession session, SteppingController controller) {

		// Parent will register IColumnPresentationFactory as modelAdapter
		super(session, controller);
	}

	@Override
	protected IVMProvider createViewModelProvider(IPresentationContext context) {

		// For the Peripherals view, return the view model provider.
		if (PeripheralsView.PRESENTATION_CONTEXT_ID.equals(context.getId())) {
			return new PeripheralsVMProvider(this, context, getSession());
		}

		// <CUSTOMIZATION - ASHLING>
		if (GlobalVariablesView.GLOBAL_VARIABLE_VIEW.equals(context.getId())) {
			return new GlobalVariableVMProvider(this, context, getSession());
		}
		if (CacheView.ID_VIEW_CACHE.equals(context.getId()) || TLBView.ID_VIEW_TLB.equals(context.getId())) {
			return new CacheViewVMProvider(this, context, getSession());
		}
		if (context.getId().contains(TraceViewVMProviderManager.TRACE_VIEW_PREFIX)) {
			return TraceViewVMProviderManager.INSTANCE.getVMProvider(context.getId(), this, context, getSession());
		}
		// </CUSTOMIZATION>

		// For all others, refer them to the parent class.
		return super.createViewModelProvider(context);
	}

	// ------------------------------------------------------------------------
}
