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


