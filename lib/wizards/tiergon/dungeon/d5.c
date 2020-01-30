inherit "room/room";
object monster,monster2,monster3;

reset(arg) {
if(!monster) {
    monster = clone_object("/wizards/tiergon/dungeon/monsters/icefiend");
    move_object(monster, this_object()); } 

if(!monster2) {
    monster2 = clone_object("/wizards/tiergon/dungeon/monsters/gelugon");
    move_object(monster2, this_object()); } 

if(!monster3) {
    monster3 = clone_object("/wizards/tiergon/dungeon/monsters/gelugon");
    move_object(monster3, this_object()); } 

  if(arg) return;
set_not_out(1);
add_exit("southwest","/wizards/tiergon/dungeon/d6");
add_exit("west","/wizards/tiergon/dungeon/d4");
add_exit("northwest","/wizards/tiergon/dungeon/d7");
  short_desc = "An abandoned mining tunnel";
  long_desc =
                "The gray walls are covered with a thick layer of dust that makes you cough.\n"+
		"It looks like the tunnel ended here originally, but has been somewhat modified by the new ihabitants"+
		"You're practically freezing in here\n";
}

