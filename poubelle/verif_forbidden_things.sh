echo "\n\nCurrent files in your project :\n\n"
find ./ex* -type f
echo "\n\nChecking for forbidden words...\n\n"
echo "\n -- Searching for \"stdio\"... --\n"
cat ./*/* | grep stdio
echo "\n -- Searching for \"printf\"... --\n"
cat ./*/* | grep printf
echo "\n -- Searching for \"main(\"... -- \n"
cat ./*/* | grep "main("
echo "\n -- Searching for \"for\"... -- \n"
cat ./*/* | grep "for"
echo "\n\nChecking finished."
