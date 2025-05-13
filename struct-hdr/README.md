# struct-hdr
To run this repair, execute this command in `tests\struct-hdr`:\
`angelix src test.c oracle 1 2 3 4 5 6 --assert assert.json --defect guards --synthesis-level conditional arithmetic --synthesis-ptr-vars --syntehsis-func-params`

This experiment was an attempt to apply angelix to common packet length checks that are part of XDP programs. For example:
```c
struct ethhdr *eth = data;
uint64_t network_header_offset = sizeof(*eth);

if (data + network_header_offset > data_end)
{
  return RETURN_CODE;
}
```
We want to work with data within bounds of the header offset. If it overshoots the end of the data, `data_end`, then that means it could access data it's not supposed to. That is the purpose of this check.

In our program, we have an array of strings, `str_array`, with strings of various lengths. The struct `struct eth` has a size of 8 bytes since it contains two ints that are 4 bytes.

The user inputs an integer that corresponds to a string in the array. `data` is set to 0, and `data_end` to the length of the string. If the user chooses a string that is too small, the program will return -1 as an indicator that the data is "malformed" and could lead to bad accesses.

While typical XDP code has assigns the struct with `data` as a pointer, I decided against it for now. This may be the reason that `data` was not used in the repair, since it is initialized as an int to 0.

However, the results seem a step closer to being able to apply angelix to automate eBPF repairs such as bounds checking.
