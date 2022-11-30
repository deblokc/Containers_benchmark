#!/bin/bash

awk 'FNR==NR { a[FNR""] = $0; next } { print a[FNR""], $0 }' std.log ft.log | awk -e '/^[0-9]*\.[0-9]*s\s.*[0-9]*\.[0-9]*s.*$/ {print $1 " " $5 " " $2 " " $3 " " $4}' | awk -e '{printf("% 7.2f%% %-6s %-9s %-10s\n", ((($2+0.001)/($1+0.001))*100), ($3), ($4), ($5))}'
