Install

```shell
bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)"

# LLVM default packages
apt-get install clang-format clang-tidy clang-tools clang clangd libc++-dev 
libc++1 libc++abi-dev libc++abi1 libclang-dev libclang1 liblldb-dev
libllvm-ocaml-dev libomp-dev libomp5 lld lldb llvm-dev llvm-runtime llvm
python-clang

# Other packages
sudo apt install cmake ninja-build iwyu cppcheck

# Python
pip3 install conan
```
