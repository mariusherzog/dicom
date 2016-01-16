#!/bin/bash


# This script is used to process a datadictionary file and generate a appropriate header
# containing all the information


function write_template_struct {
   echo "template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == $1>, bool_t<(eid & 0xffff) == $2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::$3, \"$4\", \"$5\", \"$6\", $7) {}
};"
}



function write_template_rng_struct {
   echo "template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & $3) == $1>, bool_t<(eid & $4) == $2>>: dictionary_entry {
   datadictionary():
      dictionary_entry(VR::$5, \"$6\", \"$7\", \"$8\", $9) {}
};"
}



declare -A template_map_mask



if [ $# -lt 1 ]; then
   echo "Usage: gendatadic.sh datadic.txt"
fi


cat datadic_template.cpp

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
      if [ $(echo $GID | tr -cd x | wc -c) -gt 1 ] || [  $(echo $EID | tr -cd x | wc -c) -gt 1 ]; then
         MASKGID=$(echo "0x$(echo $GID | cut -c 1-2 --complement | sed -e 's/[0-9a-fA-f]/f/g' | sed -e 's/x/0/g')")
         MASKEID=$(echo "0x$(echo $EID | cut -c 1-2 --complement | sed -e 's/[0-9a-fA-f]/f/g' | sed -e 's/x/0/g')")
         GID=$(echo "0x$(echo $GID | cut -c 1-2 --complement | sed -e 's/[xX]/0/g')")
         EID=$(echo "0x$(echo $EID | cut -c 1-2 --complement | sed -e 's/[xX]/0/g')")
         write_template_rng_struct "$GID" "$EID" "$MASKGID" "$MASKEID" "$VR" "$MESF" "$KEYW" "$VM" "false"
      else
         write_template_struct "$GID" "$EID" "$VR" "$MESF" "$KEYW" "$VM" "false" 
      fi

   else
      VM=$(echo $line | rev | cut -d ' ' -f2 | rev)
      VR=$(echo $line | rev | cut -d ' ' -f3 | rev)
      KEYW=$(echo $line | rev | cut -d ' ' -f4 | rev)
      MESF=$(echo $line | cut -d ' ' -f1 --complement | rev | cut -d ' ' -f1,2,3,4 --complement | rev)
      GID=$(echo $TAG | tr -d '(' | cut -d ',' -f1 | sed -e 's/^/0x/')
      EID=$(echo $TAG | tr -d ')' | cut -d ',' -f2 | sed -e 's/^/0x/')
      if [ $(echo $GID | tr -cd x | wc -c) -gt 1 ] || [  $(echo $EID | tr -cd x | wc -c) -gt 1 ]; then
         MASKGID=$(echo "0x$(echo $GID | cut -c 1-2 --complement | sed -e 's/[0-9a-fA-f]/f/g' | sed -e 's/x/0/g')")
         MASKEID=$(echo "0x$(echo $EID | cut -c 1-2 --complement | sed -e 's/[0-9a-fA-f]/f/g' | sed -e 's/x/0/g')")
         GID=$(echo "0x$(echo $GID | cut -c 1-2 --complement | sed -e 's/[xX]/0/g')")
         EID=$(echo "0x$(echo $EID | cut -c 1-2 --complement | sed -e 's/[xX]/0/g')")
         write_template_rng_struct "$GID" "$EID" "$MASKGID" "$MASKEID" "$VR" "$MESF" "$KEYW" "$VM" "true"
      else
         write_template_struct "$GID" "$EID" "$VR" "$MESF" "$KEYW" "$VM" "true" 
      fi
   fi
done < $1

cat datadic_template_tail.cpp

