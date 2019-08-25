echo "\nCurrent files in your project :\n"
find ./ex* -type f
echo "\nNorminette check...\n"
norminette -R CheckForbiddenSourceHeader ./*/ft*.c
norminette -R CheckForbiddenSourceHeader ./*/ft*.c | grep -e '^(Error|Warning)'
echo "\nTrying to compile\n"
gcc -c ./*/ft*.c ../../main.c -Wall -Werror -Wextra
rm *.o
echo "\nList of prototypes :\n"
cat ./*/ft* | grep "\tft"
cat ./*/ft* | grep "\t*ft"
echo "\n\nChecking for forbidden words...\n\n"
echo "\n -- Searching for \"stdio\"... --\n"
cat ./*/ft* | grep stdio
echo "\n -- Searching for \"printf\"... --\n"
cat ./*/ft* | grep printf
echo "\n -- Searching for \"main(\"... -- \n"
cat ./*/ft* | grep "main("
echo "\n -- Searching for \"for\"... -- \n"
cat ./*/ft* | grep "for"
echo "\n\nChecking finished."
