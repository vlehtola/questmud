inherit "room/room";
int systeemi;

object vehje;

reset(arg) {
    if(!vehje) {
    vehje = clone_object("/wizards/nalle/jerusalem/eq/kitten");
    move_object(vehje, this_object());
 }
  if(arg) return;
  add_exit("down","wizards/nalle/jerusalem/cattower2");
  short_desc = "Above the bell";
  long_desc =
"You have entered a room that you did not expect would exist.\n" +
"There are signs of habitation here: a straw bed, ragged clothes \n" +
"and a pair of leather shoes lie in the midst of the pigeon excrements.\n";
}

init() {
    ::init();
   add_action("get", "get");
}

get(str) {
   if (str == "kitten") {
   if(!vehje) {
   write("Nothing taken.\n");
   return 1;
   }
   if (systeemi != 0) { write("You can not see the kitten here.\n");
   return 1;
   }
  write("A man jumps in your way from a shadowy corner and roars furiously.\n");
  say(this_player()->query_name()+" tries to get the kitten but a furious man jumps in the way.\n");
  move_object("/wizards/nalle/jerusalem/monsters/quasimodo", this_object());
  systeemi = 1;
 }
}
