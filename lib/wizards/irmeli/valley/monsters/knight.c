inherit "obj/monster";

void reset(status arg) {
    string *chat_str;
    string *a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(100);
    set_log();
    set_name("knight");
    set_alias("human");
    set_short("Knight of the Cross, archfiend of the Enchantress");
    set_long("A valiant knight is the last living member of the Cross. He is old but\n"+
             "tremendously strong. Only the best fighters can give him the final\n"+
             "deathblow, which ends the power of the Cross, eventually. His curly,\n"+
             "silver-grey hair, angular face and well-proportioned figure, complemets\n"+
             "his neat, elegant appearance. He is the archfiend of the Enchantress\n"+
             "Victoria.\n");

    set_race("human");
    set_gender(1);
    set_al(10);
    set_str(1000);
    set_aggressive(0);
    set_init_ob(this_object());
    if(!chat_str)
      chat_str = ({ "Knight says: 'Bring me the heart of the Enchantress.'\n", });
    if(!a_chat_str)
      a_chat_str = ({ "Knight says: 'I must protect the Cross.'\n", });
    load_chat(7, chat_str);
    load_a_chat(3, a_chat_str);
}


void gived_you(object *item) {
  object ob;
  if(!item) return;
  ob = item[0];
     /* prevent for using illusion to get unlimited amount of free eq //Celtron */
     if(ob && (strlen(file_name(ob)) < 23 || file_name(ob)[0..21] != "/wizards/irmeli/valley")) {
	tell_room(environment(this_object()), "The knight looks outraged and disappointed, 'You dare try to trick me?!'\n");
        this_object()->attack_object(this_player());
        destruct(ob);
        return;
     }
     /* end */

       destruct(ob);
       write("Knight says: 'Finally someone has given the final deathblow to the Enchantress.'\n");
       call_out("do_quest",3,this_player());
}

void do_quest(object ob) {
  tell_object(ob,"Knight says: 'I'll give you this armour, as a reward for your trouble.'\n");
  ob->set_quest("Bring the heart to the Knight");
  move_object(clone_object("/wizards/irmeli/valley/eq/armour_of_courage01"), this_player());
}
