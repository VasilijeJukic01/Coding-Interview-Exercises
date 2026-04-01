/*
You are implementing a non-blocking concurrent stack using Compare-And-Swap (CAS) to avoid the 
context-switching overhead of traditional locks.
*/

public class LockFreeStack<T> {
    static class Node<T> {
        T value;
        Node<T> next;
        Node(T val) { this.value = val; }
    }

    private AtomicReference<Node<T>> head = new AtomicReference<>(null);

    public T pop() {
        Node<T> oldHead;
        Node<T> newHead;
        do {
            oldHead = head.get();
            if (oldHead == null) return null; // Stack is empty
            newHead = oldHead.next;
        } while (!head.compareAndSet(oldHead, newHead)); 
        return oldHead.value;
    }
}

/*
This code has a catastrophic flaw that can corrupt the entire linked list.

1) Write the exact sequence of thread preemptions that causes the CAS to succeed when it should have failed.
2) What specific Java class should you use to fix this?
*/

/*
Vaske:

1) 
Let stack be A -> B -> C.
Let us have two threads T1 and T2.

- T1 starts pop(), oldHead = A, newHead = B, and T1 sleeps.
- T2 runs, pops A, pops B, and pushes A back. Stack is now A -> C.
- T1 comes back and sees head == A (same reference as before). CAS succeeds but stack is changed.

CAS only checks if the reference is the same, and cannot detect intermediate changes.

2) To fix this we can use AtomicStampedReference (add versioning).
*/

public class LockFreeStack<T> {
    static class Node<T> {
        T value;
        Node<T> next;
        Node(T val) { this.value = val; }
    }

    private AtomicStampedReference<Node<T>> head = new AtomicStampedReference<>(null, 0);

    public T pop() {
        Node<T> oldHead;
        Node<T> newHead;
        int[] stampHolder = new int[1];

        do {
            oldHead = head.get(stampHolder);
            if (oldHead == null) return null;
            newHead = oldHead.next;
        } while (!head.compareAndSet(oldHead, newHead, stampHolder[0], stampHolder[0] + 1));
        return oldHead.value;
    }
}
