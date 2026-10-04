@echo off
setlocal
cd /d "%~dp0"
python test_runner.py %*
endlocal
