inherit "room/room";

reset(arg) {

        add_exit("west","/wizards/jenny/gnael/huoneet/thief5.c");

  short_desc = "In a basement";
  long_desc = "You are in a basement, there are no light sources\n"+
              "so it is difficult to see anything. The place is\n"+
              "very clean if you consider that it is a basement.\n"+
              "Some paintings are hung on the wall and there is\n"+
              "a small statue placed on a pilar on the middle of\n"+
              "the room. Otherwise the room is completely empty\n"+
              "and gloomy.\n";

        items = allocate(4);
        items[0] = "paintings";
        items[1] = "A few paintings with pictures of famous assassins.";
        items[2] = "statue";
        items[3] = "A small gloomy looking statue resembling a knight.";

}

init() {
  ::init(); 
  add_action("turn", "turn"); 
}

turn(str) {
  if(str == "statue") {
    write("You turn the statue around and a door opens!\n"); 
    say(this_player()->query_name()+" turns the statue and a door opens!\n");
    add_exit("east","/wizards/jenny/gnael/huoneet/thief7.c");
    command("look",this_player());
     }
     return 1;
 }
