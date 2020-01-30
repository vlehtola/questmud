inherit "room/room";
object monster,monster2,monster3,monster4;

reset(arg) {
if(!monster) {
    monster = clone_object("/wizards/tiergon/dungeon/monsters/bcfighter3");
    move_object(monster, this_object()); } 

if(!monster2) {
    monster2 = clone_object("/wizards/tiergon/dungeon/monsters/bcfighter3");
    move_object(monster2, this_object()); } 

if(!monster3) {
    monster3 = clone_object("/wizards/tiergon/dungeon/monsters/gelugon");
    move_object(monster3, this_object()); } 

if(!monster4) {
    monster4 = clone_object("/wizards/tiergon/dungeon/monsters/gelugon");
    move_object(monster4, this_object()); } 
  if(arg) return;
set_not_out(1);
add_exit("west","/wizards/tiergon/dungeon/d3");
add_exit("east","/wizards/tiergon/dungeon/d5");
  short_desc = "An abandoned mining tunnel";
  long_desc =
                "The gray walls are covered with a thick layer of dust that makes you cough.\n"+
		"It looks like you've been caught in a struggle between Black Circle fighters and some type of blue-skinned fiends"+
		"You're practically freezing in here\n";
}

