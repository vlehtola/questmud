inherit "room/room";
object kivi;

reset(arg) {
if (!kivi) {
    kivi = clone_object("/wizards/tiergon/dungeon/boulder");
    move_object(kivi, this_object());
}
set_not_out(1);
add_exit("north","/wizards/tiergon/dungeon/a5");
  short_desc = "The rockfall";
  long_desc = "This part of the tunnel was cut of by the rockfall.\n"+
                "You could never have gotten here without the spectre's help.\n";
}
