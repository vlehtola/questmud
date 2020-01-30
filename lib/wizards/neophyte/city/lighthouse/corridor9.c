inherit "room/room";
reset(arg) {
if(arg) return;

set_not_out(1);
set_light(1);

short_desc = "A dark and misty corridor";
long_desc =  "A dark and misty corridor. There are no dust on the floor,\n"+
             "it looks like someone is taking a good care of this part\n"+
             "of the lighthouse. A small table is placed next to wall.\n"+
             "Walls are grey, maybe it's from the cement which was used to\n"+
             "build this lighthouse.\n";

add_exit("east","corridor10");
add_exit("south","corridor8");

  property = allocate(1);
  property[0] = "no_summon";
  }

