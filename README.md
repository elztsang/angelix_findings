# Angelix Findings
These are my experiments and findings using the [https://github.com/msv-lab/angelix](angelix) software.
You will find each of the experiments with their own README files detailing what they do and what I learned.

## Setup ##
I had several issues with trying to compile Angelix after building from source. So, using a virtual machine worked best for me as it has Angelix pre-installed (albeit with an outdated distribution).

1. Download the .vdi file from https://s3-ap-southeast-1.amazonaws.com/angelix/angelix-icse16-v2.vdi
2. Run the following command in your linux-based terminal: `qemu-img convert -f vdi -O qcow2 angelix-icse16-v2.vdi angelix.qcow2`
3. Install virt-manager if you haven't already: `sudo apt-get install virt-manager`
4. Run the Virtual Machine Manager application. You can import the `.qcow2` file into the KVM by following the steps [https://markontech.com/posts/convert-virtualbox-vms-to-qemu-kvm/#import-the-qcow2-into-the-kvm-vm](here).

The contents of this repository are only the test cases I made. You will need your own Angelix software to run these test cases.

## TBE ##
