Apps= ./Apps
Include=./Include
Bin=./Bin
Build= ./Build
Headers= ./Headers
Object= ./Object
Library= ./Library
extra_tags= -std=c++17

Comp_gpp:
	g++ ${extra_tags}  -c ${Include}/HandleStringExpression.cpp -I${Headers} -o ${Object}/HandleStringExpression.o 
	ar -rcs ${Library}/libed_Gpp.a ${Object}/*.o
Comp_emcc:
	emcc ${extra_tags}  -c ${Include}/HandleStringExpression.cpp -I${Headers} -o ${Object}/HandleStringExpression.o 
	emar -rcs ${Library}/libed_Emcriptem.a ${Build}/*.o
main:
	g++ ${Apps}/main.cpp ${Object}/*.o -I${Headers} -o ${Bin}/main.exe
run:
	./Bin/main.exe	