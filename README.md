# c0gnito-authentication-emulation
A repository containting two methods of emulating c0gnito's authentication

# How it works?
The first method is a dummy dll that exports the same primitives as the production module for c0gnito.cc; the issue with this method of emulating their authentication is
it can easily be avoided by integrity checking the c0gnito module when loading it which can be an issue for us. Another issue is some people ship their product with the module 
contained within their image preventing one from just swapping the modules. The solution to would have been pointer swapping the imports to the process but that can screwed over by
protection such as VMP. So by simply locating the export address to the authentication primitive we can simply place a jmp instruction to own function (detour hooking) and do what 
ever we want.

![](https://github.com/S3ctor/c0gnito-authentication-emulation/blob/main/assets/Capture.PNG)

# How to use it. 1      (better version) (x64 & x86)
Download release 2.0 (make sure to get the correct architecture) and inject it into the process that utilizes c0gnito authentication.

# How to use it. 2
Download release 1.0 and replace the c0gnito.dll located in the same directory as the target process. (only for x64)
