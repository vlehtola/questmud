inherit "room/room";
int purity, darkness, satisfaction, crudeness, complete, h = random(3);
object mob, isomoko;

reset(arg) {
  add_exit("south", "/wizards/ahma/orc/forest/sub08");
  add_exit("southwest", "/wizards/ahma/orc/forest/sub09");
  add_exit("southeast", "/wizards/ahma/orc/forest/sub07");
  short_desc = "In the northern end of an underground opening";
  long_desc = "The smooth, stony opening ends into a wall shimmering in bright blue.\n" + 
              "The strong magical presence can be felt in this small tunnel and a\n" + 
              "quiet humming can be heard coming from somewhere inside the walls. The\n" + 
              "ground trembles softly under your feet and the powder-like particles\n" + 
              "are floating in the mid-air. In the center of this tunnel is an altar-\n" + 
              "like construction.\n";
  
  items = allocate(6);
  items[0] = "altar";
  items[1] = "The altar-like construction is fully made of sturdy-looking stone. There\n" + 
             "seems to be lots of runes and some symbols carved in the stony plate which\n" + 
             "is held in air by three sturdy stands. The stony construction is trembling\n" + 
             "softly along the rest of the room. A quiet humming can also be heard coming\n" + 
             "from inside the altar";
  items[2] = "runes";
  items[3] = "'Thy shall resurrect me by bringing here my four Relics of Life.'\n" + 
             "There are four small, quite deep holes carved into the stone plate near\n" + 
             "the runes. Under each hole there appears to be a name for it. From left\n" + 
             "to right the names are as follows: Purity, Darkness, Satisfaction and Crudeness";
  items[4] = "slot";
  items[5] = "You see nothing special";

  if(!mob) {
    if(h==1) { move_object(clone_object("/wizards/ahma/orc/mob/elemental02"), this_object()); }
    if(h==2 || h==0) { move_object(clone_object("/wizards/ahma/orc/mob/elemental03"), this_object()); }
  }
}

init() {
  ::init();
  add_action("hep", "put");
}

hep(str) {
  string what, where;
  if(!str) { write("Put what in where?\n"); return 1; }
  if(sscanf(str, "%s in %s", what, where) != 2) {
  write("Put what in where?\n");
  return 1;
  }
  
  else {
    if(what == "lily" && where == "purity") {
    if(present("lily", this_player()) && !present("lily", this_player())->query_no_save()) {
    if(purity) { write("There is already a flower in the hole.\n"); return 1; }  
      write("You put a lily in the hole named 'Purity' and the flower seems to turn into stone.\n");
      say(this_player()->query_name() + " operates something with the altar-like construction.\n");
      purity = 1;
      destruct(present("lily", this_player()));
      call_out("complete", 2);
      return 1;
    }
    else {
      write("You don't have a lily.\n");
      return 1;
    }
  }
  else {
    if(what == "lily" && (where == "darkness" || where == "satisfaction" || where == "crudeness")) {
    if(present("lily", this_player())) {
    if(where == "darkness" && darkness) { write("There is already something in the hole.\n"); return 1; }
    if(where == "satisfaction" && satisfaction) { write("There is already something in the hole.\n"); return 1; }
    if(where == "crudeness" && crudeness) { write("There is already something in the hole.\n"); return 1; }
      write("Nothing seems to happen. You take the lily out from the hole.\n");
      say(this_player()->query_name() + " operates something with the altar-like construction.\n");
      return 1;
    }
    else {
      write("You don't have a lily.\n");
      return 1;
    }
  }
  
  else {
    if(what == "orchid" && where == "satisfaction") {
    if(present("orchid", this_player()) && !present("orchid", this_player())->query_no_save()) {
    if(satisfaction) { write("There is already a flower in the hole.\n"); return 1; }  
      write("You put an orchid in the hole named 'Satisfaction' and the flower seems to turn into stone.\n");
      say(this_player()->query_name() + " operates something with the altar-like construction.\n");
      satisfaction = 1;
      destruct(present("orchid", this_player()));
      call_out("complete", 2);
      return 1;
    }
    else {
      write("You don't have an orchid.\n");
      return 1;
    }
  }
  else {
    if(what == "orchid" && (where == "purity" || where == "darkness" || where == "crudeness")) {
    if(present("orchid", this_player())) {
    if(where == "purity" && purity) { write("There is already something in the hole.\n"); return 1; }
    if(where == "darkness" && darkness) { write("There is already something in the hole.\n"); return 1; }
    if(where == "crudeness" && crudeness) { write("There is already something in the hole.\n"); return 1; }
      write("Nothing seems to happen. You take the orchid out from the hole.\n");
      say(this_player()->query_name() + " operates something with the altar-like construction.\n");
      return 1;
    }
    else {
      write("You don't have an orchid.\n");
      return 1;
    }
  }

  else {
    if(what == "night-bell" && where == "darkness") {
    if(present("night-bell", this_player()) && !present("night-bell", this_player())->query_no_save()) {
    if(darkness) { write("There is already a flower in the hole.\n"); return 1; }  
      write("You put a night-bell in the hole named 'Darkness' and the flower seems to turn into stone.\n");
      say(this_player()->query_name() + " operates something with the altar-like construction.\n");
      darkness = 1;
      call_out("complete", 2);
      destruct(present("night-bell", this_player()));
      return 1;
    }
    else {
      write("You don't have a night-bell.\n");
      return 1;
    }
  }
  else {
    if(what == "night-bell" && (where == "purity" || where == "satisfaction" || where == "crudeness")) {
    if(present("night-bell", this_player())) {
    if(where == "purity" && purity) { write("There is already something in the hole.\n"); return 1; }
    if(where == "satisfaction" && satisfaction) { write("There is already something in the hole.\n"); return 1; }
    if(where == "crudeness" && crudeness) { write("There is already something in the hole.\n"); return 1; }
      write("Nothing seems to happen. You take the night-bell out from the hole.\n");
      say(this_player()->query_name() + " operates something with the altar-like construction.\n");
      return 1;
    }
    else {
      write("You don't have a night-bell.\n");
      return 1;
    }
  }
  
  else {
    if(what == "carnation" && where == "crudeness") {
    if(present("carnation", this_player()) && !present("carnation", this_player())->query_no_save()) {
    if(crudeness) { write("There is already a flower in the hole.\n"); return 1; }  
      write("You put a carnation in the hole named 'Crudeness' and the flower seems to turn into stone.\n");
      say(this_player()->query_name() + " operates something with the altar-like construction.\n");
      crudeness = 1;
      destruct(present("carnation", this_player()));
      call_out("complete", 2);
      return 1;
    }
    else {
      write("You don't have a carnation.\n");
      return 1;
    }
  }
  else {
    if(what == "carnation" && (where == "purity" || where == "satisfaction" || where == "darkness")) {
    if(present("carnation", this_player())) {
    if(where == "purity" && purity) { write("There is already something in the hole.\n"); return 1; }
    if(where == "satisfaction" && satisfaction) { write("There is already something in the hole.\n"); return 1; }
    if(where == "darkness" && darkness) { write("There is already something in the hole.\n"); return 1; }
      write("Nothing seems to happen. You take the carnation out from the hole.\n");
      say(this_player()->query_name() + " operates something with the altar-like construction.\n");
      return 1;
    }
    else {
      write("You don't have a carnation.\n");
      return 1;
    }
  }

  else {
    if(what == "violet" && where == "slot" && complete) {
    if(present("violet", this_player()) && !present("violet", this_player())->query_no_save()) {
      write("You put a violet in the slot in the wall. The flower turns into dust.\n");
      say(this_player()->query_name() + " puts a flower in the slot in the wall. The flower turns into dust.\n");
      call_out("complete2", 3);
      destruct(present("violet", this_player()));
      return 1;
    }
    else {
      write("You don't have a violet.\n");
    }
  }
  else {
    if(what == "violet" && (where == "purity" || where == "satisfaction" || where == "darkness" || where == "crudeness")) {
    if(present("violet", this_player())) {
    if(where == "purity" && purity) { write("There is already something in the hole.\n"); return 1; }
    if(where == "darkness" && darkness) { write("There is already something in the hole.\n"); return 1; }
    if(where == "satisfaction" && satisfaction) { write("There is already something in the hole.\n"); return 1; }
    if(where == "crudeness" && crudeness) { write("There is already something in the hole.\n"); return 1; }
      write("Nothing seems to happen. You take the violet out from the hole.\n");
      say(this_player()->query_name() + " operates something with the altar-like construction.\n");
      return 1;
    }
    else {
      write("You don't have a violet.\n");
      return 1;
    }
  }
 
 else {
  /*write("That is not possible.\n");*/
  return;
  }
}
}
}
}
}
}
}
}
}
}
}

complete() {
  if(purity && darkness && satisfaction && crudeness) {
    tell_room(this_object(), "When placing the final flower in its right hole, the room starts shaking\n" + 
              "more intensively. The low voice starts speaking through the walls:\n" + 
              "'The most important part of life is still needed to raise me from my dark\n" + 
              "burial coffin. Bring the last, a passionate symbol of Love, to me and I\n" + 
              "shall show myself to thou.'\n" + 
              "As the voice goes quiet a small slot opens from the shimmering blue wall\n" + 
              "on front of you.\n");
    items[5] = "A small slot made of shimmering blue stone is situated in the wall in northern\n" + 
               "side of the room. The symbol of Love, the heart, has been carved above the slot";
    complete = 1;
    return 1;
  }
  else { return 0; }
}

complete2() {
  tell_room(this_object(), "\nThe room starts shaking dangerously, some smaller rocks fall down from ceiling\n" + 
           "but luckily none of them hits you. The shiny wall in the end of the tunnel\n" + 
           "flashes in bright blue and something dark seems to float through it into the\n" + 
           "room.\n");
  call_out("complete3", 8);
  return 1;
}

complete3() {
  tell_room(this_object(), "\nAfter a while you notice that the dark matter resonating throught the wall\n" + 
           "is actually a figure of some huge creature. Eventually the creature is close\n" + 
           "enough for you to recognize that it is some kind of a huge stone elemental.\n");
  call_out("complete4", 8);
  return 1;
}

complete4() {
  tell_room(this_object(), "\nThe elemental jumps through the wall and the bright light disappears. Stone\n" + 
           "elemental is standing in front of you, looking extremely angry when its long\n" + 
           "sleep has been disturbed. The monster goes for the kill.\n");
  move_object(clone_object("/wizards/ahma/orc/mob/elemental04"), this_object());
  return 1;
}
