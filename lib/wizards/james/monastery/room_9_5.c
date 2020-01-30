
#include "dir.h"
inherit "room/room";
int found;

reset(arg)
{
  if(!arg)
  {
    short_desc = "A storageroom";
    long_desc = "This is a huge storage room, it is probably used to store every religious item which isn't used every day. A huge wooden cross is lying against the north wall.\n";
    add_exit("west",DIR+"room_8_5.c");
    set_light(1);
    found=0;
  }
}
/*
init() {
add_action("search","search");
::init();
}
*/
search_finished() {
  if(found==0) {
	write("You find a small silver cross!\n");
	say(this_player()->query_name()+" finds a small silver cross!\n");
	found=1;
	move_object(clone_object(DIR+"scross.c"),this_player());
  }
  return 1;
}
