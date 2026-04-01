/*
You are building a metrics system to track the number of successful and failed requests 
on a high-throughput multi-core server.

You assign one thread to update successes and another to update failures.
*/

public class Metrics {
    // Thread 1 constantly updates this
    public volatile long successCount = 0; 
    
    // Thread 2 constantly updates this
    public volatile long failureCount = 0; 
}

/*
Even though Thread 1 and Thread 2 never touch each other's variables, this code causes a massive 
CPU performance degradation on multi-core machines.

1) Why does this happen at the hardware/CPU cache level?
2) How do you modify the Metrics class to fix it?
*/

/*
Vaske:

1) The issue here is false sharing. Even though two threads update different variables, those variables 
are likely located in the same cache line. Each write invalidates the cache line in other cores, causing 
heavy cache invalidation.

2) The fix is to ensure the variables are in separate cache lines using separate objects.
*/

class Counter {
    public volatile long value = 0;
}

public class Metrics {
    public Counter success = new Counter();
    public Counter failure = new Counter();
}
