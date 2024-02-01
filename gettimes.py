#!/usr/bin/env python
import time

def str2time(str):
    return time.mktime(time.strptime(str, "%d %b %Y"))

print ("#define TIMEBIRTH",str2time("23 Nov 1977"))

