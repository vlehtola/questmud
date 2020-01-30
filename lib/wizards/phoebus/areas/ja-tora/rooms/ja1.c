inherit "room/room";
object monster;
object monster2;

reset(arg) {

if(!monster) {
monster = clone_object("/wizards/phoebus/areas/ja-tora/monsters/g_guard");
move_object(monster, this_object());
 }

if(!monster2) {
monster2 = clone_object("/wizards/phoebus/areas/ja-tora/monsters/g_guard");
move_object(monster2, this_object());
}

if(arg) return;

add_exit("east","/wizards/phoebus/areas/ja-tora/rooms/ja2");
  //  Add exit to outer world  "leave"  //  


short_desc = "Entrance to Ja-Tora";
long_desc = "This small entrance opens up into the village of Ja-Tora, small \n"+
                      "stone houses line Gnome made roads. The village is situated \n"+
                      "beside a small range of mountains and is surrounded by a tall \n"+    
                      "wooden fence, giving it extra protection.\n";
}
