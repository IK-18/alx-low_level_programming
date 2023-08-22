#!/bin/bash
wget -P /tmp https://github.com/IK-18/alx-low_level_programming/blob/master/0x18-dynamic_libraries/libinjection.so
export LD_PRELOAD=/tmp/libinjection.so
