#!/bin/bash

make || exit 1

for f in maps/*.cub; do
	echo "==== Test: $f ===="
	./cub3D "$f"
	echo "status = $?"
	echo
done

