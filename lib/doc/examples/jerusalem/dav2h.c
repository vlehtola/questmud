inherit "room/room";

int giggle,savettu;
object monster,monster2,masteriukko;

reset(arg) {
  if(!monster) {
    if (giggle != 21) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/boona");
    move_object(monster, this_object());
    giggle = 21;
    }
   }
  if(!monster2) {
    monster2 = clone_object("/wizards/nalle/jerusalem/monsters/crow2");
    move_object(monster2, this_object());
  }
  if(arg) return;
  add_exit("down","wizards/nalle/jerusalem/dav2g");
  short_desc = "At the top of the Tower";
  long_desc =
"You have entered a large room, completely stripped\n" +
"of all luxuries. There is however a small bed in one\n" +
"corner of the room, to which a young lady has been tied.\n" +
"A familiar looking crow is hopping around her.\n";
}

init() {
    ::init();
   add_action("untie", "untie");
   add_action("untie", "release");
}

untie() {
  object ob;
  ob = present("crow", environment(this_player()));
  if (savettu == 21) { return 0; }
  savettu = 21;
  if(!ob) {
    call_out("jeejee", 1);
    return 1;
  }
  call_out("jee", 1);
  destruct(ob);
  return 1;
}

jee() {
 write("Just as you release the lady, in a small puff of smoke the crow transforms itself into a man.\n");
 say("Just as "+ this_player()->query_name()+ " releases the lady, the crow transforms itself into a man.\n");
 masteriukko = clone_object("/wizards/nalle/jerusalem/monsters/davmaster.c");
 move_object(masteriukko, this_object());
 write("The Man shouts 'You betrayed me my lady!' and sets the lady afire with a word of magic.\n");  
 say("The Man shouts 'You betrayed me my lady!' and sets the lady afire with a word of magic.\n");  
 destruct(monster);
  return 1;
}

jeejee() {
  write("You release the lady from her bonds.\n");
  say(this_player()->query_name()+" releases the lady from her bonds.\n");
  write("The lady says 'Thank you ever so much "+ this_player()->query_name()+", now I do not"+    
  " have to marry that evil man!'\n");
  say("The lady says 'Thank you ever so much "+ this_player()->query_name()+", now I do not"+     
  " have to marry that evil man!'\n");
  if (!this_player()->query_quests("Release a lady in David's Tower")) {
   tell_object(this_player(), "You complete the David's Tower quest.\n");
   call_other(this_player(), "set_quest", "Release a lady in David's Tower");
  } else { tell_object(this_player(), "You had already completed the David's Tower quest.\n"); }
   destruct(monster);
   return 1;
}
