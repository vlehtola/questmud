inherit "room/room";
int door_open;
object mob;

reset(arg) {
  short_desc = "In a small wooden hut";
  long_desc = "The small hut looks quite cozy from inside. In the middle of the floor\n" + 
              "is lying a big bear fur. Some stuffed heads of dead animals are hanging\n" + 
              "near the ceiling. A wooden dinner table is by the western wall. Near the\n" + 
              "bed which is located by the eastern wall is a small night-stand with a\n" + 
              "painting standing on it. A window is located in the southern wall, as\n" + 
              "well as the door.\n";

  items = allocate(18);
  items[0] = "door";
  items[1] = "An ordinary-looking wooden door. Some carvings have been made to decorate\n" + 
             "the door, but no name or such is written on it. The door is open";
  items[2] = "fur";
  items[3] = "The bear fur which has been set on the floor looks very soft and comfortable\n" + 
             "to walk on. Bear's open mouth with its numerous sharp teeth is facing towards\n" + 
             "the front door of the house. The fur has almost three inch long hair";
  items[4] = "heads";
  items[5] = "Stuffed heads of the dead animals are hanging near the ceiling, creating a\n" + 
             "spooky atmosphere. The heads seem to be all from common animals, who once\n" + 
             "lived in the surrounding forest. The biggest head, which can be found from\n" + 
             "the middle of the head-row, belonged once to a bear";
  items[6] = "head";
  items[7] = "Try looking at 'heads'";
  items[8] = "table";
  items[9] = "A wooden dinner table stands by the western wall of the hut. The empty\n" + 
             "table looks quite sturdy despite that it has been made of wood. The\n" + 
             "table is big enough for three persons to dine around it in the same\n" + 
             "time";
  items[10] = "bed";
  items[11] = "A small and uncomfortable-looking bed. Strong smell of hay is surrounding\n" + 
              "the bed, indicating that the bed has been stuffed with hay or some other\n" + 
              "weeds";
  items[12] = "night-stand";
  items[13] = "A wooden night-stand is standing next to the bed. There does not seem\n" + 
              "to be any drawers in it, just a wooden stand where can be put something\n" + 
              "on. A picture has been placed on the night-stand";
  items[14] = "picture";
  items[15] = "A carefully-made picture of a female Orc. She must be somebody very close\n" + 
              "to the owner of this hut";
  items[16] = "window";
  items[17] = "The square-shaped window is located in the wall next to the door. The\n" + 
              "window gives out to the beautiul flowery meadow where can be spotted many\n" + 
              "different varieties of flowers and butterflies";
        
  if(!mob) { move_object(clone_object("/wizards/ahma/orc/mob/gralt"), this_object()); }
}

init() {
  ::init();
  add_action("hep", "open");
  add_action("hap", "close");
}

hep(str) {
  if(str == "door") {
  if(!door_open) {
    write("You open the wooden door leading out of the hut.\n");
    say(this_player()->query_name() + " opens the wooden door leading out of the hut.\n");
    add_exit("out", "/wizards/ahma/orc/forest/for36");
    call_other("/wizards/ahma/orc/forest/for36", "add_exit", "enter", "/wizards/ahma/orc/forest/house02");
    call_other("/wizards/ahma/orc/forest/for36", "door_opened");
    tell_room("/wizards/ahma/orc/forest/for36", "The wooden door leading into the hut opens.\n");
    door_opened();    
    return 1;
  }
  else {
    write("The door is already open.\n");
    return 1;
  }
  }
  else {
    write("Open what?\n");
    return 1;
  }
}

hap(str) {
  if(str == "door") {
  if(door_open) {
    write("You close the wooden door leading out of the hut.\n");
    say(this_player()->query_name() + " closes the wooden door leading out of the hut\n");
    remove_exit("out");
    call_other("/wizards/ahma/orc/forest/for36", "remove_exit", "enter");
    call_other("/wizards/ahma/orc/forest/for36", "door_closed");
    tell_room("/wizards/ahma/orc/forest/for36", "The wooden door leading into the hut closes.\n");
    door_closed();
    return 1;
  }
  else {
    write("The door is alredy closed.\n");
    return 1;
  }
  }
  else {
    write("Close what?\n");
    return 1;
  }
}

door_opened() {
    items[1] = "An ordinary-looking wooden door. Some carvings have been made to decorate\n" + 
               "the door, but no name or such is written on it. The door is open";
  door_open = 1;
}

door_closed() {
  door_open = 0;
    items[1] = "An ordinary-looking wooden door. Some carvings have been made to decorate\n" + 
               "the door, but no name or such is written on it. The door is closed";
}