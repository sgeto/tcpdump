@echo off
:: read VERSION and store its content in %vstring%
for /f "tokens=* usebackq" %%F in (`type $(SolutionDir)..\VERSION`) do (
set vstring=%%F
)

:: Construct the date string and store it in %_curdate%
:: Note: This presumes that your date string is formatted 
:: as 10/06/2017 or Fri 10/06/2017
:: for /f "tokens=* delims=" %%x in (`echo _%date:~-4,4%_%date:~-10,2%_%date:~-7,2%`) do (
:: set curdate=%%x
)

:: Uncomment the following lines (and comment the above) 
:: if you are in a country other than the United States.
for /f "delims=" %%A in ('powershell get-date -format "{_yyyy_MM_dd}"') do (
set curdate=%%A
)

echo.
echo Building TCPdump %vstring%%curdate%
echo.

echo const char version[] = "%vstring%%curdate%"; > $(SolutionDir)version.c