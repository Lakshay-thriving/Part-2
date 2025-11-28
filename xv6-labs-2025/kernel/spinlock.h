// Mutual exclusion lock.
struct spinlock {
  uint locked;       // Is the lock held?

  // For debugging:
  char *name;        // Name of lock.
  struct cpu *cpu;   // The cpu holding the lock.
#ifdef LAB_LOCK
  int nts;
  int n;
#endif
};

#ifdef LAB_LOCK
// Reader-writer lock.
struct rwspinlock {
  int waiting_writers;// Count of writers waiting (for priority)
  int readers;        // Count of current readers
  int writer;         // Boolean: is a writer holding the lock?
  struct spinlock lk; // Internal lock to protect the struct fields
  char *name;         // Name of the lock (for debugging)
};
#endif
