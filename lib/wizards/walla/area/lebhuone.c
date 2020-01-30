/*Changed by Siki 16.12.2000*/
inherit "room/room";
object leb,guard;

reset(arg) {

   if(!leb) {
      if(arg) return;
      leb = clone_object("/wizards/walla/area/monsters/lebkamar");
      move_object(leb, this_object());
      }
   if(!guard) {
      guard = clone_object("/wizards/walla/area/monsters/privateer");
      move_object(guard, this_object());
      }

add_exit("out","/wizards/walla/area/cs");
add_exit("maze","/wizards/walla/area/wrongway4");

short_desc = "Leb-Kamars secret chambers";
long_desc =
"You are in a great hall covered with paintings and plans. Leb-Kamar seems\n"+
"to be working on something, so he doesn't like your presence.\n";

set_not_out(1);
set_light(3);

}
