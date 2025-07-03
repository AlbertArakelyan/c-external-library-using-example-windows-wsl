There is libhpdf linking problem even after linking during build(compile time), and here is how to fix it permanently on linuz (or WSL) environment.

### Add `/usr/local/lib` to the Linker Path (Recommended)**
#### **Step 1: Update the linker configuration**
Run:
```sh
echo "/usr/local/lib" | sudo tee /etc/ld.so.conf.d/usrlocal.conf
```
This creates a config file telling the linker to search `/usr/local/lib`.

#### **Step 2: Update the linker cache**
Run:
```sh
sudo ldconfig
```
This refreshes the system's library cache.

#### **Step 3: Verify the library is detected**
Check if `libhpdf.so.2.4` is now recognized:
```sh
ldconfig -p | grep libhpdf
```
If it appears, your program should now run:
```sh
./pdf-gen.exe
```

---

### **Summary**
✅ **Permanent Fix** (Best for WSL):
```sh
echo "/usr/local/lib" | sudo tee /etc/ld.so.conf.d/usrlocal.conf
sudo ldconfig
./pdf-gen.exe
```

---

> Chat URL: https://chat.deepseek.com/a/chat/s/6d7db148-ce1e-48e3-8352-c8679b88a2cd