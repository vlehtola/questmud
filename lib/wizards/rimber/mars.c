inherit "obj/monster";
int sit, down;

reset(arg) {
        sit = 0;
        down = 0;
	::reset(arg);
	if(arg) return;
        set_level(70);
        set_name("mars");
	set_short("Rimber's dobermann called Mars");
	set_alt_name("dog");
	set_alias("mars");
	set_long("Black dobermann.\n");
	set_race("animal");
	set_gender(1);
}

catch_tell(str) {
 object ob, tgt;
 string dir, tmp, tmp2;
 if(sscanf(str, "Rimber says '%s'", tmp2) == 1) {
  if(tmp2 == "istu") {
   say("Mars sits down.\n");
   sit = 1;
  }
 if(tmp2 == "kuole") {
  say("Mars plays dead.\n");
   }
 if(tmp2 == "anna tassu") {
   say("Mars rises his paw toward Rimber.\n");
   }
 if(tmp2 == "irti") {
  this_object()->stop_fight();
  }
  if(tmp2 == "seuraa") {
   if(sit == 1 || down == 1) {
    say("Mars stands up.\n");
    sit = 0;
    down = 0;
   }
  }
  if(tmp2 == "paikka") { say("Mars sits down.\n");
  down = 1;
 }
  if(tmp2 == "maahan"){
   say("Mars lays down.\n");
   down = 1;
  }
 }
 if(sscanf(str,"Rimber points at %s.", tmp2) == 1) {
  tgt = present(lower_case(tmp2), environment(this_object()));
 attack_object(tgt);
 }
 if(sscanf(str,"%s leaves %s",tmp,dir) == 2) {
   ob = find_player(lower_case(tmp));
   if(!ob) { return; }
    if(tmp == "rimber" || tmp == "Rimber") {
    if(down == 1) return;
     call_out("move_to",1,ob);
  say("Mars walks after his master.\n");
  }
 }
}

move_to(ob) {
 move_player("after " + ob->query_name(), environment(ob));
}
