inherit "obj/monster";
mapping signs;

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    set_level(100);
    set_name("master");
    set_short("The master of wars");
    set_long("An extremely strong looking human who is known\n"+
             "as the master of wars all around the world.\n"+
             "He is holding a sign that reads: 'Type 'join'\n"+
             "to sign up into the war or type 'check' to see\n"+
             "who has already joined.\n");
    set_al(0);
    set_aggressive(0);
    set_log();

    signs = ([ ]);
}

init() {
  ::init();
add_action("join","join");
add_action("check","check");
}

join() {

  if(!signs[this_player()->query_name()]) {
   write("You join the event");
     shout("Master shouts: '"+this_player()->query_name()+" has joined the war!'\n");
     signs += ([this_player()->query_name(): (int)1]);
     this_player()->move_player("war#/wizards/jenny/events/battle/entrance.c");
   }
  else {
        tell_object(this_player(),"Master says: 'But you have already joined dummy!'\n");
}
return 1;
}

check() {
  string *joins;
  int i, koko;
  if(!signs) {
        write("Master tells you: 'No one has joined yet.'\n");
        return 1;
  }

  write("Master tells you: 'These players have already joined:\n");

  joins = m_indices(signs);
  koko = m_sizeof(signs);
  for( i=0; i<koko;i++) {
        write(joins[i]+"\n");
  }
  return 1;
}
