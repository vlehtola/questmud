inherit "room/room";
reset(arg) {
if(arg) return;

set_not_out(1);
set_light(1);

short_desc = "A dark and misty corridor";
long_desc =  "This part of the corridor is in bad condition, the walls\n"+
             "have started to crack. The floor is full of dangerous looking\n"+
             "holes. The ceiling looks like it might come down in any second.\n";

add_exit("north","corridor8");
add_exit("west","corridor14");

  property = allocate(1);
  property[0] = "no_summon";
  }

