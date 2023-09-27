package org.eclipse.embedcdt.debug.gdbjtag.core.memory;

import java.util.HashMap;
import java.util.Map;

import org.eclipse.debug.core.model.IMemoryBlockRetrieval;

/**
 * @author vinod.appu
 *
 */
public class PeripheralMemoryBlockRetrievalWrapper {

	Map<Object, IMemoryBlockRetrieval> memoryBlockRetrievals = new HashMap<>();

	public void putMemoryRetreival(String key, IMemoryBlockRetrieval value) {
		memoryBlockRetrievals.put(key, value);
	}

	public IMemoryBlockRetrieval getMemoryRetreival(String key) {
		return memoryBlockRetrievals.get(key);
	}
}