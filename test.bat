..\bin\name_compiler_app.exe -i ..\examples\decorated_name0.txt
if %errorlevel% neq 0 goto failure
goto success
:failure
@echo failure!
goto end
:success
@echo success!
goto end
:end
