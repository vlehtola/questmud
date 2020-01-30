inherit "obj/monster";

reset(arg) {
    object shirt,trousers,hat;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("gnome");
    set_level(10+random(10));
    set_name("child");
    set_alias("kid");
    set_short("Young looking gnome child");
    set_long("Young looking gnome child is wandering around the\n"+
              "city. He is propably lost and he seems to be crying\n"+
              "for his mother.\n");
             
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
