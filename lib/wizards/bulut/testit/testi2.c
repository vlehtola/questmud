
int gate_open;

init() {

  add_action("open");
  add_action("close");
}

close(str) {
  if(str == "gate") {
    if(gate_open) {
      write("You close the gate.\n");
      say(this_player()->query_name()+" closes the gate.\n");
      gate_open = 0;
      return 1;
      }
  }
}

open(str) {
  if(gate_open) {
    write("You open the gate.\n");
    gate_open = 1;
    return 1;
                }
    write("The gate is already open.\n");
    return 1;
          }

id(str) {
  if(str == "open") {
  return 1;
                    }
  if(str == "close") {
  return 1; }
                     }

