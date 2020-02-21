#!/bin/bash
set -ex
set -euo pipefail

spike --isa=RV32IMAC -m0x20000000:0x2000,0x40000000:0x1000,0x80000000:0x1000 --pc=0x80000100 -d $1
