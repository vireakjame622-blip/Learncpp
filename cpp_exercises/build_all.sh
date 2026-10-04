#!/usr/bin/env bash
# Runs test_runner.py using python3 or python
DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
if command -v python3 &>/dev/null; then
    python3 "$DIR/test_runner.py" "$@"
else
    python "$DIR/test_runner.py" "$@"
fi
