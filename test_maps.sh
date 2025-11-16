#!/bin/bash

make || exit 1

for f in maps/*.cub; do
	echo "==== Test: $f ===="
	./cub3d "$f"
	echo "status = $?"
	echo
done

