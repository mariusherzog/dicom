#!/bin/bash


# This script is used to process a datadictionary file and generate a appropriate header
# containing all the information. Additional after processing might be necessary.


function write_template_struct {
   echo "template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == $1>, bool_t<(eid & 0xffff) == $2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(attribute::VR::$3, \"$4\", \"$5\", \"$6\", $7) {}
};"
}



function write_template_rng_struct {
   echo "template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & $3) == $1>, bool_t<(eid & $4) == $2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(attribute::VR::$5, \"$6\", \"$7\", \"$8\", $9) {}
};"
}


if [ $# -lt 1 ]; then
   echo "Usage: gendatadic.sh datadic.txt"
fi


cat datadic_template.cpp

while read line; do
   ISRET="false";

   TAG=$(echo $line | cut -d ';' -f1 | tr -d ' ')
   RET=$(echo $line | cut -d ';' -f6 | tr -d ' ')
   if [[ $RET == "RET" ]]; then
      ISRET="true";
   fi

      VM=$(echo $line | cut -d ';' -f5 | tr -d ' ')
      VR=$(echo $line | cut -d ';' -f2 | tr -d ' ' )
      KEYW=$(echo $line | cut -d ';' -f4 | tr -d ' ')
      MESF=$(echo $line | cut -d ';' -f3 | sed -e 's/^ *//')
      GID=$(echo $TAG | tr -d '(' | cut -d ',' -f1 | sed -e 's/0x//')
      EID=$(echo $TAG | tr -d ')' | cut -d ',' -f2 | sed -e 's/0x//')
      if [ $(echo $GID | tr -cd x | wc -c) -gt 0 ] || [  $(echo $EID | tr -cd x | wc -c) -gt 0 ]; then
         MASKGID=$(echo "0x$(echo $GID | sed -e 's/[0-9a-fA-f]/f/g' | sed -e 's/x/0/g')")
         MASKEID=$(echo "0x$(echo $EID | sed -e 's/[0-9a-fA-f]/f/g' | sed -e 's/x/0/g')")
         GID=$(echo "0x$(echo $GID | sed -e 's/[xX]/0/g')")
         EID=$(echo "0x$(echo $EID | sed -e 's/[xX]/0/g')")
         write_template_rng_struct "$GID" "$EID" "$MASKGID" "$MASKEID" "$VR" "$MESF" "$KEYW" "$VM" "$ISRET"
      else
         GID=$(echo $GID | sed -e 's/^/0x/')
         EID=$(echo $EID | sed -e 's/^/0x/')
         write_template_struct "$GID" "$EID" "$VR" "$MESF" "$KEYW" "$VM" "$ISRET" 
      fi
done < $1

cat datadic_template_tail.cpp

