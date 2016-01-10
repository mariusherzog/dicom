#!/bin/bash


function write_template_struct {
   echo "template <>
struct datadictionary<$1, $2>: datadictionary_type<$1, $2>
{
   datadictionary():
      datadictionary_type {VR::$3, \"$4\", \"$5\", $6} {}
};"
}


if [ $# -eq 0 ]; then
   echo "Usage: gendatadic.sh datadic.txt"
fi

while read line; do
   HASRET=0;

   TAG=$(echo $line | cut -d ' ' -f1)
   RET=$(echo $line | rev | cut -d ' ' -f1 | rev)
   if [ $RET != "RET" ]; then
      VM=$RET
      VR=$(echo $line | rev | cut -d ' ' -f2 | rev)
      KEYW=$(echo $line | rev | cut -d ' ' -f3 | rev)
      MESF=$(echo $line | cut -d ' ' -f1 --complement | rev | cut -d ' ' -f1,2,3 --complement | rev)
      GID=$(echo $TAG | tr -d '(' | cut -d ',' -f1 | sed -e 's/^/0x/')
      EID=$(echo $TAG | tr -d ')' | cut -d ',' -f2 | sed -e 's/^/0x/')
      write_template_struct "$GID" "$EID" "$VR" "$MESF" "$KEYW" "false" 
   else
      VM=$(echo $line | rev | cut -d ' ' -f2 | rev)
      VR=$(echo $line | rev | cut -d ' ' -f3 | rev)
      KEYW=$(echo $line | rev | cut -d ' ' -f4 | rev)
      MESF=$(echo $line | cut -d ' ' -f1 --complement | rev | cut -d ' ' -f1,2,3,4 --complement | rev)
      GID=$(echo $TAG | tr -d '(' | cut -d ',' -f1 | sed -e 's/^/0x/')
      EID=$(echo $TAG | tr -d ')' | cut -d ',' -f2 | sed -e 's/^/0x/')
      write_template_struct "$GID" "$EID" "$VR" "$MESF" "$KEYW" "true" 
   fi



done < $1


