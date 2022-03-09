#!/bin/bash -e

qmk compile -kb dztech/dz60rgb_ansi/v2_1 -km shearn89
cp -v dztech_dz60rgb_ansi_v2_1_shearn89.bin /mnt/c/repos/annepro-2-firmware/FLASH.bin
echo "done"
