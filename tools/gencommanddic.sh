#!/bin/bash


function write_cmd_struct {
   echo "template<>
struct commanddictionary<$1, $2>: commanddictionary_type {
   commanddictionary():
      commanddictionary_type(VR::$3, \"$4\", \"$5\", \"$6\") {}
};"
}



if [ $# -lt 1 ]; then
   echo "Usage: gendcommanddic.sh commanddic.txt"
fi

cat cmddic_template.cpp


while read line; do
   TAG=$(echo $line | cut -d ';' -f1 | tr -d ' ')
   MESF=$(echo $line | cut -d ';' -f2 | sed -e 's/^ //g')
   KEYW=$(echo $line | cut -d ';' -f3 | tr -d ' ')
   VR=$(echo $line | cut -d ';' -f4 | tr -d ' ')
   VM=$(echo $line | cut -d ';' -f5 | tr -d ' ')

   GID=$(echo "0x$(echo $TAG | cut -d ',' -f1 | tr -d '(')")
   EID=$(echo "0x$(echo $TAG | cut -d ',' -f2 | tr -d ')')")

   write_cmd_struct "$GID" "$EID" "$VR" "$MESF" "$KEYW" "$VM"

done < $1

cat cmddic_template_tail.cpp

