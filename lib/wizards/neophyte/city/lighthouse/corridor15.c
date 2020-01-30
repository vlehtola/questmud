inherit "room/room";

reset(arg) {
if(arg) return;

set_not_out(1);
set_light(1);

short_desc = "A small corridor";
long_desc =  "The corridor is getting smaller and it's going\n"+
             "little upwards, indicating that it will shortly\n"+
             "end. A dim light is going in from west.\n";

add_exit("west","corridor16");
add_exit("east","corridor8");

  property = allocate(1);
  property[0] = "no_summon";
}

