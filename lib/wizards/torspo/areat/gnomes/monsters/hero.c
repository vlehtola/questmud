inherit "obj/monster";

 status q;
reset(arg) {
 string chat_str;
 object armour, armour2, weapon;
  ::reset(arg);
  if(arg) { return; }
 q = 0;
  set_level(21);
  set_race("gnome");
  set_name("lalli");
  set_alias("hero");
  set_gender(1);
  set_short("Lalli, the gnomish hero");
  set_long("This gnome seems to be a lot bigger than his mates. His rough, brown skin\n"+
           "is covered with scars. The long muscular arms are fully tattooed. His red\n"+
           "eyes watch carefully to the northern passage and he has a huge weapon\n"+
           "wielded in his hands. He seems to be ready for a battle.\n");
  set_al(15);
  set_al_aggr(100);

 if(!q) {
   chat_str = allocate(1);
   chat_str[0] = "Lalli says: 'Please bring me the head of that horrible beast...'\n";
   load_chat(10, chat_str);
 }

   armour = clone_object("/wizards/torspo/areat/gnomes/monsters/eqs/tunika01");
   move_object(armour, this_object());
   init_command("wear tunic");

   weapon = clone_object("/wizards/torspo/areat/gnomes/monsters/eqs/maul01");
   move_object(weapon, this_object());
   init_command("wield maul");

   armour2 = clone_object("/wizards/torspo/areat/gnomes/monsters/eqs/necklace01");
   move_object(armour2, this_object());
   init_command("wear necklace");
}

catch_tell(str) {

   string tmp1,tmp2, chat_str;
   object ob;
   ::catch_tell(str);
   
   if (sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
    ob = present("do_not_abuse_this_one", this_object());
    if (ob && this_player()->query_name() == tmp1) {
    call_out("tuho",0,ob);
    write("Lalli says 'Thank you! Now they believe i'm a real hero.\n"+
          "Lalli snickers.\n");
    q = 1;
     chat_str = allocate(1);
     chat_str[0] = "Lalli states: 'I'm a hero, yes'\n";
     load_chat(5, chat_str);
    this_player()->set_quest("Bring wolf head to Lalli");
    }
   }
}

tuho(ob) {
    destruct(ob);
    return;
}
