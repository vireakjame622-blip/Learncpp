# PowerShell test runner wrapper
param(
    [string]$Target = ""
)

$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
if ($Target -ne "") {
    python "$scriptDir\test_runner.py" $Target
} else {
    python "$scriptDir\test_runner.py"
}
