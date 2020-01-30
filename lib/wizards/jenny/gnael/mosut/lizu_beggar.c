inherit "obj/monster";

reset(arg) {
    object shirt,trousers,hat;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("lizardman");
    set_level(10+random(17));
    set_name("beggar");
    set_alias("man");
    set_short("A lizardman is whining money here");
    set_long("An old and dirty looking lizardman is here whining\n"+
              "money and alcohol from everyone. He is wearing\n"+
              "very worn looking clothes and he surely smells bad.\n");
             
    set_al(0);
    set_aggressive(0);

   shirt = clone_object("/wizards/jenny/gnael/rojut/shirt");
    move_object(shirt, this_object());
    init_command("wear shirt");      
   
   trousers = clone_object("/wizards/jenny/gnael/rojut/trousers");
    move_object(trousers, this_object());
    init_command("wear trousers");      

   hat = clone_object("/wizards/jenny/gnael/rojut/hat");
    move_object(hat, this_object());
    init_command("wear hat");      
   
}
