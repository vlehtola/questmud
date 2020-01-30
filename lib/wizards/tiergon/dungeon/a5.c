inherit "room/room";
object monster;

reset(arg) {
if (!monster) {
    monster = clone_object("/wizards/tiergon/dungeon/monsters/qspectre");
    move_object(monster, this_object());
    remove_exit("south"); }
set_not_out(1);
add_exit("north","/wizards/tiergon/dungeon/a4");
  short_desc = "The rockfall";
  long_desc = "This tunnel is of rougher make than the one above.\n"+
                "It looks like the tunnel was collapsed here on purpose.\n";
}
