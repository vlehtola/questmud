inherit "obj/monster";
reset(arg) {
  object eq,eq2,eq3,eq4;
  string chat_str;
  ::reset(arg);
  if(arg) return;
  set_level(99);
  set_gender(1);
  set_log(1);
  set_name("anrax");
  set_alias("guildmaster");
  set_short("Anrax, the fighter's guildmaster");
  set_long(
"Anrax is dressed into leather and wears a chain mail. His muscular body\n"+
"dominates the nearby location. He is here to train new fighters for\n"+
"incoming battles.\n");
  set_race("human");
  chat_str = allocate(6);
  chat_str[0] = "Anrax says 'New fighters should seek easy opponents in the ant mine south of the city.'\n";
  chat_str[1] = "Anrax says 'You need to be a true fighter to enter the weapon master training area.'\n";
  chat_str[2] = "Anrax states 'Punch is useful if you don't have shield nor two weapons.'\n";
  chat_str[3] = "Anrax flexes his muscles and grins 'Train hard and one day you might be as good as I am.'\n";
  chat_str[4] = "Anrax says 'Check out our supply stores in south at the warrior guildroom.'\n";
  chat_str[5] = "Anrax gives some advice 'Get a weapon from the rack south from here.'\n";
  load_chat(5, chat_str);
}

jees() {
  if(this_player()->query_skills("attack") < 50 ||
	this_player()->query_level() < 40) {
    tell_object(this_player(),
	"Anrax blocks your way and says: 'You are not worthy to pass.'\n");
    say("Anrax stops "+this_player()->query_name()+" when "+
	this_player()->query_pronoun()+" attempts to go upstairs.\n",this_player());
    return 1;
  } else {
    return 0;
  }
}

init() {
  ::init();
  add_action("jees", "up");
}

catch_tell(str) {
  string tmp,tmp2;
  object ob;
  ::catch_tell(str);
  if(str && sscanf(str, "%s is in vigorous combat with %s.",tmp,tmp2)==2) {
    if(tmp != "Guard") {
      ob = present(tmp, environment(this_object()));
      if(!ob) return;
      say(query_name()+" gets mad on "+tmp+"'s hostile actions!\n");
      attack_object(ob);
    }
  }
}

