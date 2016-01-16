#!/bin/bash


# This script is used to process a datadictionary file and generate a appropriate header
# containing all the information


function write_template_struct {
   echo "template<unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & 0xffff) == $1>, bool_t<(eid & 0xffff) == $2>>: datadictionary_type {
   datadictionary():
      datadictionary_type(VR::$3, \"$4\", \"$5\", \"$6\", $7) {}
};"
}



function write_template_rng_struct {
   echo "template <unsigned gid, unsigned eid>
struct datadictionary<gid, eid, bool_t<(gid & $3) == $1>, bool_t<(eid & $4) == $2>>: datadictionary_type {
   datadictionary():
      datadictionary_type(VR::$5, \"$6\", \"$7\", \"$8\", $9) {}
};"
}




if [ $# -lt 1 ]; then
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
      echo "($GID,$EID); $VR; $MESF; $KEYW; $VM; "

   else
      VM=$(echo $line | rev | cut -d ' ' -f2 | rev)
      VR=$(echo $line | rev | cut -d ' ' -f3 | rev)
      KEYW=$(echo $line | rev | cut -d ' ' -f4 | rev)
      MESF=$(echo $line | cut -d ' ' -f1 --complement | rev | cut -d ' ' -f1,2,3,4 --complement | rev)
      GID=$(echo $TAG | tr -d '(' | cut -d ',' -f1 | sed -e 's/^/0x/')
      EID=$(echo $TAG | tr -d ')' | cut -d ',' -f2 | sed -e 's/^/0x/')
      echo "($GID,$EID); $VR; $MESF; $KEYW; $VM; RET"
   fi
done < $1

