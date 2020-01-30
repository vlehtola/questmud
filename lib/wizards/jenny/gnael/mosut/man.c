inherit "obj/monster";

reset(arg) {
    string chat_str;
    object ring,robe,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    set_level(50+random(13));
    set_special(10);
    set_str(query_str()+120);
    set_dex(query_str()+300);
    set_max_hp(query_hp()+random(40000));
    set_name("man");
    set_alias("man");
    set_short("A mysterious looking man");
    set_long("A mysterious looking man wearing a black robe.\n"+
              "He has cold eyes and a bald head, You can't really\n"+
              "notice much about him, but you can see that he has\n"+
              "a very expensive looking diamond ring on his finger.\n");
             
    set_block_dir("east");
    set_al(-30);
    set_aggressive(0);
   
   set_skills("critical",100);
   set_skills("doublehit",100);
   set_skills("dodge",100);
   set_skills("alertness",100);
   set_skills("foresee attack",100);
   set_skills("find weakness",80);
   set_skills("stun",100);
   set_skills("slash",100);
   
   set_log();

   ring = clone_object("/wizards/jenny/gnael/rojut/diamond_ring.c");
    move_object(ring, this_object());
    init_command("wear ring");      

   robe = clone_object("/wizards/jenny/gnael/rojut/robe.c");
    move_object(robe, this_object());
    init_command("wear robe");  

   sword = clone_object("/wizards/jenny/gnael/rojut/short_sword.c");
    move_object(sword, this_object());
    init_command("wield sword");  

                 if (!chat_str) {
                                chat_str = allocate(4);
                                chat_str[0] = "Man says: 'I am the leader of assassins'\n";
                                chat_str[1] = "Man says: 'No one can escape us'\n";
                                chat_str[2] = "Man says: 'Assassins guild is closed from everyone at this moment'\n";
                                chat_str[3] = "Man says: 'That Mondasa fellow is bad for business...'\n";
                         }
                         load_chat(4, chat_str); 
}

special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "Suddenly you feel enormous PAIN as the man CRUELLY STABS\n"+
  "you on the back!\n");
  say("You notice man doing some swift moves and all the sudden "+ob->query_name()+" \n"+
  "is BLEEDING BADLY!\n", ob);
  ob->hit_with_spell(800, "physical");
}
