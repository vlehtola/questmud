inherit "obj/monster";

reset(arg) {
    object shirt,trousers,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    set_level(26+random(8));
    set_name("nobleman");
    set_alias("man");
    set_short("A proud looking nobleman is walking on the mainroad");
    set_long("This man is very proud of himself because he is\n"+
              "one of Gnael's nobles. He respects no one and the only\n"+
              "thing in his pathetic mind is to gather more money\n"+
              "from normal people.\n");
             
    set_al(4);
    set_aggressive(0);

   shirt = clone_object("/wizards/jenny/gnael/rojut/silk_shirt");
    move_object(shirt, this_object());
    init_command("wear shirt");      
   
   trousers = clone_object("/wizards/jenny/gnael/rojut/clean_trousers");
    move_object(trousers, this_object());
    init_command("wear trousers");      

   sword = clone_object("/wizards/jenny/gnael/rojut/short_sword");
    move_object(sword, this_object());
    init_command("wield sword");      
   
}
