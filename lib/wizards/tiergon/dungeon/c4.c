inherit "room/room";
inherit "room/door";
object monster;

reset(arg) {
  if(!monster) {
  monster = clone_object("/wizards/tiergon/dungeon/monsters/amage");
  move_object(monster, this_object()); }
if (arg) return;  
  add_exit("north","/wizards/tiergon/dungeon/c10");
  set_door_dir("east","/wizards/tiergon/dungeon/cmager");
  set_door_link("/wizards/tiergon/dungeon/cmager");
  set_door_desc("massive bronze "); 
  add_exit("west","/wizards/tiergon/dungeon/c3");  
  short_desc = "The Magist's antechamber";  
  long_desc = "From the moment you enter this room it becomes obvious that the room has been crafted by a powerful and egoistic wizard."+ 
              "The magical aura lighting the room and the roof soaring some 50 feet to"+ 
              "the mountain above make that much pretty obvious.\n";
  set_not_out(3);
}
init() {
  ::init();
  door_init();
}

