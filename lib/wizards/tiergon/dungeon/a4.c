inherit "room/room";
object monster;

reset(arg) {
if(!monster) {
    monster = clone_object("/wizards/tiergon/dungeon/monsters/bulette");
    move_object(monster, this_object()); } 
  if(arg) return;
set_not_out(1);
add_exit("northwest","/wizards/tiergon/dungeon/a3");
add_exit("south","/wizards/tiergon/dungeon/a5");
  short_desc = "A roughly-hewn tunnel";
  long_desc = "This tunnel is of rougher make than the one above.\n"+
                "The gray walls are covered with a thick layer of dust that makes you cough.\n"+
              "There are a few shredded corpses on the floor.\n";
}
