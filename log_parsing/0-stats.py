#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics
"""
import sys

total_size = 0
counter = 0

dict_codes_counter = {'200': 0, '301': 0, '400': 0, '401': 0,
                      '403': 0, '404': 0, '405': 0, '500': 0}

def print_stats():
    print("File size: {}".format(total_size))
    for k, v in sorted(dict_codes_counter.items()):
        if v != 0:
            print("{}: {}".format(k, v))

try:
    for line in sys.stdin:
        parts = line.split()
        if len(parts) > 2 and parts[-2] in dict_codes_counter:
            dict_codes_counter[parts[-2]] += 1
            total_size += int(parts[-1])
    counter += 1

    if counter == 10:
        print_stats()
        counter = 0

except KeyboardInterrupt:
    print_stats()
    raise

finally:
    print_stats()
