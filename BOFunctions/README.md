## Description :
This is a simple [idc](https://www.hex-rays.com/products/ida/support/idadoc/157.shtml) script that finds vulnerable functions to Buffer Overflow (inspired by: [The IDA Pro Book](https://www.amazon.com/IDA-Pro-Book-Unofficial-Disassembler/dp/1593272898)), list of functions name can be found in **BOFunctionsList.txt** , the list is according to [OWASP](https://owasp.org/www-community/attacks/Buffer_overflow_attack) list.

## Usage : 
1 - Move both files : **BOFunctionsList.txt** & **BOFunctions.idc** to same directory with the executable <br>
2 - Import the script to IDA : file > script file

## Sample Output : 
![alt text](https://github.com/0xb1tByte/RE/blob/master/BOFunctions/1.png)
