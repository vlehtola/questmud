inherit "room/room";
reset(arg) {
if(arg) return;

set_not_out(1);
set_light(1);

short_desc = "A dark and misty corridor";
long_desc =  "A dark and misty corridor. There are no dust on the floor,\n"+
             "it looks like someone is taking a good care of this part\n"+
             "of the lighthouse. The walls are decorated all sort of \n"+
             "navigation equipment's.\n";

add_exit("west","corridor8");
add_exit("south","corridor12");

  property = allocate(1);
  property[0] = "no_summon";
  }

