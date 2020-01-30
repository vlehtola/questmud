inherit "room/room";
object monster;

reset(arg) {
 if(!monster) {
    monster = clone_object("/wizards/tiergon/dungeon/monsters/crzminer");
    move_object(monster, this_object()); }
  if(arg) return;
set_not_out(1);
add_exit("east","/wizards/tiergon/dungeon/barracks1");
add_exit("south","/wizards/tiergon/dungeon/2tunnel");
add_exit("west","/wizards/tiergon/dungeon/barracks2");
add_exit("up","/wizards/tiergon/dungeon/1xroad");  
add_exit("down","/wizards/tiergon/dungeon/3xroad");
  short_desc = "Deeper inside the mine shaft";
  long_desc = "The twisting staircase continues both upwards and downwards\n"+
              "The miners' residental area is situated east and west from here.\n";
}
