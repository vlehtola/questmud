#include "room.h"

string owner;
int id, x, y;
query_owner() { return owner; }
set_owner(arg) { owner = arg; }
query_castle_id() { return id; }
set_castle_id(arg) { id = arg; }
query_x() { return x; }
set_x(arg) { x = arg; }
query_y() { return y; }
set_y(arg) { y = arg; }
is_entryroom() { return 1; }
reset(arg) {
  if(arg) return;
  x = 95;
  y = 116;
  owner = "Astarel";
  id = 1;
  add_exit("northwest", "outmap: 95 116");
  add_exit("north", "outmap: 95 116");
  add_exit("northeast", "outmap: 95 116");
  add_exit("east", "outmap: 95 116");
  add_exit("southeast", "outmap: 95 116");
  add_exit("south", "outmap: 95 116");
  add_exit("southwest", "outmap: 95 116");
  add_exit("west", "outmap: 95 116");
  add_exit("enter", "/data/castle/castle_1/room0.c");
  set_short("Entrace to castle");
  set_long("There is a castle looming next to you. Castles perimeter has been"+
"\ncleared of other terrain, making it as safe as possible. There is moot"+
"\nsurrounding all but the two big doors allowing entry to the castle.\n");
}