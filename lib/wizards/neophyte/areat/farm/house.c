
inherit "room/room";
object woman;
int going;
reset (arg) {
            if(arg) return;
          if(!woman) {
             woman = clone_object("wizards/neophyte/areat/farm/monst/woman");
             move_object(woman, this_object());
             going = 0;
           }
        short_desc = "Old house";
        long_desc = "This is one of the oldest buildings in the Deleria, belonging to\n"+
                    "a rather old woman. The house looks clean and there's plenty of furnishing.\n"+
                    "The only problem seems to be those small holes in the walls and floorboards.\n";
    add_exit("out","room2");
    set_not_out(1);
    set_light(3);
    items = allocate(6);
        items[0] = "holes";
        items[1] = "Maybe some gnawer have made these holes";
}

init() {
  ::init();
  add_action("offerhelp", "offer");
}
offerhelp(str) {
  if(!woman) {
     write("There are nobody that you can help in here.\n");
     return 1;
  }
  if(going == 1) {
     write("Woman says: '"+this_player()->query_name()+" you are so nice but i dont need help anymore.'\n");
     return 1;
  }
  if(str == "help") {
     write("Woman seems very pleased by your offer.\n");
     write("She opens a trapdoor on the floor and\n");
     write("pushes you inside the floorboards\n");
     move_object(this_player(),"/wizards/neophyte/areat/farm/floor1.c");
         command("look",this_player());
     going = 1;
     return 1;
  }
}

done() {
  going = 0;
  if (woman) destruct(woman);
  return 1;
}
