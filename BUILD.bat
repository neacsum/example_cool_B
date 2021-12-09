@echo off
rem
rem  Master build script. Execute this script to create all output libraries
rem  Environment variable DEV_ROOT points to the root of development tree.
rem

call setup.bat
msbuild cool_B.sln
