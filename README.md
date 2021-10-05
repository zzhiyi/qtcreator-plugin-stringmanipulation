# qtcreator-plugin-stringmanipulation
A String Manipulation Plugin For Qt Creator (Usefull in wine development)

## Feature:
* Search selected string in Google
* Selected String to Char Array:   
`abcd` -> `{'a','b','c','d',0}`  
`'`    -> `{'\'',0}`  
`中文` -> `{0x4e2d,0x6587,0}`  
* Strip Space in Selected String:   
`a b c d` -> `abcd`  
* Add Break Point:   
  -> `__asm__ __volatile__("int3");`  
* Sort Declaration By Length:  
```
int b;      int abc;
int abc; -> int cd;
int cd;     int a;
```
* Paste Diff:  
```
+ added      added
  old     -> old
- deleted
```
