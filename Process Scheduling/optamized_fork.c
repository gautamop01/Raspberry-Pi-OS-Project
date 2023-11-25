#include "mm.h"
#include "sched.h"
#include "entry.h"

int copy_process(unsigned long fn, unsigned long arg) {
    preempt_disable();

    // Allocate memory for the new process
    struct task_struct *p = (struct task_struct *)get_free_page();
    if (!p) {
        preempt_enable();
        return 1;  // Memory allocation failure
    }

    // Initialize task_struct fields
    p->priority = current->priority;
    p->state = TASK_RUNNING;
    p->counter = p->priority;
    p->preempt_count = 1;  // Disable preemption until schedule_tail

    // Set up the CPU context
    struct cpu_context *cpu_ctxt = &p->cpu_context;
    cpu_ctxt->x19 = fn;
    cpu_ctxt->x20 = arg;
    cpu_ctxt->pc = (unsigned long)ret_from_fork;
    cpu_ctxt->sp = (unsigned long)p + THREAD_SIZE;

    // Assign a process ID and update the task array
    task[nr_tasks++] = p;

    preempt_enable();
    return 0;  // Success
}
