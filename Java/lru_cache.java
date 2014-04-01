public class LRUCache {
    public class Container {
        int key;
        int value;
		Container next;
		Container prev;
    }
    int totalAvailable;
	Container listHead;
	Container listTail;
    HashMap<Integer, Container> key2Position;
    int capacityLRU;
    
    public LRUCache(int capacity) {
        key2Position = new HashMap<Integer, Container>(2 * capacity);
        totalAvailable = capacity;
        capacityLRU = capacity;
    }
	
	public void moveToHead(Container container) {
	    if (container.prev != null) {
			container.prev.next = container.next;
		} else {
		    // This node is listHead
		    return;
		}
		if (container.next != null) {
			container.next.prev = container.prev;
		} else {
		    listTail = container.prev;
		}
		container.prev = null;
		container.next = listHead;
		listHead.prev = container;
		listHead = container;
	}
	
    public int get(int key) {
        if (key2Position.containsKey(key)) {
            Container container = key2Position.get(key);
            moveToHead(container);
            return container.value;
        } else {
            return -1;
        }
    }
    
    public void set(int key, int value) {
        if (key2Position.containsKey(key)) {
            Container container = key2Position.get(key);
			container.value = value;
            moveToHead(container);
        } else {
            Container container = new Container();
			container.key = key;
			container.value = value;
            if (totalAvailable == 0) {
                key2Position.remove(listTail.key);
			    if (listTail.prev != null) {
			        listTail.prev.next = null;
			        listTail = listTail.prev;
			    } else {
			        listTail = listHead = null;
			    }
			} else {
			    totalAvailable--;
			}
			key2Position.put(key, container);
			container.prev = null;
			container.next = listHead;
			if (listHead != null) {
			    listHead.prev = container;
			}
			listHead = container;
			if (listTail == null) {
			    listTail = listHead;
			}
        }
    }
}
