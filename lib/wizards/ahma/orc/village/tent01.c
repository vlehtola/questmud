inherit "room/room";
int moved, open, mob = 1;

reset(arg) {
  add_exit("out", "/wizards/ahma/orc/village/sq12");
  short_desc = "In the carpet shop";
  long_desc = "The tent is quite dimly illuminated for a carpet shop, but most of the\n" + 
              "carpets can be seen very clearly. Tent's walls are coloured in white\n" + 
              "from inside. Three high shelves are standing full of numerous different\n" + 
              "kinds and types of carpets. Though near the tent entrance is a humongous\n" + 
              "pile of some simple, green carpets which are being sold very cheap. A\n" + 
              "strange, annoying stench is floating all around the tent. It seems that\n" +
              "the carpets do not emit this kind of smell, it must be coming somewhere else.\n";
  
  items = allocate(8);
  items[0] = "shelf";
  items[1] = "The wooden shelves are stuffed full of different kinds of carpets. Some of\n" + 
             "them are very beautiful and seem worth of buying. The shelves look quite\n" + 
             "old. One bottom level is even cracked broken from one of the shelves";
  items[2] = "carpets";
  items[3] = "Every kinds of carpets can be found here. Furry carpets, soft carpets, harder\n" + 
             "carpets, bumpy carpets and even carpets with spikes or nails pierced through\n" +
             "them. The colour and symbol schemes are at least as varying as the difference\n" + 
             "between the carpet types. Near the entrance to this tent there seems to be a\n" + 
             "huge pile of simple, green carpets which the villagers tend to buy to decorate\n" + 
             "their homes. Behind the counter there is an ordinary, small red carpet on the\n" + 
             "ground. The red carpet looks pretty worn";
  items[4] = "lid";
  items[5] = "You see nothing special";
  items[6] = "carpet";
  items[7] = "Try looking at 'carpets'";            

  if(!present("gran'h", this_object())) { 
    move_object(mob = clone_object("/wizards/ahma/orc/mob/shopkeeper01"), this_object());
    moved = 0;
    open = 0;
    items[5] = "You see nothing special";
  }
}

init() {
  ::init();
  add_action("hep", "move");
  add_action("hap", "open");
  add_action("pep", "close");
}

hep(str) {
  if(str == "carpet") {
  if(!moved) {
  if(!mob) {
    write("You pull the small red carpet away from its present position and\n" + 
          "reveal a metallic lid under it. Seems that the lid might lead\n" + 
          "to the local sewers, at least that would explain the smell.\n");
    say(this_player()->query_name() + " pulls a carpet away revealing a metallic lid under it.\n");
    items[5] = "A shining metallic lid. These kind of lids are usually used to block\n" + 
               "the sewer entrances";
    moved = 1;
    return 1;
  }
  else {
    write("The shopkeeper is standing on the carpet and you cannot move it.\n");
    tell_room(environment(this_player()), "Gran'h glares coldly at " + this_player()->query_name() + ".\n");
    return 1;
  }
  }
  else {
    write("You put the carpet back to its original place hiding the metallic lid.\n");
    say(this_player()->query_name() + " moves the carpet back to its original place hiding the lid.\n");
    remove_exit("down");
    items[5] = "You see nothing special";
    moved = 0;
    return 1;
  }
  }
  else {
    write("Move what?\n");
    return 1;
  }
}
       
hap(str) {
  if(str == "lid") {
  if(!open) {
  if(moved) {
    write("You open the metallic lid and a huge cloud of crap-stench blows on your face\n" + 
          "You cough a little and get yourself together. The dark hole gapes by your\n" + 
          "feet.\n");
    say(this_player()->query_name() + " opens the metallic lid and a huge cloud of crap-stench blows in\n" + 
        "the tent from a dark hole which is revealed.\n");
    add_exit("down", "/wizards/ahma/orc/village/sub17");
    call_other("/wizards/ahma/orc/village/sub17", "add_exit", "up", "/wizards/ahma/orc/village/tent01");
    call_other("/wizards/ahma/orc/village/sub17", "opened");
    tell_room("/wizards/ahma/orc/village/sub17", "The metallic lid above you opens.\n");
    open = 1;
    return 1;
  }
  else {
    write("You don't see a lid around here.\n");
    return 1;
  }
  }
  else {
    write("The metallic lid is already open.\n");
    return 1;
  }
  }
  else {
    write("Open what?\n");
    return 1;
  }
}

pep(str) {
  if(str == "lid") {
  if(moved) {
  if(open) {
  write("You close the lid preventing more stench from spreading into this tent.\n");
  say(this_player()->query_name() + " closes the metallic lid.\n");
  remove_exit("down");
  call_other("/wizards/ahma/orc/village/sub17", "remove_exit", "up");
  call_other("/wizards/ahma/orc/village/sub17", "closed");
  tell_room("/wizards/ahma/orc/village/sub17", "The metallic lid above you closes.\n");
  open = 0;
  return 1;
  }
  else {
  write("The metallic lid is already closed.\n");
  return 1;
  }
  }
  else {
  write("You don't see a lid around here.\n");
  }
  }
  else {
  write("Close what?\n");
  return 1;
  }
}

dead() {
  mob = 0;
}

alive() {
  mob = 1;
}

check() {
  return mob;
}

opened() {
  open = 1;
}

closed() {
  open = 0;
}

carpetmoved() {
  moved = 1;
}

poppi() {
  if(!present("gran'h", this_object())) { 
    move_object(clone_object("/wizards/ahma/orc/mob/test"), this_object());
    moved = 0;
    open = 0;
    items[5] = "You see nothing special";
  }
}
