# MSX SDCC Make Script
Repository containing templates and build scripts for easy creating of C applications for MSX with SDCC

## OSX
- **pre-build**
  - Install **[SDCC](http://sdcc.sourceforge.net)** with brew `brew install sdcc`
  - Download and compile [hex2bin](http://hex2bin.sourceforge.net) with a simples `make && sudo make install`
  - Download and install [openMSX](https://openmsx.org) from [here](https://github.com/openMSX/openMSX/releases/download/RELEASE_16_0/openmsx-16.0-mac-x86_64-bin.dmg)
  - clone [this template](github.com/paoloo/sdcc-msx-template) to the project: `git clone git@github.com:paoloo/sdcc-msx-template.git project-name`
  - chmod +x Make/make.sh
- **usage**
  - **BUILD**: `Make/make.sh <PROFILE> <TYPE>` where PROFILE is `Debug` or `Release` and TYPE is the type of application that should be built: `ROM`, `BIN` or `MSXDOS`.
  - **TEST**:  using openMSX: `/Applications/openMSX.app/Contents/MacOS/openmsx` with `-diska directory/`, `-cart APP.ROM` or send the compiled binary to the MSXDOS directory and mount it.

**IMPORTANT!** The current `main.c` is good for a `ROM`, to create a different binary, copy from `examples/msx<type>app.c` to `main.c`, where <app> is `bin`, `dos` or `rom`.

## Geany

go to `Tools > Configuration Files > Filetype Configuration > Programming Languages > filetype.c` and the C file definitions will be ready to be edited. Change the latest limes to:

```
T_00_LB=_Compile
FT_00_CM=./Make/make.sh Debug ROM
FT_00_WD=
FT_01_LB=_Build
FT_01_CM=./Make/make.sh Debug ROM
FT_01_WD=
FT_02_LB=_Lint
FT_02_CM=cppcheck --language=c --enable=warning,style --template=gcc "%f"
FT_02_WD=
EX_00_LB=_Execute
EX_00_CM=/Applications/openMSX.app/Contents/MacOS/openmsx -machine Panasonic_FS-A1GT -cart Debug/bin/MSXAPP.ROM
EX_00_WD=
```
For `EX_00_CM`, use the full path for openmsx on your system or just its name if it is on `PATH`

now, just open `main.c` and be happy!

Now you can compile with `Build > Compile` or `F8` and run the compiled code on the emulator with `Build > Run` or `F5`.


Be Happy!
