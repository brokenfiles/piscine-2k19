FOLDER=$(echo $(git rev-parse --show-toplevel))
FILE=$FOLDER/.gitignore
while IFS= read -r line
do
  if test -f "$FOLDER/$line";  then
    echo $line
  fi
done < "$FILE"
