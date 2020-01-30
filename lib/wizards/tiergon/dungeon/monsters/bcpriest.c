inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(21);
    set_name("priestess");
    set_short("A major priestess of Morai tending to the chapel");
    set_long("This young woman serves the Black Circle by training the initiates to Morai's church and maintaining the Dark Chapel.\n");
    set_al(-70);
    set_gender(2);
    set_spell_chance("chl hrm mjr", 70); 
    set_skill("cast divine", 70);
    set_skill("cast harm", 70);
    set_skill("cast major", 70);
    set_skill("channel", 70);
    set_race("human");
    set_move_at_reset();
    set_follow(70,2);    
   
    weapon = clone_object("/wizards/tiergon/eq/bcmace");
    move_object(weapon, this_object());
}
   

