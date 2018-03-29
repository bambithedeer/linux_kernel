#!/bin/bash

set -e

cd linux

make

make modules_install

cp arch/x86_64/boot/bzImage /boot/vmlinuz-linux-andrew

sed s/linux/linux-andrew/g </etc/mkinitcpio.d/linux.preset >/etc/mkinitcpio.d/linux-andrew.preset

mkinitcpio -p linux-andrew

grub-mkconfig -o /boot/grub/grub.cfg
