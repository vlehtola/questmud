inherit "obj/weapon";
int i, chanted;
string words;

start() {
  set_class(5);
  set_sub_type("club");
  set_name("wand");
  set_short("Wand of Wonders");
  set_long("Cranked wooden magic wand. This almost sarcastically ugly wand is absolutely\n" + 
           "one of the weakest magic wands ever made. It is made from a branch quickly\n" + 
           "torn off from a normal tree in a normal forest. A weak magic enchantment has\n" + 
           "been laid on the wand, but still, the magicks it can accomplish are very, very\n" + 
           "weak. The wand sizzles softly and some energy particles fly out from its tip\n" + 
           "when you shake it. Maybe you could spell something out from the wand with a\n" + 
           "correct chant. Some words are carved on the base of this small wand.\n");
           
  i = random(5);
  if(i==0) { words = "the wealth awaits"; }
  if(i==1) { words = "shall there be light"; }
  if(i==2) { words = "death to the chanter"; }
  if(i==3) { words = "the weaponus ultimatum"; }
  if(i==4) { words = "trrr kll krats"; }

}

init() {
  ::init();
  add_action("words", "read");
  add_action("chant", "chant");
}

words(str) {
  if(str == "words") {
    write("'Chant '" + words + "' to activate the spirit within.'\n");
    return 1;
  }
  else {
    write("Read what?\n");
    return 1;
  }
}

chant(str) {
  object item;
  if(str == words) {
    if(!chanted) {
    if(wielded_by) {  
    if(wielded_by->query_current_room() == "/world/city/inn") { write("You cannot operate the wand in the inn.\n"); return 1; }
    write("The wand starts to sizzle wildly as you chant the magical words.\n");
    if(i==0) { 
        write("Something appears on the ground.\n"); 
        say(wielded_by->query_name() + " chants the magic words '" + words + "'.\nSomething appears on the ground.\n");
        move_object(clone_object("/wizards/ahma/castle/eq/crap1"), environment(this_player()));
      } 
      if(i == 1) {
        move_object(clone_object("/world/eq/lantern"), environment(this_player()));
        say(wielded_by->query_name() + " chants the magic words '" + words + "'.\nSomething appears on the ground.\n");
        write("Something appears on the ground.\n");
      }
      if(i == 2) {
        move_object(clone_object("/wizards/ahma/castle/mob/mob07"), environment(this_player()));
        say(wielded_by->query_name() + " chants the magic words '" + words + "'.\nSomething appears on the ground.\n");
        write("Something appears on the ground.\n");
      }
      if(i == 3) {
        move_object(clone_object("/wizards/ahma/castle/eq/crap2"), environment(this_player()));
        say(wielded_by->query_name() + " chants the magic words '" + words + "'.\nSomething appears on the ground.\n");
        write("Something appears on the ground.\n");
      }
      if(i == 4) { 
      write("The wand cracks and breaks.\n");
      destruct(this_object());
      }
      chanted = 1;
      return 1;
    }
    else { write("The wand must be wielded to release its inner powers.\n"); return 1;}
  }
  else { write("The wand's power is already used up.\n"); return 1; }
  }
}

test() {
  return environment(wielded_by); }