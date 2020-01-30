#include <ansi.h>

inherit "room/room";

object hani;

reset(arg) {
  if(arg) return;

  if(!hani)     {
    hani = clone_object("/world/objects/fountain");
    move_object(hani, this_object()); 
                }
    move_object(clone_object("/wizards/nalle/misc/banana"), this_object());
    move_object(clone_object("/wizards/nalle/misc/rose"), this_object());

  short_desc = "Nalle's bedroom";
  long_desc = ""; 
  property = ({ "no_summon", });
  set_light(10);
  add_exit("inn","/world/city/inn");
  add_exit("cs","/world/city/cs");
  add_exit("east","wizards/nalle/workroom");
  add_exit("jerusalem","wizards/nalle/jerusalem/wgate");
  add_exit("post","world/city/post");
  add_exit("ban","/room/banroom");
}

long() {
write(  "This is a neat lounge with a huge soft bed in the middle of\n"+
        "the room. It looks very comfortable and smells like honey!\n"+
        "It seems someone has been rolling in it recently, it must \n"+
        "be the lovely Anna. (Unless Mariah or Geri snuck in again!)\n"
        );
    ::long();
}

