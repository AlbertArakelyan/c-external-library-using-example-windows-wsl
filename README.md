# PDF Generating Library Integration Example `libharu`
This app was created for testing external library integration into a C program configured and set up on Windows via `WSL`.

## Compiling and Running
For compiling you need `gcc` installed on your machine inside of `WSL`.
```bash
wsl # For entering WSL terminal

gcc main.c -o pdf-gen.exe -lhpdf
```

## Additional Information
### Header files we use in the project
Those header files e.g. `stdio.f` and `hpdf.h` are imported from dirctories where they are located (on Linux) and those directories are
- `/usr/local/include` - for packacges, libraries (and headers coming with them) installed by us (e.g. `hpdf.h`)
- `/usr/include` - for built in packages (e.g. C native packages) that installed with C (while installed gcc and other tools) for example `stdio.h` library

### Libraries we include during building
The libraries anyway need to be included even during build time e.g. `-lhpdf`. They are also taken from certain directories (on Linux), and those directories are
- `/usr/lib` - for native libraries that come with C (while installing gcc)
- `/usr/local/lib` - for packages and libraries we installed **hpdf (libharu)** which we link like `-lhpdf`, and here is how it works when we type `-lhpdf`.

> ✅ **-lhpdf**  
> `-l<name>` (lowercase L) means:  
>  
> "Link against a library named `lib<name>.a` (`lib<name>.so`) or `lib<name>.dylib`"  
>  
> So `-lhpdf` will link against:  
>  
> `libhpdf.a`  
>  
> or  
>  
> `libhpdf.dylib`  
>  
> (depending on what’s available and how your system is configured)  
>  
> 📌 Without this, you'd get "undefined symbol" errors for every function you used from `libharu`.
