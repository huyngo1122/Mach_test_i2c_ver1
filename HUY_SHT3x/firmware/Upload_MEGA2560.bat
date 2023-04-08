REM https://stackoverflow.com/questions/41934215/batch-file-get-filename-from-directory-and-save-as-variable
@echo off
REM setlocal
set "boardName=MEGA2560"
set "yourDir=%~dp0"
set "yourExt=*%boardName%.hex"
rem set filename=''
pushd %yourDir%
for %%a in (%yourExt%) do (
	REM C:\Users\Administrator\Desktop\arduino_board/HEX_UNO.bat %%a
	set "filename=%%a"
	echo !filename!
	echo %%a
	echo %filename%
	
	Goto upload_uno
REM for %%a in (%yourExt%) do echo %%a
)

echo .
echo .
echo not detect file hex for %boardName%

set /p DUMMY=Hit ENTER to continue...

:upload_uno
REM for %%a in (%yourExt%) do (
REM REM Do stuff with %%a here
REM Set filename=%%a
REM echo !filename!
REM echo !filename:~0,6!
REM echo !filename:a=b!
REM )

popd
REM endlocal

echo %filename%

D:\arduino_board\avr_tool_upload/HEX_%boardName%.bat %filename%
set /p DUMMY=Hit ENTER to continue...