# fs-autolock
A small set of systemd units for the Raspberry Pi that enables automatic switching the root and boot partitions between between read-write and read-only mode if maintenance tasks are in-progress. Can help with reducing wear and tear of inbuilt storage for embedded or fixed-function images.

## Notes
- This package assumes that systemd is used as the `init` subsystem and that no partitions are configured by other means to be writable by-default, which is the default behaviour of the kernel.
- Installation of these units may not be possible on a running system, and should be done through another system.
- Services in this repository are not meant to be started and stopped manually, thus having `RefuseManualStart`, `RefuseManualStop` and `StopWhenUnneeded` all set to `true` in their `[Unit]` sections. Addditional mounts can be managed/chained, but must also follow the same convention for predictable behaviour.
