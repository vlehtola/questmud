inherit "room/room";
object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/jenny/gnael/mosut/baker.c");
    move_object(monster, this_object());
   }
  if(arg) return;

        add_exit("north","/wizards/jenny/gnael/huoneet/city26.c");

  short_desc = "In a bakery";
  long_desc = "You have arrived into the bakery of Gnael. There is\n"+
              "flour everywhere and you can smell the delicious smell\n"+
              "of just baked bread coming from the ovens. Some pans and\n"+
              "pots are hanging on the walls and a huge rolling pin\n"+
              "is placed on the table.\n";

}
