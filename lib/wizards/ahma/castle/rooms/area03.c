inherit "room/room";
int hole_open = 0, i;
object monster01, maggot01, maggot02, maggot03;


reset(arg) {
  add_exit("north", "/wizards/ahma/castle/rooms/area11");
  add_exit("south", "/wizards/ahma/castle/rooms/area02");
  add_exit("west", "/wizards/ahma/castle/rooms/area04");
  add_exit("east", "/wizards/ahma/castle/rooms/area05");
  short_desc = "A 4-way intersection";
  long_desc = "A 4-way intersection.\n" + 
              "The hallway separates in four ways. In north is situated the throne\n" + 
              "room of the king. In east and west the hallways turn into a mere\n" + 
              "corridor which lead into the guarding posts. In south the hallway leads\n" + 
              "out from the castle. The carpet in this room is a bit sticky from all\n" + 
              "the blood poured on it and a rotting corpse of a guard is leaning against\n" + 
              "the wall near the eastern hallway.\n";
  items = allocate(2);
  items[0] = "corpse";
  items[1] = "As you start examining more closely to the corpse you notice that\n" + 
             "there is a huge hole in the wall behind the corpse's back. For a moment\n" + 
             "you hear a rattling noise from the hole";
  
  i = random(3);
  
  if(i == 0) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob02");
      move_object(monster01, this_object());
    }
  }
  if(i == 1) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob03");
      move_object(monster01, this_object());
    }
  }  
  if(i == 2) {
    if(!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob01");
      move_object(monster01, this_object());
    }
  }
  call_other("/wizards/ahma/castle/file1", "set_new_value", 0);
}

init() {
  ::init();
  hole_open = call_other("/wizards/ahma/castle/file1","query_arvo");
  add_action("pull", "move");
  add_action("pull", "pull");
  add_action("enter", "enter");
}

pull(str) {
  if(str == "corpse") {
  if(hole_open == 0) {
  write("You feel an urge to puke when you grasp on the corpse and pull it away\n" + 
        "from the wall. Behind the corpse is revealed a dark, deep hole. You\n" + 
        "wonder where is all the dirt that comes when digging holes this deep.\n" +
        "You don't see it anywhere in the room.\n");
  say(this_player()->query_name() + " pulls the corpse away from the wall. The hole is revealed.\n");
  write("\nSome flesh maggots bury themselves out from the hole.\n");
  say("\nSome flesh maggots bury themselves out from the hole.\n");
  if(!maggot01) {
    maggot01 = clone_object("/wizards/ahma/castle/mob/mob07");
    move_object(maggot01, this_object());
  }
  if(!maggot02) {
    maggot02 = clone_object("/wizards/ahma/castle/mob/mob07");
    move_object(maggot02, this_object());
  }
  if(!maggot03) {
    maggot03 = clone_object("/wizards/ahma/castle/mob/mob07");
    move_object(maggot03, this_object());
  }
  hole_open = 1;
  return 1;
  }
  write("The corpse has already been moved away from the wall.\n");
  return 1;
  }
}

enter(str) {
  if(str == "hole") {
  if(hole_open == 1) {
  write("You enter the dark hole.\n");
  this_player()->move_player("hole#/wizards/ahma/castle/rooms/area35i.c");
  return 1;
  }
  { write("You don't see a hole anywhere around here.\n");return 1; }
  }
}

test() {
  return hole_open;
}
