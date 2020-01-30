inherit "obj/monster";

reset(arg) {
    object shirt,trousers,hat;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    set_level(3+random(10));
    set_name("ben");
    set_alias("child");
    set_short("A small child named 'Ben'");
    set_long("Ben is about 13 years old child and he is the son\n"+
              "of the owner of the mansion. He is wearing some\n"+
              "worn clothes and his face is pretty dirty.\n");
             
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
