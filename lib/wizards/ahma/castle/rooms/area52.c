inherit "room/room";
object spec, ob;
int i, jumpactive;

reset(arg) {
  add_exit("down", "/wizards/ahma/castle/rooms/area51");
  add_exit("portal", "/wizards/manta/hill/room10");
  short_desc = "On the top of the tower";
  long_desc =  "The roof of the tower.\n" + 
               "A beautiful sight opens in front of your eyes. The whole underground\n" + 
               "opening can be seen from here. You are at the northern end of the room,\n" + 
               "looking straight to the south. In the very northwestern end you can see\n" + 
               "a little black spot, which is the opening of the hole from which you came\n" + 
               "through this very place. A bit to the east from the hole mouth, there is\n" + 
               "the pulsating, glowing hill. The spirits of the soldiers who were killed\n" + 
               "in the attack to the castle Lhavorak can be seen floating above the hill,\n" + 
               "disappering through the ceiling, on their way to the better plains. The\n" + 
               "geysirs can be heard and seen again. Their sighs and groans do not sound\n" + 
               "so desperate anymore, but full of pride and joy. The north-eastern corner\n" +
               "consist of a barred cave, which probably leads deeper into the realm of\n" + 
               "Hell. A way below the tower you can see the softly moving red, dream-like\n" + 
               "mass. Somehow it seems to attract you. A magical portal is located in the\n" +
               "very center of the opening.\n";

  set_not_out(1);
  property = ({"no_kill", "no_skill", "no_spell", "no_summon"});

  items = allocate(2);
  items[0] = "portal";
  items[1] = "A portal shining in light blue glow. It is ellipse-shaped and some white\n" + 
             "particles of energy move inside the sphere. There are no signs in sight,\n" + 
             "which would give a clue, where this portal will teleport the one who enters\n" + 
             "it. You have a strange feeling that you have seen a portal alike somewhere\n" + 
             "else before";
    
  call_out("hopo", 2);
/*  if(!spec) {
    spec = clone_object("/wizards/ahma/castle/mob/spec04");
    move_object(spec, this_object());
  }*/
}

init() {
  ::init();
  add_action("jump", "jump");
}

jump(str) {
  if(str == "down") {
  if(!this_player()->query_quests("The death prevails")) {
  if(!jumpactive) {
  ob = this_player();
  write("You step on the edge of the tower. With your inner voice making you crazy\n" + 
        "you have no other option but - just - let - go. You close your eyes and lean\n" + 
        "forward. You start falling..\n");
  move_object(this_player(), "/wizards/ahma/castle/rooms/area52b");
  jumpactive = 1;
  call_out("jump01", 12);
  return 1;
  }
  else {
  write("You see " + ob->query_name() + " falling down and have to wait for your turn.\n");
  return 1;
  }
  }
  else {
  write("You have already completed the quest 'The death prevails'.\n");
  return 1;
  }
  }
  else {
  write("Where to jump?\n");
  return 1;
  }
}

jump01() {
  write("You are moving down with an incredible speed. The tower just sweeps past your\n" + 
        "eyes in a few seconds. At least you do not hear the voices any more. Suddenly a\n" +
        "question pops in your mind: Was this such a good idea after all?\n\n");
  call_out("jump02", 7);
  return 1;
}

jump02() {
  write("You fell past the glowing roads few seconds ago, and the melting materia closes\n" + 
        "in at every tenth of second. Your worries are gone. You are feeling relaxed and\n" + 
        "ready to face anything what might happen to you after you hit the melting ground.\n\n");
  call_out("jump03", 7);
  return 1;
}

jump03() {
  write("The ground is closing in fast. You have a feeling that you will hit it in\n" + 
        "seconds now. You do not think about anything, just relax yourself as well as\n" + 
        "you are able at this moment. The air starts to feel very warm when falling the\n" + 
        "last twenty meters. In the end, you close your eyes.\n\n");
  call_out("jump04", 7);
  return 1;
}

jump04() {
  write("You start screaming hysterically.\n");
  this_player()->set_quest("The death prevails");
  call_out("jump05", 3);
}

jump05() {
  jumpactive = 0;
  ob->death();
}

hopo() {
  if(!random(17)) {
  i = random(8);
  if(i==0) { tell_room(this_object(), "A voice in your head: 'What is the value of life?'\n"); }
  if(i==1) { tell_room(this_object(), "A voice in your head: 'You can discover new things about you if you jump.'\n"); }
  if(i==2) { tell_room(this_object(), "A voice in your head: 'Can you see the truth?'\n"); }
  if(i==3) { tell_room(this_object(), "A voice in your head: 'The life is worthless without new experiences.'\n"); }
  if(i==4) { tell_room(this_object(), "A voice in your head: 'Death is the plane of victory.'\n"); }
  if(i==5) { tell_room(this_object(), "A voice in your head: 'The meaning of life? No, life has no meaning.'\n"); }
  if(i==6) { tell_room(this_object(), "A voice in your head: 'Who wants to stop you? You have no one so dear.'\n"); }
  if(i==7) { tell_room(this_object(), "A voice in your head: 'The gates are open, open for you.'\n"); }
  }
  call_out("hopo", 2);
}
