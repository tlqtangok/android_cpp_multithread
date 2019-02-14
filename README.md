# android_cpp_multithread
android_cpp_multithread: android create and build a cpp multiple threads, and run on your cellphone

## to setup the cross-compile environment 

one need install android ndk tools from : https://developer.android.com/ndk/downloads/?hl=zh-cn
then set up the cc toolchain, following following steps:

. download android-ndk-r16b-windows-x86_64.zip

. unzip and create a standalone version

. pushd E:\jd\t\android-ndk-r16b-windows-x86_64\android-ndk-r16b\build\tools

. python make_standalone_toolchain.py  --arch arm64 --api 24 --stl gnustl --install-dir %cd%\aarch64_bin

. in aarch64_bin , create env.env

```
### :: cat env.env :: ###
	set ROOT=%CD%
	set PATH=%ROOT%\bin;%PATH%
###
```


## to run 

on windows

. `cd main_cpp_test`

. `call cross_bld_and_adb_push.bat` to build and push binary file to phone

. adb push run_on_phone.sh to /data/t

. on phone, run the `*.sh` file





