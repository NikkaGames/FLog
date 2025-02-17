# FLog
## FLog is a File Logger, logs any type of value into a file.

### This library will work without any issues on android and linux platform, not sure about other Operating Systems...

## Example:
```cpp
#include "FLog.h" //includes the FLog library


FLog* logger = new FLog("/storage/logs.txt"); //creates FLog instance.

int main() {

   logger->autosave(true); //enables auto save, it's on by default.

   logger->append("just a string"); //logs string value.

   logger->append(1234); //logs integer

   logger->append_arg("str: %s, %p, %d", "a word", logger->get_address_ptr(), 3828); //logs multiple values.

   logger->append_arg_mode("str: %s, %p, %d", NEW_LOG, "a word", logger->get_address_ptr(), 3828); //logs multiple values using custom save mode.

   logger->save(NEW_LOG); //saves the logs in file which is stored in memory, don't use this when auto save is turned on.

   logger->save(APPEND_LOG); //saves the logs in file which is stored in memory and also preserves the old content which was in file if it exists, don't use this when auto save is turned on.

   logger->erase(); //removes the log file if it exists.

   logger->clear(); //clears the log content in FLog instance memory.

   uintptr_t flog_addr = logger->get_address_ptr(); //gets the pointer address of FLog instance.

   std::string flog_addr_as_str = logger->get_address_str(); //gets the pointer address of FLog instance, but as a string.

   return 0;
}
```
----------

## BSD 2-Clause License

### Copyright (c) 2025, Nikka

```
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.```
