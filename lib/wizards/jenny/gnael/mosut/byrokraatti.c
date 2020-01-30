inherit "obj/monster";

reset(arg) {
    object armour,trousers,sword;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    set_level(random(15)+5);
    set_name("man");
    set_alias("bureaucrat");
    set_short("A "+({ "busy", "tired", "sweaty", "sad", "hungry",})[random(5)]+" looking bureaucrat is running around");
    set_long("This bureaucrat looks very busy and he is constantly\n"+ 
              "mumbling something. His eyes look tired and he is\n"+
              "sweating badly. He has a leather armour protecting\n"+
              "from assassins and a small short sword is tied to\n"+
              "his wrist.\n");
             
    set_al(0);
    set_aggressive(0);
   
   armour = clone_object("/wizards/jenny/gnael/rojut/leather_armour");
    move_object(armour, this_object());
    init_command("wear armour");      
   
   trousers = clone_object("/wizards/jenny/gnael/rojut/trousers");
    move_object(trousers, this_object());
    init_command("wear trousers");      

   sword = clone_object("/wizards/jenny/gnael/rojut/short_sword");
    move_object(sword, this_object());
    init_command("wield sword");     
 
}
