
// This may not work for 4.17 on x64, you need replace kprobe__sys_clone with kprobe____x64_sys_clone
int kprobe__sys_clone(void *ctx) 
{ 
    bpf_trace_printk("Hello, World!\n"); 
    return 0; 
}