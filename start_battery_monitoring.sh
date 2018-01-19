#!/bin/bash
/bin/cat /dev/ttyACM0 | tee -a /var/log/lifepo4_bms_`date +%Y-%m-%d`.log