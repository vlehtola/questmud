inherit "room/room";
reset(arg) {
if(arg) return;


short_desc = "Beside the large tombstone";
set_long("This part of the graveyard has only a one large tomb, the large stone door\n"+
             "of tomb is tightly shut and looks like there are no way getting inside\n"+
             "it. A small trail of light is coming from inside the tomb. Beside\n"+
             "the tomb is two massive looking boats carved from stone, looks like this\n"+
             "is an important tomb.\n");
  add_exit("east", "room2");
  items = allocate(6);
  items[0] = "boats";
  items[1] = "They are over two feets tall and carved from white stone";
  items[2] = "door";
  items[3] = "The door looks like it is tightly shut but something is moving inside the tomb, maybe you can pry this open";
  items[4] = "tomb";
  items[5] = "A large and beautifull tomb is builded in here. The door of tomb is little open";
}


init() {
  ::init();
  add_action("pry_door", "pry");
}
pry_door(str) {
	object ob;
	ob = present("crowbar", this_player());
	if(!str || str != "door") { write("Pry what?\n"); return 1; }
    if(!ob) { write("You try to force the door open without any success.\nMaybe you should get something to pry with.\n"); return 1; }
    if(this_player()->query_str() < random(this_player()->query_str()*2)) { write("You try hard but you lack the strength to complete.\n"); return 1; }

    write("You succesfully pry to door open and step inside the tomb.\n");
    say(this_player()->query_name()+" opens the door and steps in the tomb.\n");
    write("The door somehow moves itself back.\n");
    say("As "+this_player()->query_name()+" steps inside the tomb, the door is somehow moved back to place.\n");
    move_object(this_player(), "/wizards/neophyte/city/graveyard/tomb");
    return 1;
}
