# PDF Generating Library Integration Example `libharu`
This app was created for testing external library integration into a C program configured and set up on Windows via `WSL`.

## Compiling and running
For compiling you need `gcc` installed on your machine inside of `WSL`.
```bash
wsl # For entering WSL terminal

gcc main.c -o pdf-gen.exe -lhpdf
```