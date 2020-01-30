inherit "room/room";
reset(arg) {
if(arg) return;

set_not_out(1);
set_light(1);

short_desc = "A corridor on the second floor of the lighthouse";
long_desc =  "A dark corridor on the second floor of the lighthouse. The\n"+
             "walls of the corridor are made from solid looking rocks.\n"+
             "A wooden banister is going in to all corridors. The floor\n"+
             "doesn't look that solid and lots of blood tips are on it.\n";

add_exit("north","corridor9");
add_exit("south","corridor13");
add_exit("west","corridor15");
add_exit("east","corridor11");
add_exit("down","corridor7");

  property = allocate(1);
  property[0] = "no_summon";
  }

