inherit "obj/monster";
int done;
object ob;
string plr, what, whom;

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3) + 15);
  set_name("bum");
  set_alias("man");
  set_short("A sobbing Ogre bum");
  set_gender(1);
  set_race("ogre");
  set_long("This fat bum seems to be drunk enough to pass out. His eyes are half-\n" + 
           "closed and he stinks of pure booze. The man is mumbling some nutty words\n" + 
           "to himself as he sits on a wooden crate. The ogre is wearing a torn gray\n" + 
           "shirt and torn pants. They are covered with puke and some other substances\n" + 
           "you do not even want to know about.\n");

  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Bum tries to say something but manages only to spit some slime on the floor.\n";
    chat_str[1] = "Bum mumbles: 'I am far away from home. Oh, how I miss that fortress.\n";
    if(!done) { chat_str[2] = "Bum asks: 'Psst, can you bring me a dress of a beautiful woman from my former home?'\n"; }
    else { chat_str[2] = "Bum strokes a beautiful pink dress in his hands"; }
  }
  load_chat(3, chat_str);
  set_al(20);
}

catch_tell(str) {

  if(sscanf(str, "%s gives %s to %s", plr, what) == 2) {
    ob = find_player(lower_case(plr));
    if(done) { completealready(); return; }
    if(!present("alias_to_make_cheating_impossible", this_object())) { wrongitem(); return; }
    questcomplete();
    return;
  }
}

questcomplete() {
  say("Bum says: 'Oooh, thank you so much! Here, take these coins.'\n");
  ob->add_money(100 + random(51));
  ob->add_exp(1000000 + random(500001));
  done = 1;
  environment(this_object())->task_complete();
  return;
}

completealready() {
  say("Bum smiles: 'Thank you very much, but I already have what I wanted. You can have this back.'\n");
  move_object(present(what, this_object()), ob);
  tell_object(ob, "Bum gives " + what + " to you.\n");
  say("Bum gives " + what + " to " + ob->query_name() + ".\n", ob);
  return;
}

wrongitem() {
  say("Bum says: 'No, I don't think this is the item I wanted. You can have this back.\n");
  tell_object(ob, "Bum gives " + what + " to you.\n");
  say("Bum gives " + what + " to " + ob->query_name() + ".\n", ob);
  move_object(present(what, this_object()), ob);
  return;
}

task_complete() {
  done = 1;
}
