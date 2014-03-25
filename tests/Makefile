all:
	@javac dhry.java
	@/Users/merck/Projects/mydroid/out/host/darwin-x86/bin/dx --dex --output=dhry.jar dhry.class
	@unzip dhry.jar
	@rm -rf META-INF *.jar
	@mv classes.dex dhry.dex

dump:
	@/Users/merck/Projects/mydroid/out/host/darwin-x86/bin/dexdump -d dhry.dex

clean:
	@rm -f *.jar dhry.dex DhrystoneConstants.class ExitObserver.class GlobalVariables.class Msg.class Record_Type.class dhry.class
