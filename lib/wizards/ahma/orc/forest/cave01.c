inherit "room/room";
int placed, complete, stash, empty;

reset(arg) {
  add_exit("hole", "/wizards/ahma/orc/forest/pond02");
  short_desc = "Inside a shimmering underwater cave";
  long_desc = "The air feels very heavy and thin in this small cave which is located\n" + 
              "several meters underwater. Somewhat bright light is luminating into the\n" +
              "room from small yellow-coloured sparkling stones located in the crude\n" +
              "walls. Two bigger stones in the center of the room seem also to emit a\n" +
              "bright yellow glow. One of the bigger stones is hanging from the ceiling\n" +
              "and the other one is standing on the floor. In the eastern part of the\n" +
              "floor is a hole from where you arrived into this cave.\n";

  items = allocate(12);
  items[0] = "stones";
  items[1] = "Two stones in the center of the room are much bigger than the others, which\n" +
             "are stuffed in the walls of this room. In the stone which is standing on the\n" +
             "ground seems to have ten holes, five on each side. In addon to the holes,\n" +
             "there seems to be some kind of a spike on the center of the stone. The stones\n" +
             "seem to pulsate simultaneously. A quiet humming can be heard coming from\n" +
             "inside of them";
  items[2] = "hole";
  if(placed == 2) { holeactive(); } else { items[3] = "Try looking at 'holes'"; }
  items[4] = "holes";
  items[5] = "Five quite small-sized holes are located on both sides of the yellow stone\n" +
             "in the center of the cave. Holes seem to be about six inch deep and they\n" +
             "are situated in line with other four holes per side. Maybe you could place\n" +
             "something in the holes";
  items[6] = "spike";
  items[7] = "The sharp, thin spike seems to be made of same material with the stones all\n" +
             "around the room. A small beam of light rises from the tip of the spike to\n" +
             "the stone above the one standing on the ground. The spike is about half a\n" +
             "feet high and it is reaching up from the very center of the yellow stone";
  items[8] = "stone";
  items[9] = "Try looking at 'stones'";
 items[10] = "stash";
 if(!stash) { items[11] = "You see nothing special"; } else { activatestash(); }
}

init() {
  ::init();
  add_action("hep", "place");
  add_action("hap", "take");
}

hep(str) {
  string what, where;
  if(!complete) {
  if(!str) { write("Place what in where?"); return 1; }
  if(sscanf(str, "%s in %s", what, where) != 2) {
    write("Place what in where?"); return 1; }
    else {
      if(what == "claws"  && where == "holes" && placed == 0) {
        if(present("claws", this_player()) && !present("claws", this_player())->query_no_save()) {
        write("You put the freak's claws in the holes on the left side of the stone.\n");
        say(this_player()->query_name() + " puts freak's claws in holes located on the left side of the stone.\n");
        destruct(present("claws", this_player()));
        placed++;
        return 1;
      }
      else {
        write("You don't have any claws.\n");
        return 1;
      }
      }
  if(what == "claws" && where == "holes" && placed == 1) {
        if(present("claws", this_player()) && !present("claws", this_player())->query_no_save()) {
        write("You put the freak's claws in the holes on the right side of the stone.\n");
        say(this_player()->query_name() + " puts freak's claws in holes located on the right side of the stone\n");
        destruct(present("claws", this_player()));
        placed++;
        call_out("clawsplaced", 3);
        return 1;
      }
      else {
        write("You don't have any claws.\n");
        return 1;
      }
    }
  if(what == "ring" && where == "spike" && placed == 2) {
    if(present("freakring", this_player()) && !present("freakring", this_player())->query_no_save()) {
    write("You put the ring in the spike and it starts falling deeper into the hole.\n");
    say(this_player()->query_name() + " places a ring in the spike and the ring starts falling deeper into the hole.\n");
    destruct(present("freakring", this_player()));
    complete = 1;
    call_out("correctring", 2);
    return 1;
  }
  else {
    write("You place the ring in the spike and it starts falling deeper into the hole.\n");
    say(this_player()->query_name() + " places a ring in the spike and the ring starts falling deeper into the hole.\n");
    move_object(present("ring", this_player()), this_object());
    call_out("wrongring", 2);
    return 1;
  }
  }
  else {
    write("Cannot place " + what + " in " + where + ".\n");
    return 1;  
  }
}
}
  else {
  write("Nothing happens.\n");
  return 1;
}
}

clawsplaced() {
  tell_room(this_object(), "When filling the second set of holes with the freaky claws, the yellow\n" +
           "light in the stones seem to get somewhat stronger. A small hole opens in\n" +
           "the base of the spike, which is standing in the very center of the stone\n" +
           "on the ground. Some yellow light is luminating into the room from the hole.\n");
  holeactive();
}

holeactive() {
  items[3] = "The hole shimmers some yellow light into its surroundings. The bottom of\n" +
             "the hole cannot be seen, but the stony spike, which is pointing straight\n" +
             "up to another stone, seems to be reaching up from somewhere deep inside the\n" +
             "hole. Maybe you could drop something into the hole by placing the item in\n" +
             "the spike which is leading deeper into the hole";
}

wrongring() {
  tell_room(this_object(), "Suddenly, the ring flies out from the hole and drops on the ground.\n" +
           "Seems, that this was not the correct item.\n");
}

correctring() {
  tell_room(this_object(), "The ring hits the ground somewhere in the hole with a soft clink. The stones\n" +
           "in the center of the room seem to light up even more when the correct object\n" +
           "has been placed inside them.\n");
  call_out("rinkula1", 5);
}

rinkula1() {
  tell_room(this_object(), "The stones start to pulsate simultaneously even more frequent than before\n" +
           "and the light-beam between the spike and the stone which is located in the\n" +
           "ceiling gets stronger. Some small tremors seem to shake the small cave-like\n" +
           "room a little.\n");
  call_out("rinkula2", 5);
}

rinkula2() {
  tell_room(this_object(), "When the yellow beam of light seems to reach its climax, it suddenly dies out.\n" +
           "The room goes dark when every other source of yellow light dies out with the\n" +
           "beam. The tremors stop and the weak humming has disappeared as well.\n");
  call_out("rinkula3", 5);
}

rinkula3() {
  tell_room(this_object(), "After a moments silence and darkness, the weak yellow shimmering begins to\n" +
            "to emit from the walls again. In the same time, a stone drops on the wall\n" +
            "from the western wall. Seems that there is some kind of a stash in the wall\n" +
            "which the stone was covering.\n");
  activatestash();
}

activatestash() {
  stash = 1;
  if(!empty) { items[11] = "A small hole seems to be carved inside the yellow stone wall. The stash\n" +
               "seems to be quite hastily-made and rarely opened. A shiny amulet is lying\n" +
               "by the rear wall of the stash"; call_out("activatestash", 2); }
  else {
    items[11] = "A small hole seems to be carved inside the yellow stone wall. The stash\n" +
                "seems to be quite hastily-made and rarely opened. The stash is empty"; }
}

hap(str) {
  if(str == "amulet from stash" || str = "amulet from the stash") {
    if(stash) {
    if(!empty) {
      write("You take the shiny amulet from the stash.\n");
      say(this_player()->query_name() + " takes something from the stash.\n");
      move_object(clone_object("/wizards/ahma/orc/eq/amulet"), this_player());
      empty++;
      activatestash();
      return 1;
    }
    else {
      write("The stash is empty.\n");
      return;
    }
  }
  else {
    return;
  }
}
  else {
    return;
  }
}
