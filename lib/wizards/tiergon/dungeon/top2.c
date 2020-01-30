inherit "room/room";
object monster;

reset(arg) {
 if(!monster) {
    monster = clone_object("/wizards/tiergon/dungeon/monsters/crzminer");
    move_object(monster, this_object()); }
  if(arg) return;
set_not_out(1);
add_exit("north","/wizards/tiergon/dungeon/topoffice");
add_exit("southeast","/wizards/tiergon/dungeon/top1");
add_exit("west","/wizards/tiergon/dungeon/vault1");
  short_desc = "The 1st level guard post";
  long_desc = "Guards stationed here were responsible for the safety of the vault and the supervisor welfare.\n"+
              "From the way blood is splattered on the walls you'd guess they were killed by a sharp weapon only a few hours ago.\n";
}
