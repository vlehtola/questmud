inherit "room/room";
object monster;

reset(arg) {
if(!monster) {
    monster = clone_object("/wizards/tiergon/dungeon/monsters/bcfighter3");
    move_object(monster, this_object()); } 
  if(arg) return;
set_not_out(1);
add_exit("west","/wizards/tiergon/dungeon/d2");
add_exit("east","/wizards/tiergon/dungeon/d4");
  short_desc = "An abandoned mining tunnel";
  long_desc =
                "The gray walls are covered with a thick layer of dust that makes you cough.\n"+
		"It looks like the sounds of fighting are coming from the next room to the east.\n"+
		"You're practically freezing in here\n";
}

