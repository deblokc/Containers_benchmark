#!/bin/bash

echo "----FT----"

./test_ft > ft.log

echo "----STD----"

./test_std > std.log

echo "---DIFF---"

sh diff.sh

echo "------------"

exit 0
