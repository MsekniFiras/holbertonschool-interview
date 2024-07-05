#!/usr/bin/python3
""" Log parsing """
import sys

status_codes = ["200", "301", "400", "401", "403", "404", "405", "500"]
status_counts = {code: 0 for code in status_codes}
total_size = 0
line_count = 0

try:
    for line in sys.stdin:
        parts = line.split()
        if len(parts) > 2 and parts[-2] in status_codes:
            status_counts[parts[-2]] += 1
            total_size += int(parts[-1])
        line_count += 1
        if line_count % 10 == 0:
            print("File size: {}".format(total_size))
            for code in sorted(status_counts.keys()):
                if status_counts[code]:
                    print("{}: {}".format(code, status_counts[code]))
except KeyboardInterrupt:
    pass
finally:
    print("File size: {}".format(total_size))
    for code in sorted(status_counts.keys()):
        if status_counts[code]:
            print("{}: {}".format(code, status_counts[code]))