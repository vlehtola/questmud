inherit "room/room";
int planted, growing;
object plant;

reset(arg) {
  add_exit("northwest", "/wizards/ahma/orc/forest/for06");
  add_exit("southeast", "/wizards/ahma/orc/forest/for04");
  short_desc = "On a soft forest path";

  items = allocate(2);
  items[0] = "soil";
  items[1] = "The soil here looks very fertile and moist. This would be the\n" + 
             "most optimal place to plant a new plant";

  if(planted) { soilon(); } else { soiloff(); }

  if(growing == 3) {
    destruct(present("plant", this_object()));
    plant = move_object(clone_object("/wizards/ahma/orc/mob/carnplant04"), this_object());
    tell_room(this_object(), "The huge green plant jumps out from the ground and starts furiously jump towards you.\n");
    growing++;
  }

  if(growing == 2) {
    destruct(present("sprout", this_object()));
    move_object(clone_object("/wizards/ahma/orc/eq/root3"), this_object());
    tell_room(this_object(), "The sprout on the ground starts shaking and grows much larger.\n");
    growing++;
  }

  if(growing == 1) {
    move_object(clone_object("/wizards/ahma/orc/eq/root2"), this_object());
    tell_room(this_object(), "A small green sprout pops up from the ground.\n");
    growing++;
  }
}

init() {
  int i;
  ::init();
  i = random(5);
  if(i==0) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc01") + 
             "The soil in this part of the forest looks very fertile.\n"; }
  if(i==1) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc02") + 
             "The soil in this part of the forest looks very fertile.\n"; }
  if(i==2) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc03") + 
             "The soil in this part of the forest looks very fertile.\n"; }
  if(i==3) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc04") + 
             "The soil in this part of the forest looks very fertile.\n"; }
  if(i==4) { long_desc = read_file("/wizards/ahma/orc/forest/fordesc05") + 
             "The soil in this part of the forest looks very fertile.\n"; }
  add_action("hep", "plant");
  if(!random(250)) {
    tell_room(this_object(), "An Orcish ranger jumps out from the bush.\n");
    move_object(clone_object("/wizards/ahma/orc/mob/ranger"), this_object());
  }
}

hep(str) {
  if(str == "root") {
  if(present("root", this_player()) && !present("root", this_player())->query_no_save()) {
  if(!planted) {
    write("You gently place the root under the fertile soil and start waiting for something to happen.\n");
    say(this_player()->query_name() + " buries something under ground.\n");
    destruct(present("root", this_player()));
    soilon();
    growing = 1;
    return 1;
  }
  else {
    write("There seems to be already something planted in the ground.");
    return 1;
  }
  }
  else {
    write("You don't have a root.\n");
    return 1;
  }
  }
  else {
    return;
  }
}

soilon() {
  items[1] = "The soil here looks very fertile and moist. There seems to be\n" + 
             "something planted in the ground";
  planted = 1;
}

soiloff() { 
  items[1] = "The soil here looks very fertile and moist. This would be the\n" + 
             "most optimal place to plant a new plant";
  planted = 0;
}
