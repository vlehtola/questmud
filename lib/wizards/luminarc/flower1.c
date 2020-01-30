#include "/sys/ansi.h"

reset(arg) {
  if(arg) return;
}

short() {
  return "A beautiful yellow "+BOLD+YELLOW_F+"flower"+OFF;
}

id(str) {
  return str == "flower";

}

long() {
  write("A beautiful yellow flower\n");
}

get() {
        return 1;
}

query_weight() {
  return 1;
}

