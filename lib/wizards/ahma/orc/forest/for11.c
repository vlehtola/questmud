inherit "room/room";
int picked, purified, thrown, eventti;
object mob01, mob02, mob03, isomoko, plr, plr2, diver;
string plrname;

reset(arg) {
  add_exit("northeast", "/wizards/ahma/orc/forest/for10");
  short_desc = "On a shore of a small forest pond";
  long_desc = "The forest ends in a short-grassed green shore of a darkblue pond. A thick\n" +
              "barrier of trees is surrounding the opening. The sparkling pond creates an\n" + 
              "extraordinary scenery with the green deciduous trees surrounding it. Though\n" + 
              "so does many other forest ponds as well. A healthy-looking green bush grows\n" + 
              "on the shore near the water. A wooden sign is standing in a small hummock\n"+ 
              "near the entrance to the forest.\n";

  items = allocate(8);
  items[0] = "pond";
  if(!purified) { purifyoff(); } else { purifyon(); }
  items[2] = "sign";
  items[3] = "**DANGER** Swimming prohibited! **DANGER**\n" + 
             "Lately, the pond has been found out to be poisonous. The\n" + 
             "origin of these lethal substances are not known, but the\n" + 
             "village council believes that the reason may be the mixture\n" + 
             "of all of those things thrown into the water to feed the\n" +
             "underwater creatures. If you have some clues regarding the\n" + 
             "poisoning, please contact the village council of Nehelam or\n" + 
             "report straight to Chief Tas'gand.\n" +
             "And please, do not throw anything in the pond";
  items[4] = "bush";
  items[5] = "The green, fertile bush is growing in a shore, about one third a foot\n" + 
             "away from the water. The bush grows light red, almost pink berries. The\n" + 
             "land where the bush is growing must be very fertile because it can almost\n" + 
             "be heard as the berries grow. It seems that the part of the bush which\n" + 
             "reaches over the water grows least berries. Or maybe the fishes keep\n" +
             "somehow eating the berries as they grow";
  items[6] = "berries";
  items[7] = "Little reddish, almost pink berries look delicious. The berries grow in a\n" + 
             "fertile-looking bush, and they must be quite nourishing too. Berries spread\n" + 
             "a soft, good scent, making their essence being even more delicious and wanted";

  picked = 0;

  if(!mob01) { move_object(mob01 = clone_object("/wizards/ahma/orc/mob/frog"), this_object()); }
  if(!mob02) { move_object(mob02 = clone_object("/wizards/ahma/orc/mob/frog"), this_object()); }
  if(!mob03) { move_object(mob03 = clone_object("/wizards/ahma/orc/mob/frog"), this_object()); }
  bonusmove();
}

init() {
  ::init();
  add_action("hep", "pick");
  add_action("hap", "throw");
  add_action("pep", "dive");
  add_action("pap", "move");
  if(!random(250)) {
    tell_room(this_object(), "An Orcish ranger jumps out from the bush.\n");
    move_object(clone_object("/wizards/ahma/orc/mob/ranger"), this_object());
  }
}

hep(str) {
  if(str == "berries") {
  if(!picked) {
    write("You pick some of the delicious-looking berries from the bush.\n");
    say(this_player()->query_name() + " picks some of the berries from the bush.\n");
    move_object(clone_object("/wizards/ahma/orc/eq/berries"), this_player());
    picked = 1;
    return 1;
  }
  else {
    write("Someone has already picked some berries from the bush. You do not want to\n" + 
          "ruin the outlook of the bush by picking the rest of the berries away. You\n" + 
          "will have to wait for a moment so that the bush grows some more berries.\n");
    return 1;
  }
  }
  else {
    write("Pick what?\n");
    return 1;
  }
}

hap(str) {
  string what, where;
  if(!str) { write("Throw what in where?"); return 1; }
  if(sscanf(str, "%s in %s", what, where) != 2) {
  write("Throw what in where?\n");
  return 1;
  }

  else { 
    if(what == "toe" && (where == "water" || where == "pond")) {
    if(present("toe", this_player()) && !present("toe", this_player())->query_no_save()) {
    if(!thrown) {
      thrown++;
      plr = this_player();
      plrname = this_player()->query_name();
      write("You throw the grayish toe in the pond. Some small fish swim to look at\n" + 
            "the strange object thrown in the water, but soon scatter. The toe starts\n" + 
            "to sink.\n");
      say(this_player()->query_name() + " throws a grayish toe in the pond.\n");
      destruct(present("toe", this_player()));
      call_out("revive1", 3);
      return 1;
    }
    else {
      write("The toe sinks in the water and nothing else happens.\n");
      return 1;
    }
    }
    else {
      write("You don't have a toe.\n");
      return 1;
    }
  }

  else {
    if(what == "apple" && (where == "water" || where == "pond")) {
    if(present("apple", this_player())) {
      write("You throw the apple in the pond. Some small fish swim to look at the\n" + 
            "object thrown into the water. The fishes soon scatter from the apple,\n" + 
            "leaving it to float alone in the surface.\n");
      say(this_player()->query_name() + " throws an apple in the pond. The apple starts floating away.\n");
      destruct(present("apple", this_player()));
      return 1;
    }
    else {
      write("You don't have an apple.\n");
      return 1;
    }
  }

  else {
    if(what == "berries" && (where == "water" || where == "pond")) {
    if(present("berries", this_player())) {
      write("You throw the handful of berries into the water. A school of sparkling\n" + 
            "fish swim to the berries and eventually eat them.\n");
      say(this_player()->query_name() + " throws a handful of berries into the water. A school of sparkling\n" + 
          "fish eventually come and eat them away.\n");
      destruct(present("berries", this_player()));
      return 1;
    }
    
    else 
      write("You don't have any berries.\n");
    }
 
  else {
    if(present(what, this_player()) && (where == "water" || where == "pond")) {
    if(present(what, this_player())) {
      write("You don't want to throw " + what + " in the pond.\n");
      return 1;
    }
  }
  else { write("You don't have " + what +".\n"); return 1;}}   

}
}
}
}
pep(str) {
  if(str == "in water" || str == "in pond") {
  if(purified) {
    write("Because the sparkling blue pond looks extremely deep, you start gathering air\n" + 
          "into your lungs with long, deep breaths..\n");
    call_out("dive1", 4);
    return 1;
  }
  else {
    write("The poisonous-green surface of the forest pond scares you a bit and you start\n" + 
          "gathering some courage before jumping into the smelly water..\n");
    call_out("lethaldive", 5);
    return 1;
  }
  }
  else {
    write("Dive in where?\n");
    return 1;
  }
}

pap(str) {
  if(str == "bush") {
  if(eventti) {
  if(this_player()->query_name() == plr2->query_name()) {
    write("You move the bush a little and see an Orcish boy sitting and giggling inside it.\n");
    call_other("/wizards/ahma/orc/void", "moveboy");
    call_out("activateboy", 2);
    return 1;
  }
  else {
    write("You move the bush and see an Orcish boy sitting and giggling inside it.\n" + 
          "The boy whispers: 'Please don't tell " + plr2->query_name() + " that I'm in here, OK?\n");
    return 1;
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

purifyon() {
  purified = 1;
  items[1] = "A sparkling darkblue pond looks remarkable, but still just like any good-\n" + 
             "looking forest pond. The water is rippling slowly in the soft squalls of\n" + 
             "wind blowing in from the forest. A few small fishes can be seen glaring\n" + 
             "around near the surface of the water. You might try throwing something in\n" + 
             "the pond to feed the fishes, though you will probably never be able to\n" + 
             "catch one. The surface of the pond looks beautifully blue and pure";
}

purifyoff() {
  purified = 0;
  items[1] = "A sparkling darkblue pond looks remarkable, but still just like any good-\n" + 
             "looking forest pond. The water is rippling slowly in the soft squalls of\n" + 
             "wind blowing in from the forest. A few small fishes can be seen glaring\n" + 
             "around near the surface of the water. You might try throwing something in\n" + 
             "the pond to feed the fishes, though you will probably never be able to\n" + 
             "catch one. The surface of the pond looks suspiciously green, like poisoned";
}

revive1() { 
  tell_room(this_object(), "\nAfter the toe has disappeared from your sight, small bubbles start to rise\n" + 
                           "on the surface. The bubbling gets more intensive and suddenly, it stops.\n");
  call_out("revive2", 6);
  return 1;
}

revive2() {
  tell_room(this_object(), "\nThe water bursts in the air like something heavy would have thrown into the\n" + 
                           "pond as something jumps in the air from the greenish water. The water drops\n" + 
                           "on your shoulders in the same time as the thing which jumped from the water\n" + 
                           "lands on the ground on front of you.\n");
  if(!plr->query_quests("Discover the pond's secret")) {
    tell_object(plr, "You completed the quest 'Discover the pond's secret'\n");
    plr->set_quest("Discover the pond's secret");
  }
  else {
    tell_object(plr, "You have already completed this quest.\n");
  }
  isomoko = clone_object("/wizards/ahma/orc/mob/freak");
  move_object(isomoko, this_object());
  call_out("revive3", 10);
  return 1;
}

revive3() {
  tell_room(this_object(), "\nA freaky-looking creature stands on front of you. It slowly moves its fingers\n" + 
                           "like pondering what to do next. Suddenly, it raises its ugly hands in the air\n" + 
                           "and some blades pierce its skin from the tips of its fingers. The freak screams\n" + 
                           "both in pain and in anger, it seems to be up for a battle.\n");
  call_out("revive4", 10);
  return 1;
}

revive4() {
  if(!present(plrname, this_object())) return 1;
  tell_room(this_object(), "\nThe freak attacks " + plrname + " furiously.\n");
  present("freak", this_object())->attack_object(plr);
  return 1;
}

bonusmove() {
  if(!random(20)) {
    if(present("frog", this_object())) {
    destruct(present("frog", this_object()));
    tell_room(this_object(), "Frog jumps into the pond and disappears under the surface.\n");
    }
  }
  call_out("bonusmove", 30);
}

setevent() {
  eventti = 1;
}

boyevent(ob) {
  plr2 = ob;
  if(eventti) {
  if(!random(15)) {
  if(present(lower_case(plr2->query_name()), this_object())) {
    tell_room(this_object(), "Something moves in the bush.\n");
  }
  else {
    tell_room(this_object(), "Little boy whispers from the bush: Don't tell " + plr2->query_name() + " that I'm here, OK?\n");
  }
  }
  call_out("boyevent", 2, plr2);
  }
}

activateboy() {
  if(present("boy", this_object())) {
    present("boy", this_object())->complete4();
    eventti = 0;
  }
}

lethaldive() {
  if(this_player()->query_current_room() == "/wizards/ahma/orc/forest/for11") {
  write("\nAfter gathering some courage you take few steps back from the shore and start\n" + 
        "running towards the pond. The moment you hit the water, the poison starts burning\n" + 
        "your skin. Your limbs go into paralyzed state and you start sinking to your death.\n");
  say(this_player()->query_name() + " jumps into the poisonous-green pond and starts screaming in pain.\n");
  call_out("makeharm", 2);
  /*this_player()->move_player("pond#/wizards/ahma/orc/forest/pond01.c");*/
  call_other("/wizards/ahma/orc/forest/pond01", "badlong");
  move_object(this_player(), "/wizards/ahma/orc/forest/pond01");
  }
}

makeharm() {
  if(this_player()->query_current_room() == "/wizards/ahma/orc/forest/pond01") {
  write("\nThe poison burns your skin, making unbelievable pain.\n");
  this_player()->hit_with_spell(500);
  if((this_player()->query_hp()) < 500) {
    write("\nWith the last wisps of conscience you feel something grabbing from your foot\n" + 
          "and pulling you even deeper into the toxic-pond.\n");
  }
  call_out("makeharm", 3);
 }
}

dive1() {
  write("\nAfter you think you have stocked enough air to reach your goal in the pond you\n" + 
        "take few steps back from the shore and start running towards the water.\n");
  call_out("dive2", 3);
}

dive2() {
  say(this_player()->query_name() + " dives into the sparkling pond.\n");
  /*this_player()->move_player("X#/wizards/ahma/orc/forest/pond01.c");*/
  call_other("/wizards/ahma/orc/forest/pond01", "goodlong");
  move_object(this_player(), "/wizards/ahma/orc/forest/pond01");
  write("\nYou make your way through the layer of dead fish floating on the surface and dive\n" + 
        "deeper into the sparkling forest pond.\n");
  call_other("/wizards/ahma/orc/forest/pond02", "checkshell");
  call_out("dive3", 4);
}

dive3() {
  write("\nAfter a moments dive you spot a cave-like hole near the bottom of the pond.\n" + 
        "You head towards it.\n");
  call_out("dive4", 3);
}

dive4() {
  write("\nYou have still about 10 meters to go for the cave entrance when you notice that\n" +
        "two extremely ugly and hostile-looking seashells are blocking your way into the cave.\n" +
        "The seashells are glaring at you angrily.\n");
  call_out("dive5", 5);
}

dive5() {
  write("\nYour lungs are beginning to feel empty. You will have to deal with the seashells\n" +
        "quickly before losing your consciousness. The seashells attack you.\n");
  /*this_player()->move_player("X#/wizards/ahma/orc/forest/pond02.c");*/
  move_object(this_player(), "/wizards/ahma/orc/forest/pond02");
}

comingup(ob) {
  say(ob->query_name() + " jumps out from the pond, coughing maniacally and gasping for air.\n");
  write("\nYou climb up from the pond coughing maniacally and gasping for air into your empty lungs.\n");
}
