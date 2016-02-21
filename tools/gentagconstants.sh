#!/bin/bash

# Helper script for generation of named constants for a tag in
# the command or data dictionary. Manual adjustments after
# creation may be necessary.

declare -A identifiers


function write_tag_constant {
   echo "const elementfield::tag_type $3 {$1, $2};"
   identifiers[$3]=1
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
      KEYWCLEAN=$(echo $KEYWCLEAN | sed -e 's/\(^[0-9]\)/n\1/')
   
      if [[ $(echo $GID | sed -e 's/^0x//' | tr -cd 'x'| wc -c) -eq 0 ]] \
         && [[ $(echo $EID | sed -e 's/^0x//' | tr -cd 'x'| wc -c) -eq 0  ]] \
         && [[ ${identifiers[$KEYWCLEAN]} -ne 1 ]]; then

         write_tag_constant "$GID" "$EID" "$KEYWCLEAN" 
      fi
   
   done < $file
done

cat tagconstants_template_tail.cpp

