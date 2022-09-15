#!/bin/sh

if [ ! -f ./tools/xxd ]; then
	echo "Compiling xxd..."

	cd tools
	cc xxd.c -o xxd
	cd ..
fi

echo "Building assets..."
./tools/xxd -i assets/LOGO.TMD > Assets.h
./tools/xxd -i assets/ARROW.TMD >> Assets.h
./tools/xxd -i assets/TROPHY.TMD >> Assets.h
./tools/xxd -i assets/FONT.TIM >> Assets.h
./tools/xxd -i assets/BUTTONS.TIM >> Assets.h
./tools/xxd -i assets/ANSWER.VAG >> Assets.h
./tools/xxd -i assets/POINTS.VAG >> Assets.h
./tools/xxd -i assets/QUIZEND.VAG >> Assets.h
./tools/xxd -i assets/QUIZ1.VAG >> Assets.h
./tools/xxd -i assets/QUIZ2.VAG >> Assets.h
./tools/xxd -i assets/QUIZ3.VAG >> Assets.h
./tools/xxd -i assets/WINNER.VAG >> Assets.h
