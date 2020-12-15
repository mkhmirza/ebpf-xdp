from bcc import BPF

b = BPF(src_file="hello.c")
try:
    b.trace_print()
except KeyboardInterrupt:
    pass
