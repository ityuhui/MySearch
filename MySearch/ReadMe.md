# Text search CLI on Windows

## Usage
```
PS C:\> ..\MySearch.exe
All options:
  -r [ --reg ] arg      Regular expression that to find
  -f [ --file ] arg     File or directory to parse, the default is current
                        working directory
  -g [ --debug ]        Enable debug log
  -v [ --version ]      Print version
  -h [ --help ]         Print help message
```

## Sample
```
PS C:\MySearch\test> .\MySearch.exe --reg hello
Line 3, in file .\a.txt, hello
Line 3, in file .\b\a.txt, hello
```
