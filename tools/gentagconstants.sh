#!/bin/bash

# Helper script for generation of named constants for a tag in
# the command or data dictionary. Manual adjustments after
# creation may be necessary.

function write_tag_constant {
   echo "const elementfield::tag_type $3 {$1, $2};"
}



if [ $# -lt 2 ]; then
   echo "Usage: gendcommanddic.sh commanddic.csv datadic.csv"
fi

cat tagconstants_template.cpp


for file in $(echo "$1 $2"); do
   while read line; do
      TAG=$(echo $line | cut -d ';' -f1 | tr -d ' ')
      KEYW=$(echo $line | cut -d ';' -f3 | tr -d ' ')
   
      GID=$(echo "$(echo $TAG | cut -d ',' -f1 | tr -d '(')")
      EID=$(echo "$(echo $TAG | cut -d ',' -f2 | tr -d ')')")

      KEYWCLEAN=$(echo $KEYW | sed -e 's/[^a-zA-Z0-9]//g')
   
      write_tag_constant "$GID" "$EID" "$KEYWCLEAN" 
   
   done < $file
done

cat tagconstants_template_tail.cpp

