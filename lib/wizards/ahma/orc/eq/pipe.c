inherit "obj/weapon";
int dizzy, i, loaded, weed, grass;

start() {
  set_class(1);
  set_sub_type("club");
  set_name("pipe");
  set_short("A simple wooden pipe");
  set_long("Various different kinds of pipes are commonly used by elderly creatures\n" +
           "all around the realm. Pipes are used to ember and inhale different types\n" +
           "of weeds and grass, some of which are very dangerous to their smoker's\n" +
           "health. The pipe consists of two parts: a base is the area where the\n" +
           "weeds or grass is supposed to be loaded, and the actual pipe is the part\n" +
           "where different smokes are inhaled into smoker's respiratory organs.\n");

  if(dizzy) { call_out("init", 1); }
}

init() {
  ::init();
  add_action("diz", "north");
  add_action("diz", "south");
  add_action("diz", "west");
  add_action("diz", "east");
  add_action("diz", "northwest");
  add_action("diz", "northeast");
  add_action("diz", "southwest");
  add_action("diz", "southeast");
  add_action("diz", "enter");
  add_action("diz", "out");
  add_action("diz", "stairs");
  add_action("diz", "ladder");
  add_action("diz", "ladders");
  add_action("load", "load");
  add_action("load", "stuff");
  add_action("smoke", "smoke");
  add_action("smoke", "inhale");
  add_action("look", "look");
  add_action("peep", "drop");
//  add_action("peep", "give");
  if(dizzy) {
    call_out("start", 1);
    dizzy--;
    if(!random(12)) {
      i = random(7);
      if(i == 0) {
        write("You feel your head spinning wildly.\n");
        say(environment()->query_name() + " spins " + environment()->query_possessive() + " head wildly.\n");
        return 1;
      }
      if(i == 1) {
        write("You roll your eyes around the room but do not understand anything you see.\n");
        say(environment()->query_name() + " rolls " + environment()->query_possessive() + " eyes around the room.\n");
        return 1;
      }
      if(i == 2) {
        write("You feel like being somewhere else than you actually are.\n");
        say(environment()->query_name() + " seems to be somewhere very far away from here.\n");
        return 1;
      }
      if(i == 3) {
        write("You pat yourself on the head and laugh insanely.\n");
        if(environment()->query_possessive() == "his") {
        say(environment()->query_name() + " pats himself on the head and laughs insanely.\n");
        }
        else {
        say(environment()->query_name() + " herself on the head and laughs  insanely.\n");
        }
        return 1;
      }
      if(i == 4) {
        write("You try to imitate a monkey by clapping your hands and jumping in the air.\n");
        say(environment()->query_name() + " tries to imitate a monkey by clapping " + environment()->query_possessive() + " hands and jumping in the air.\n");
        return 1;
      }
      if(i == 5) {
        write("You leer your surroundings eyes half-close.\n");
        say(environment()->query_name() + " leers at " + environment()->query_possessive() + " surroundings eyes half-close.\n");
        return 1;
      }
      if(i == 6) {
        write("You feel extremely relaxed and suddenly something flows down on your thigh.\n");
        say(environment()->query_name() + " looks extremely relaxed and suddenly something flows on the ground from " + environment()->query_possessive() + " pantleg.\n");
        return 1;
      }
    }
  if(dizzy == 4) {
    write("You feel your head getting clearer.\n");
    return 1;
  }
  if(dizzy == 0) {
    write("You feel being back to normal again.\n");
    say(environment()->query_name() + " seems to be back to normal again.\n");
    return 1;
  }
  }
}

look(str) {
  if(str == "at base" && weed) {
    write("The surroundings of a hollow base are already started to blacken due to the\n" +
          "intensive usage of this pipe. Different kinds of weeds and grasses are to be\n" +
          "loaded into the base before smoking the pipe. The base is currently loaded\n" +
          "with yellowish weeds.\n");
    return 1;
  }
  if(str == "at base" && grass) {
    write("The surroundings of a hollow base are already started to blacken due to the\n" +
          "intensive usage of this pipe. Different kinds of weeds and grasses are to be\n" +
          "loaded into the base before smoking the pipe. The base is currently loaded\n" +
          "with green grass.\n");
    return 1;
  }
  if(str == "at base" && !grass && !weed) {
    write("The surroundings of a hollow base are already started to blacken due to the\n" +
          "intensive usage of this pipe. Different kinds of weeds and grasses are to be\n" +
          "loaded into the base before smoking the pipe. The base is currently empty.\n");
    return 1;
  }
  else {
    return;
  }
} 

diz() {
  if(dizzy) {
    if(!random(2)) {
      i = random(5);
      if(i == 0) {
      write("You try walk, but stumble on your feet and almost fall down.\n");
      say(environment()->query_name() + " tries to move around, but stumbles on " + environment()->query_possessive() + " feet and almost falls down.\n");
      return 1;
      }
      if(i == 1) {
      write("You start walking, but stumble in another direction that your intention was.\n");
      say(environment()->query_name() + " starts walking, but stumbles in another direction where " + environment()->query_possessive() + " intention was.\n");
      /*environment()->set_move_at_random(1);
      call_out("calm", 2);*/
      return 1;
      }
      if(i == 2) {
      write("You begin to move, but fall backwards on the ground. The pain clears your head a bit.\n");
      environment()->hit_with_spell(30 + random(31));
      say(environment()->query_name() + " begins to move, but falls backwards on the ground.\n");
      if(dizzy > 10) { dizzy = (dizzy - 9); }
      return 1;
      }
      if(i == 3) {
      write("You do not remember how to walk any more and stand still in one spot, thinking.\n");
      say(environment()->query_name() + " stands in one spot and seems to try to recall how to walk again.\n");
      return 1;
      }
      if(i == 4) {
      write("Two humongous pink elements block your way.\n");
      say(environment()->query_name() + " slashes maniacally air with " + environment()->query_possessive() + " hands, like there would be something threatening.\n");
      return 1;
      }
    }
  else { return; }
  }
  else { return; }
}

/*calm() {
  environment()->set_move_at_random(0);
}*/

load(str) {
  if(str == "grass in base" || str == "base with grass" || str == "pipe with grass" || str == "grass in pipe") {
    if(!loaded) {
      if(present("grass", environment())) {
      destruct(present("grass", environment()));
      write("You load some grass in the base of the pipe.\n");
      say(environment()->query_name() + " loads " + environment()->query_possessive() + " pipe's base with some grass.\n");
      loaded++;
      grass = 2;
      return 1;
    }
    else {
      write("You don't have any grass.\n");
      return 1;
    }
    }
    else {
      write("The base is already loaded.\n");
      return 1;
    }
    }
  if(str == "weed in base" || str == "base with weed" || str == "pipe with weed" || str == "weed in pipe") {
    if(!loaded) {
      if(present("weed", environment())) {
      destruct(present("weed", environment()));
      write("You load some weed in the base of the pipe.\n");
      say(environment()->query_name() + " loads " + environment()->query_possessive() + " pipe's base with some weed.\n");
      loaded++;
      weed = 2;
      return 1;
    }
    else {
      write("You don't have any weed.\n");
      return 1;
    }
    }
    else {
      write("The base is already loaded.\n");
      return 1;
    }
  }
}

smoke(str) {
  if(str == "pipe") {
    if(grass) {
      write("You take a long inhale of the ember of green grass in the pipe's base.\n" +
            "You feel something in your head.\n");
      say(environment()->query_name() + " takes a long inhale from the pipe.\n");
      dizzy = dizzy + 50;
      grass--;
      if(!grass) { loaded = 0; }
      start();
      return 1;
    }
    if(weed) {
      write("You take a long inhale of the ember of yellowish weed in the pipe's base.\n" +
            "You feel your head spinning.\n");
      say(environment()->query_name() + " takes a long inhale from the pipe.\n");
      dizzy = dizzy + 70;
      weed--;
      if(!weed) { loaded = 0; }
      start();
      return 1;
    }
  }
}

/*peep() {
  write("You can't think anything that complicated just now.\n");
  return 1;
}*/
