inherit "room/room";
object smith;

reset(arg) {
 if(arg) return;
 if(!smith) {
 smith = clone_object("/wizards/rimber/cave/brutus.c");
 move_object(smith, this_object());
 }
 short_desc = "In a secret weaponsmith";
 long_desc = "You stand in a dimly lit room. In the middle of the room\n"+
  "there is a big, black anvil. Broken weapons and armour lie on\n"+
      "the ground. It is really hot in here.\n";
 set_light(3);
 add_exit("leave", "/wizards/rimber/cave/room5.c");
 set_not_out(1);
}
