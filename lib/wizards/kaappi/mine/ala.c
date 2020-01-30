inherit "room/room";
object monster;
status i;
reset(arg) {
if(arg) return;

add_exit("up", "r24.c");
  short_desc = "Tunnel of gold";
   long_desc = "There are many holes all around the walls.\n"+
               "This room is much lighter than the others. Maybe there\n"+
               "once was lots of veins of gold or mithril, but now \n"+
              "only the holes are left.\n";

  set_light(3);

items = allocate(4);
       items[0] = "hole";
        items[1] = "There is one hole which is clearly different from others.\n"+
                   "There seems to be something in it.\n";
}

search_finished(str) {
      if(!i && str == "hole") {
      write("You find a book.\n");
      say(this_player()->query_name()+ " founds something.\n");
       move_object(clone_object("/wizards/kaappi/mine/kamat/kirja.c"), this_player());
        items[1] = "Just an empty hole.\n";
i = 1;
  return 1;
}
write("You find nothing special.\n");
say(this_player()->query_name()+ " founds nothing.\n");
return 1;
}
