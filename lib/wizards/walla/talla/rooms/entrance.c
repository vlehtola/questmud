inherit "room/room";
int i;
object avainsysteemi;

reset(arg) {

  add_exit("south","/wizards/walla/workroom");
  short_desc = "At the gates";
  long_desc = "You are standing on a small gravel path that leads nowhere. Up ahead lies a \n"+
              "huge limestone wall, that blocks your way further. A strange symbol can be spotted\n"+
              "on the wall though. If you look closer, it seems to represent a 5-pointed star.\n"+
              "Besides, an eerie feeling creeps up on you, as you stand here.\n";
}
init()
{


::init();
add_action("north","north");
add_action("unlock","unlock");
}
unlock(string str) {
if(!str) { write("Unlock what?\n"); return; }

avainsysteemi=present("avain0700123123",this_player());

if(!avainsysteemi) {
write("You don't have a key.\n");
return;
}

write("You unlock the gates, and they silently open, revealing a leafcovered path ahead.\n");
 destruct(avainsysteemi);
 add_exit("north","/wizards/walla/jericho/rooms/leblair/leblair1");
 i = 1;
 return 1;
}

north() {
if(!i) {
write("The gates are not opened.\n");
return 1;
}

}
