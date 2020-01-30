inherit "obj/monster";

reset(arg) {
	object weapon;
        string chat_str;
	::reset(arg);
	if(arg) return;
        set_level(38);
	set_short("Dark dweller called Sneek");
	set_name("Dark dweller called Sneek");
	set_alt_name("dweller");
	set_alias("sneek");
	set_long("Sneek has light brown eyes and almost black skin.\n"+
                 "His appearance is freakish. There seems to be jewels\n"+
                 "hanging almost all around his body, and paintings\n"+
              "decorate all of the bare parts.\n"+
  "His both ears have been pierced more than five times\n"+
  "and he has a big wooden hook hanging from his nose.\n");
	set_race("human");
	set_skill("kick", 100);
	set_gender(1);
        weapon = clone_object("/wizards/rimber/cave/obj/club.c");
	move_object(weapon, this_object());
	init_command("wield club");
	if(!chat_str) {
		chat_str = allocate(2);
                chat_str[0] = "Sneek says: 'Well, well! What do we have here?'\n";
                chat_str[1] = "Sneek hums some familiar tune.\n";
	}
        load_chat(3, chat_str);
}

ask_question(str) {
        if(str == "permission") {
          say("Sneek says: 'A permission to finish Gunthar's map? Well, you'll have to prove yourself first.'\n");
          return 1;
        }
	if(str == "prove") {
          say("Sneek says: 'You'll have to do one simple task.'\n");
	  return 1;
	}
	if(str == "task") {
         say("Sneek says: 'I lost my earring when I was refreshing myself.\n"+
              "             Find it and you'll get what you want.'\n");
	  return 1;
	}
	if(str == "shaman") {
          say("Sneek says: 'He was mad. I'm surprised he got this far.'\n");
	  return 1;
	}
	if(str == "maze") {
 say("Sneek says: 'The maze is to protect our king. No-one will survive through it.'\n");
	  return 1;
	}
	if(str == "gunthar") {
 say("Sneek says: 'Our king doesn't like him. That's why Gunthar sent you to ask for the permission. But to get that you'll have to do something for me.'\n");
          return 1;
        }
	if(str == "map") {
	  say("Sneek shrugs and says: 'I don't know what Gunthar has done but he is bad writer.'\n");
	  return 1;
	}
        say("Sneek looks puzzled.\n");
        return 1;
}

catch_tell(str) {
 object ob, letter, kirje;
 string filu, tmp, tmp2;
 int id;
  if(sscanf(str, "%s gives %s to you.",tmp,tmp2) == 2) {
   ob = present("earring", this_object());
   if(ob) {
   if(sscanf(file_name(ob),"%s#%d",filu,id) == 2) {
    if(filu == "/wizards/rimber/cave/obj/earring") {
      kirje = clone_object("/wizards/rimber/cave/obj/letter.c");
     say("Sneek says: 'You found it? Great! Here, I keep my promise.'\n");
    this_player()->set_quest("Find Sneek's missing earring");
     write("Sneek gives you a letter.\n");
     destruct(ob);
     move_object(kirje, this_player());
     return 1;
  }
 }
}
}
}
