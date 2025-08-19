// TOPIC: std::lock();

// It is used to lock mutiple mutex at the same time.

// IMPORTANT:
// syntex:--> std::lock(m1, m2, m3, m4);
// 1. All arguments are locked via a sequence of calls to lock(), try_lock(), or unlock() on each argument.
// 2. order of locking is not defined (it will try to lock provided mutex in any order and ensure that there is no dead lock).
// 3. It is a blocking cell.

// Examle 1 ---> No deadlock.
// Thread 1                        Thread 2
// std::lock(m1, m2)               std::lock(m1, m2);

// Examle 2 ---> No deadlock.
// Thread 1                        Thread 2
// std::lock(m1, m2)               std::lock(m2, m1);

// Examle 2 ---> No deadlock.
// Thread 1                        Thread 2
// std::lock(m1, m2, m3, m4)       std::lock(m3, m4);
//                                 std::lock(m1, m2)