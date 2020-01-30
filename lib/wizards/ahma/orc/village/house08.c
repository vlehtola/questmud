inherit "room/room";
int moved, open;

reset(arg) {
  add_exit("west", "/wizards/ahma/orc/village/vil25");
  short_desc = "In the chief's house";
  long_desc = "Chief Tas'gand's house is suspiciously dimly lit. No actual light sources\n" + 
              "are seen, but some light is luminating in from the window located in the\n" + 
              "eastern wall. By the eastern wall is also a wooden bookshelf and by the\n" + 
              "northeastern corner is located a wooden table. Few small-sized paintings\n" + 
              "are hanging on the southern wall. A furry, red carpet is covering the\n" + 
              "floor throughout the house. The Chief does not seem to be present at the\n" + 
              "moment.\n";

  items = allocate(16);
  items[0] = "window";
  items[1] = "The square-shaped window has been carved in the eastern wall. The window\n" + 
             "gives out to the forest which is surrounding the village from east. The\n" + 
             "light coming from the window is the only actual light source from where\n" + 
             "the apartment gets its lighting at the moment";
  items[2] = "bookshelf";
  items[3] = "A wooden bookshelf is half-full of books. The shelves which are not filled\n" + 
             "with books are loaded with some other, sentimentally valuable items such as\n" + 
             "stones, teeth and shards of different bones. Some of the items seem to have\n" + 
             "turned over from their presumably original position";
  items[4] = "table";
  items[5] = "A common-looking wooden table which could be found in any of the houses in\n" + 
             "this village. Its weight has been equally divided to all of its four legs\n" + 
             "on which it is standing on. A modest, white covering has been placed on the\n" + 
             "table";
  items[6] = "painting";
  items[7] = "Try looking at 'paintings'";
  items[8] = "paintings";
  items[9] = "Few paintings of some unfamiliar Orcs are hanging on the southern wall. They\n" + 
             "might be picturing the previous chiefs of the village Nehelam. The paintings\n" +
             "seem to be noticeably smaller than the other paintings seen all around the\n" + 
             "village. There are no names or such on the paintings";
 items[10] = "carpet";
 items[11] = "A furry, mostly red carpet feels comfortable under your feet. The carpet\n" +
             "has some yellow symbols in addon to the red background. The material from\n" +
             "which the carpet has been made seems somehow very expensive. The furry\n" +
             "carpet covers almost whole area of the apartment's floor. Two small bumps\n" +
             "can be seen on the carpet in the corner where the bookshelf is located";
 items[12] = "bumps";
 items[13] = "Two bumps grow up from the carpet near the corner where the bookshelf is\n" + 
             "located. The carpet does not seem to be attached to the floor, so you might\n" + 
             "be able to lift it and see what causes the bumps on the carpet";
 items[14] = "hatch";
 items[15] = "You see nothing special";

  if(moved) {
    items[15] = "A metallic hatch shimmers weakly in the dim light. Seems that there is\n" + 
                "no lock or such thing in it, so it can be opened and closed whenever needed";
  }
}

init() {
  ::init();
  add_action("hep", "lift");
  add_action("hap", "move");
  add_action("hap", "push");
  add_action("pep", "open");
  add_action("pap", "close");
}

hep(str) {
  if(str == "carpet") {
    write("You lift the red carpet to see what is under it and discover two metallic\n" +
          "hinge-like objects. The hatch itself seems to be under the bookshelf.\n" + 
          "You drop the carpet back on the floor as you stop looking at the hinges.\n");
    return 1;
  }
}

hap(str) {
  if(str == "bookshelf") {
  if(!moved) {
    write("You push the bookshelf away from the corner, revealing a metallic hatch\n" + 
          "under it.\n");
    say(this_player()->query_name() + " moves the bookshelf away from the corner, in the same time revealing a metallic hatch.\n");
    items[15] = "A metallic hatch shimmers weakly in the dim light. Seems that there is\n" + 
                "no lock or such thing in it, so it can be opened and closed whenever needed";
    moved = 1;
    return 1;
  }
  else {
    write("You do not need to move the bookshelf back to its original place.\n");
    return 1;
  }
  }
  else {
    return;
  }
}

pep(str) {
  if(str == "hatch") {
  if(moved) {
  if(!open) {
    write("You open the metallic hatch and discover a new exit leading down via ladders.\n");
    say(this_player()->query_name() + " opens a metallic hatch, discovering a new exit to down.\n");
    add_exit("down", "/wizards/ahma/orc/village/sub01");
    call_other("/wizards/ahma/orc/village/sub01", "add_exit", "up", "/wizards/ahma/orc/village/house08");
    call_other("/wizards/ahma/orc/village/sub01", "opened");
    tell_room("/wizards/ahma/orc/village/sub01", "The metallic hatch above you opens.\n");
    open = 1;
    return 1;
  }
  else {
    write("The metallic hatch is already open.\n");
    return 1;
  }
  }
  else {
    write("You don't see a hatch around here.\n");
    return 1;
  }
  }
  else {
    return;
  }
}

pap(str) {
  if(str == "hatch") {
  if(moved) {
  if(open) {
    write("You close the metallic hatch hiding the exit leading down.\n");
    say(this_player()->query_name() + " closes the metallic hatch hiding the exit leading down.\n");
    remove_exit("down");
    call_other("/wizards/ahma/orc/village/sub01", "remove_exit", "up");
    call_other("/wizards/ahma/orc/village/sub01", "closed");
    tell_room("/wizards/ahma/orc/village/sub01", "The metallic hatch above you closes.\n");
    open = 0;
    return 1;
  }
  else {
    write("The metallic hatch is already closed.\n");
    return 1;
  }
  }
  else {
    write("You don't see a hatch around here.\n");
  }
  }
  else {
    return;
  }
}

opened() {
  open = 1;
}

closed() {
  open = 0;
}

movedi() {
  return moved;
}

moveda() {
  moved = 0;
  items[15] = "You see nothing special";
  tell_room(this_object(), "Chief Tas'gand pushes the bookshelf back to its original place.\n");
  return 1;
}
