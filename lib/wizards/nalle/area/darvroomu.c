inherit "room/room";

object monster;

reset(arg) {
if(arg) return;
  if(!monster) {
    monster = clone_object("/wizards/nalle/area/monsters/realdarvox.c");
    move_object(monster, this_object());
  }
  
  add_exit("down","/wizards/nalle/area/darvroom.c");
  short_desc = "A very large lounge";
  long_desc =
"The dimensions of this room are huge. The ceiling seems to be 20 feet\n" +
"high. There is a long wooden desk in the northern part of the room.\n" +
"Behind the desk there is a black throne, which seems to be meant for\n" +
"someone of an outstanding size. Some wine red lingerie has been left\n" +
"on a couch by one of Darvox's female admirers.\n";

set_not_out(1);
set_light(3);
}


