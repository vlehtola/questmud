inherit "room/room";
object monster;

reset(arg) {
 if(!monster) {
    monster = clone_object("/wizards/tiergon/dungeon/monsters/bcguard3");
    move_object(monster, this_object()); }
  if(arg) return;
set_not_out(1);
add_exit("east","/wizards/tiergon/dungeon/d1");
add_exit("south","/wizards/tiergon/dungeon/e1");
add_exit("up","/wizards/tiergon/dungeon/3xroad");  
add_exit("down","/wizards/tiergon/dungeon/5xroad");
  short_desc = "Mine shaft";
  long_desc = "The twisting staircase continues both upwards and downwards\n"+
              "You can hear the clash of weapons coming from east.\n";
}
