inherit "room/room";
object monster;

reset(arg) {
 if(!monster) {
    monster = clone_object("/wizards/tiergon/dungeon/monsters/bcguard");
    move_object(monster, this_object()); }
  if(arg) return;
set_not_out(1);
add_exit("east","/wizards/tiergon/dungeon/c1");
add_exit("west","/wizards/tiergon/dungeon/b1");
add_exit("up","/wizards/tiergon/dungeon/2xroad");  
add_exit("down","/wizards/tiergon/dungeon/4xroad");
  short_desc = "Black Circle checkpoint";
  long_desc = "The twisting staircase continues both upwards and downwards\n"+
              "The Black Circle keeps a checkpoint here.\n";
}
