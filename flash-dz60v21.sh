#!/bin/bash -e

qmk compile -kb dztech/dz60rgb_ansi/v2_1 -km shearn89
echo "reconnect in bootloader mode, will continue in 10 seconds..."
sleep 10
echo "continuing"
rm /Volumes/KBDFANS\ \ /FLASH.BIN
cp dztech_dz60rgb_ansi_v2_1_shearn89.bin /Volumes/KBDFANS\ \ /FLASH.bin
echo "complete"
