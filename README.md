# Angelix Findings
These are my experiments and findings using the [angelix](https://github.com/msv-lab/angelix) software as of spring 2025.\
You will find each of the experiments with their own README files detailing what they do and what I learned.

## Setup ##
I had several issues with trying to compile Angelix after building from source. So, using a virtual machine worked best for me as it has Angelix pre-installed (albeit with an outdated distribution).

1. Download the .vdi file from https://s3-ap-southeast-1.amazonaws.com/angelix/angelix-icse16-v2.vdi
2. Install QEMU if you haven't already: `sudo apt install qemu-system`
3. Run the following command in your linux-based terminal in the location where your `.vdi` file is: `qemu-img convert -f vdi -O qcow2 angelix-icse16-v2.vdi angelix.qcow2`
4. Install virt-manager if you haven't already: `sudo apt-get install virt-manager`
5. Run the Virtual Machine Manager application. You can import the `.qcow2` file into the KVM by following the steps [here](https://markontech.com/posts/convert-virtualbox-vms-to-qemu-kvm/#import-the-qcow2-into-the-kvm-vm).
6. Log into user `angelix` with password `angelix`.

## Transferring files
You can transfer the files from this repository to your VM with scp.

The angelix VM does not come with ssh pre-installed. In the angelix VM, run the command `sudo apt install openssh-server`.\
Enter password "angelix" when prompted.

If you want to transfer all of the tests into the VM, from the root folder of this repository on your HOST machine, run `scp -r . angelix@192.168.122.8:/home/angelix/angelix/tests/`.\
If you just want a specific test, from the root folder of this repository on your HOST machine, run `scp -r angelix@192.168.122.8:/home/angelix/angelix/tests/[name_of_test] /[name_of_test]`.

I'm not sure if the angelix IP matches on every computer. You can find the angelix IP by going into the VM and entering `ifconfig` to the command line.\
Look for the `indet addr:` field under `eth0`. Replace the angelix IP in the previous scp commands with the different one if needed.

## Overview ##
The contents of this repository are only the test cases I made. You will need your own Angelix software to run these test cases.\
Make sure to build the experiment `test.c` executable with `make all` in `/src` before changing out of the directory, and then running the command specified in the README.md for the experiment.\
The `oracle` files are the test cases, and the `assert.json` files tell angelix which of the test cases are failing for the initial program.

The progression of experiments is memory-oob, memory-param, then struct-hdr. Each builds off of the previous experiment, so it would be the most helpful to follow in that order.

## Purpose ##
These experiments were to learn how angelix repair works. The ultimate goal is to see if we can eventually apply angelix's repair methodology to eBPF code. The hypothetical, high-level workflow is shown below.\
![alt text](https://github.com/elztsang/angelix_findings/blob/main/overview.png)

The motivation for looking into angelix is to apply automatic program repair to eBPF code rejected by the eBPF verifier. As eBPF bytecode is hard to debug, we want to try to repair eBPF C code instead.

Angelix depends on user-inputted test cases in order to infer correct behavior and generate intended repairs. As eBPF code is dealing with non-static data/packet streams, the goal is to be able to generate test cases after processing information from the resulting error log and generating test cases from there.
