@echo off

REM
SET "ARCHIVE_PATH=D:\DirectX12_Study\Library\Lib\release.zip"
SET "DEST_PATH=D:\DirectX12_Study\Library\Lib\FBX\release"

REM
powershell Expand-Archive -Path "%ARCHIVE_PATH%" -DestinationPath "%DEST_PATH%" -Force