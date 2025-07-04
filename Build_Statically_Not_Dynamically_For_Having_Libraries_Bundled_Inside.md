\- My Question to Deepseek: Do you want to say if I don’t have that libraries or whoever I send the binary him, binary will never open?

\- Deepseek's answer:
Yes! If you compile a program **dynamically** (the default in GCC), the binary depends on shared libraries (`.so` files) at runtime. If those libraries are missing on your system (or on the system of whoever runs the binary), the program **will fail to launch** with an error like:

```
error while loading shared libraries: libxxx.so: cannot open shared object file
```

### **What This Means for You**
1. **On Your Machine**  
   - If you delete or move the required `.so` files, your own binary won’t run.  
   - Fix: Install the libraries (`sudo apt install libharu-dev`, etc.) or set `LD_LIBRARY_PATH`.

2. **On Someone Else’s Machine**  
   - If they don’t have the exact libraries installed, your binary **will crash**.  
   - Example: If you link `libhpdf.so.2.4`, their system must have that exact version.

---

### **Solutions to Make the Binary Portable**
#### **Option 1: Static Linking (Best for Portability)**
Compile with **static libraries** (`.a` files) so everything is bundled into the binary:
```sh
gcc -o pdf-gen pdf-gen.c -L/usr/local/lib -l:libhpdf.a -l:libssl.a -l:libcurl.a -static
```
✅ **Pros**:  
   - No external dependencies needed.  
   - Binary runs on any compatible Linux system.  

❌ **Cons**:  
   - Larger binary size.  
   - Not all libraries support static linking (e.g., some `glibc` features).  

#### **Option 2: Bundle Shared Libraries**
Ship the `.so` files alongside your binary and set `LD_LIBRARY_PATH`:
```sh
mkdir dist
cp pdf-gen.exe dist/
cp /usr/local/lib/libhpdf.so.2.4 dist/
```
Then run with:
```sh
LD_LIBRARY_PATH=./dist ./dist/pdf-gen.exe
```

#### **Option 3: Use Docker (For Advanced Users)**
Create a Docker image with all dependencies preinstalled.  

---

### **Key Takeaways**
- **Dynamic linking** → Binary is small but **fragile** (needs exact libraries).  
- **Static linking** → Binary is self-contained but **larger**.  
- **WSL/Windows Note**: Binaries compiled in WSL are **Linux executables** and won’t run natively on Windows (unless using WSL).  

### **Recommendation**
- For personal use → Install libraries on the target machine (`sudo apt install ...`).  
- For distributing → **Static linking** or **bundle `.so` files**.  

Want to check dependencies? Run:
```sh
ldd pdf-gen.exe
```
This lists all shared libraries the binary requires. If any are "not found", the binary won’t run without them.

---

> Chat URL: https://chat.deepseek.com/a/chat/s/6d7db148-ce1e-48e3-8352-c8679b88a2cd
