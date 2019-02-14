# android_cpp_multithread
android_cpp_multithread: android create and build a cpp multiple threads, and run on your cellphone

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




