inherit "room/room";
inherit "room/door";
object monster;

reset(arg) {
 if(!monster) {
    monster = clone_object("/wizards/tiergon/dungeon/monsters/miner3");
    move_object(monster, this_object()); }
  if(arg) return;
set_not_out(1);
add_exit("west","/wizards/tiergon/dungeon/2xroad");
set_door_dir("east","/wizards/tiergon/dungeon/superroom");
set_door_link("/wizards/tiergon/dungeon/superroom");
random_door_code();
set_door_desc("normal wooden "); 
short_desc = "In the barracks";
 long_desc = "This room's walls have been covered with wood to keep the heat in better.\n"+
             "There are two rows of seven beds. Several are covered with blood.\n";
items = allocate(4);
items[0] = "door";   
items[1] = "This is just a normal wooden door";
}

init() {
  ::init();
  door_init();
}
