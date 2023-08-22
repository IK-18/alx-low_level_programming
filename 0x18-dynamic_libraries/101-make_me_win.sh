#!/bin/bash
wget -P /tmp https://github.com/IK-18/alx-low_level_programming/blob/master/0x18-dynamic_libraries/injection.so
export LD_PRELOAD=/tmp/injectin.so
