ifeq ($(OS), Darwin)
DX_PATH := /Users/merck/Projects/mydroid/out/host/darwin-x86/bin/dx
DEXDUMP_PATH := /Users/merck/Projects/mydroid/out/host/darwin-x86/bin/dexdump
else
DX_PATH := /home/merck/work/ntu-android/out/host/linux-x86/bin/dx
DEXDUMP_PATH := /home/merck/work/ntu-android/out/host/linux-x86/bin/dexdump
endif


all:
	@javac dhry.java
	@$(DX_PATH) --dex --output=dhry.jar dhry.class
	@unzip dhry.jar
	@rm -rf META-INF *.jar
	@mv classes.dex dhry.dex

dump:
	@$(DEXDUMP_PATH) -d dhry.dex

clean:
	@rm -f *.jar dhry.dex DhrystoneConstants.class ExitObserver.class GlobalVariables.class Msg.class Record_Type.class dhry.class
