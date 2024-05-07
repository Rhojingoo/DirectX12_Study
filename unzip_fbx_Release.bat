@echo off

REM
SET "BASE_PATH=%~dp0"
SET "ARCHIVE_PATH=%BASE_PATH%Library\Lib\release.zip"
SET "DEST_PATH=%BASE_PATH%Library\Lib\FBX\release"

REM
powershell Expand-Archive -Path "%ARCHIVE_PATH%" -DestinationPath "%DEST_PATH%" -Force