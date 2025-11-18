#!/bin/bash

make re || exit 1

for f in maps/*.cub; do
    echo "==== Valgrind: $f ===="
    valgrind --leak-check=full \
             --show-leak-kinds=all \
             --track-origins=yes \
             --error-exitcode=1 \
             ./cub3d "$f"
    echo "status = $?"
    echo
done

