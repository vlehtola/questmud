inherit "room/room";
int door_open, h, alive;
object mob;


reset(arg) {
  add_exit("north", "/wizards/ahma/orc/forest/for37");
  add_exit("west", "/wizards/ahma/orc/forest/for34");
  add_exit("southwest", "/wizards/ahma/orc/forest/for35");
  short_desc = "In the center of a flowery meadow";
  long_desc = "The flowery meadow shimmers in every colour of the whole spectrum.\n" +
              "The soil feels soft under your feet, the weeds and the stalks of the\n" + 
              "flowers are fondling your legs when advancing forward in the opening.\n" + 
              "Some butterflies can be seen flying over the flowers. The meadow ends\n" + 
              "into a thick wall of trees in east. A wooden hut is located in north.\n" + 
              "A thin path is leading behind the building.\n";

  items = allocate(10);
  items[0] = "flower";
  items[1] = "Try looking at 'flowers'";
  items[2] = "flowers";
  items[3] = "Many different varieties of flowers are living in this meadow. There must\n" + 
             "be almost a dozen different types of flowers, but seems that not too rare\n" +
             "varieties or species can be found. The flowers emit a soft, wonderful\n" + 
             "scent and some butterflies can be seen flying from flower to flower";
  items[4] = "butterflies";
  items[5] = "Common-looking butterflies live their short life here. Flying from flower\n" + 
             "to flower, getting nutrients and in the same time pollinating the flowers.\n" +
             "Butterflies are a beautiful sight in the meadow, but the flowers win even\n" + 
             "those with their fascinating and bright colours";
  items[6] = "hut";
  items[7] = "The brown hut made of wood probably belongs to one of the hunters living in\n" +
             "the forest. A window is located in the wall near the door, but the shutters\n" + 
             "are closed. A wooden door leading into the hut is also closed";
  items[8] = "door";
  items[9] = "An ordinary-looking wooden door. Some carvings have been made to decorate\n" + 
             "the door, but no name or such is written on it. The door is closed";

  h = random(5);
  if(!mob) {
  if(!alive) {
    if(h==0) { move_object(mob = clone_object("/wizards/ahma/orc/mob/bear01"), this_object()); alive = 1; }
    if(h==1) { move_object(mob = clone_object("/wizards/ahma/orc/mob/eagle"), this_object()); }
    if(h==2) { move_object(mob = clone_object("/wizards/ahma/orc/mob/fox"), this_object()); alive = 1; }
    if(h==3) { move_object(mob = clone_object("/wizards/ahma/orc/mob/deer"), this_object()); alive = 1; }
    if(h==4) { move_object(mob = clone_object("/wizards/ahma/orc/mob/jogger"), this_object()); alive = 1; }
  }
  }
}

init() {
  ::init();
  add_action("hep", "open");
  add_action("hap", "close");
  if(!random(250)) {
    tell_room(this_object(), "An Orcish ranger jumps out from the bush.\n");
    move_object(clone_object("/wizards/ahma/orc/mob/ranger"), this_object());
  }
}

hep(str) {
  if(str == "door") {
  if(!door_open) {
    write("You open the wooden door leading into the hut.\n");
    say(this_player()->query_name() + " opens the wooden door leading into the hut.\n");
    add_exit("enter", "/wizards/ahma/orc/forest/house02");
    call_other("/wizards/ahma/orc/forest/house02", "add_exit", "out", "/wizards/ahma/orc/forest/for36");
    call_other("/wizards/ahma/orc/forest/house02", "door_opened");
    tell_room("/wizards/ahma/orc/forest/house02", "The wooden door leading out of the hut opens.\n");
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
    write("You close the wooden door leading into the hut.\n");
    say(this_player()->query_name() + " closes the wooden door leading into the hut\n");
    remove_exit("enter");
    call_other("/wizards/ahma/orc/forest/house02", "remove_exit", "out");
    call_other("/wizards/ahma/orc/forest/house02", "door_closed");
    tell_room("/wizards/ahma/orc/forest/house02", "The wooden door leading out of the hut closes.\n");
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
  door_open = 1;
    items[7] = "The brown hut made of wood probably belongs to one of the hunters living in\n" +
               "the forest. A window is located in the wall near the door, but the shutters\n" + 
               "are closed. A wooden door leading into the hut is open";
    items[9] = "An ordinary-looking wooden door. Some carvings have been made to decorate\n" + 
               "the door, but no name or such is written on it. The door is open";
}

door_closed() {
  door_open = 0;
    items[7] = "The brown hut made of wood probably belongs to one of the hunters living in\n" +
               "the forest. A window is located in the wall near the door, but the shutters\n" + 
               "are closed. A wooden door leading into the hut is also closed";
    items[9] = "An ordinary-looking wooden door. Some carvings have been made to decorate\n" + 
               "the door, but no name or such is written on it. The door is closed";
}

mobdead() {
  alive = 0;
}
