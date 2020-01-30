#include "/sys/ansi.h"

reset(arg) {
  if(arg) return;
}

short() {
  return "A beautiful red "+BOLD+RED_F+"rose"+OFF;
}

id(str) {
  return str == "rose";

}

long() {
  write("A beautiful red rose from your secret admirer.\n");
}

get() {
	return 1;
}

query_weight() {
return 100000;
}
