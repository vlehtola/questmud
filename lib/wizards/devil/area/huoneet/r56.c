inherit "room/room";
object monster,monster2;



reset(arg) {

  if(!present("mummy")) {
   move_object(clone_object("/wizards/devil/area/mobit/mummy.c"), this_object());
   move_object(clone_object("/wizards/devil/area/mobit/mummy.c"), this_object());
}
 
  if(arg) return;

 add_exit("east","/wizards/devil/area/huoneet/r57.c");
 add_exit("south","/wizards/devil/area/huoneet/r55.c");

 short_desc = "Low aisle deep in the huge temple";
 long_desc = "This aisle is lower than the earlier one probably because it's leading you\n"+
                "back under the ground. There are some paintings hanging from the wall\n"+
                "trying to make this aisle more domestic.\n";

items = allocate(2);
  items[0] = "paintings";
  items[1] = "This gallery was painted to make this aisle more domestic.";

}