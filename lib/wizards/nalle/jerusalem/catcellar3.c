inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/drunkmonk");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/catcellar3w");
  add_exit("east","wizards/nalle/jerusalem/catcellar3e");
  add_exit("south","wizards/nalle/jerusalem/catcellar2");
  short_desc = "The wine cellar";
  long_desc =
"You have entered a marvellous wine cellar, with tyrannous oaken\n" +
"barrels everywhere, and best of all they are full. There are a few \n" +
"monks here spending their free time too. The room is lit with\n" +
"torches and you notice wine puddles on the floor.\n";
}
