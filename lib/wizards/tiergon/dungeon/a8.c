inherit "room/room";
object monster;

reset(arg) {
set_not_out(1);
add_exit("north","/wizards/tiergon/dungeon/a7");
  short_desc = "Beyond the rockfall";
  long_desc = "This part of the tunnel was cut of by the rockfall.\n"+
                "You could never have gotten here without the spectre's help.\n";
monster = clone_object("/wizards/tiergon/dungeon/monsters/qminer");
move_object(monster, this_object()); 
}
