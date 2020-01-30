inherit "room/room";
object monster;

reset(arg) {
if (!monster) {
    monster = clone_object("/wizards/tiergon/dungeon/monsters/revenant");
    move_object(monster, this_object());
}
set_not_out(1);
add_exit("north","/wizards/tiergon/dungeon/a6");
add_exit("south","/wizards/tiergon/dungeon/a8");
  short_desc = "Beyond the rockfall";
  long_desc = "This part of the tunnel was cut of by the rockfall.\n"+
                "You could never have gotten here without the spectre's help.\n";
}
