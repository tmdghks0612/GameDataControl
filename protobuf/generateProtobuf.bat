set SRC_DIR=source
set DST_DIR=dest

@echo source : %SRC_DIR%, destination : %DST_DIR%

for /r %%i in (%SRC_DIR%\*.proto) do (
	protoc -I=%~dp0\%SRC_DIR% --cpp_out=%~dp0\%DST_DIR% %%i
)

@pause
