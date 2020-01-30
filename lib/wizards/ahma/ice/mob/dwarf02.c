inherit "obj/monster";
string plr, chat_str, item;
object ob;
int i;

reset(arg) {
  string a_chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(16);
  set_name("serak");
  set_race("dwarf");
  set_gender(1);
  set_short("Serak, the puny-looking Dwarf");
  set_long("Serak is a small and weak-looking Dwarf. He is wearing a thick, furry\n" +
           "clothes which efficiently prevent the cold from piercing itself under\n" +
           "the fragile skin of this Dwarven man. Serak looks somehow scornful as\n" +
           "he glares at you with frowned eyebrows. The brown leather clothes\n" +
           "cover his body thoroughly.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
      chat_str[0] = "Serak grunts: 'I hate my neighbor's pet wolverine, it's always trying to kill Cuong.'\n";
      chat_str[1] = "Serak winks: 'I would be grateful if someone would kill that little bastard.'\n";
      chat_str[2] = "Serak says: 'I like Harald, he's my best neighbor.'\n";
  }
  if(!a_chat_str) {
    a_chat_str = allocate(2);
    a_chat_str[0] = "Serak shouts: 'You will pay for this!'\n";
    a_chat_str[1] = "Serak screams: 'You messed with a wrong Dwarf today!'\n";
  }
  
  load_chat(4, chat_str);
  load_a_chat(10, chat_str);
  set_resists("cold", 8);
  if(i) environment(this_object())->setspec();

  move_object(clone_object("/wizards/ahma/ice/eq/lcap"), this_object()); init_command("wear cap");
  move_object(clone_object("/wizards/ahma/ice/eq/ljacket"), this_object()); init_command("wear jacket");
  move_object(clone_object("/wizards/ahma/ice/eq/lpants"), this_object()); init_command("wear pants");
  move_object(clone_object("/wizards/ahma/ice/eq/lshoes"), this_object()); init_command("wear slippers");
  move_object(clone_object("/wizards/ahma/ice/eq/lgloves"), this_object()); init_command("wear mittens");
}

catch_tell(str) {
  if(sscanf(str, "%s gives %s to you.", plr, item) == 2) {
    if(present("tail 2")) {
      say("Serak says: 'There must be some kind of a mistake, I already have a tail.'\n");
      return 1;
    }
    if(!present("tail", this_object()) || present("tail", this_object())->query_no_save()) return;
    ob = find_player(lower_case(plr));
    say("Serak thanks: 'Thank you so much " + ob->query_name() + "! Now my pet is safe again.'\n");
    if(this_player()->query_quests("Performing the dirty work for Serak")) {
      tell_object(this_player(), "You have already completed this quest before.\n");
    }
    else {
      ob->set_quest("Performing the dirty work for Serak");
      tell_object(ob, "Congratulations! You have completed the quest 'Performing the dirty work for Serak'\n");
    }
    call_other("/wizards/ahma/ice/rooms/nest06", "notails");
    destruct(present("tail", this_object()));
    i = 1;
    specsay();
    return 1;
  }
}

specsay() {
  chat_str[0] = "Serak says: 'At last my beloved pet mink doesn't have to fear any more.'\n";
  chat_str[1] = "Serak says: 'Harald is very polite man. I would like to be just like him.'\n";
}
