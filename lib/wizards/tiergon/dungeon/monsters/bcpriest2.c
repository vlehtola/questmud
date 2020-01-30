inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(23);
    set_name("priestess");
    set_short("A high priestess of Morai");
    set_long("This young woman serves as the Chaplain's aide.\n");
    set_al(-77);
    set_gender(2);
    set_race("human");
    set_spell_chance("chl hrm mjr", 70); 
    set_skill("cast divine", 77);
    set_skill("cast harm", 77);
    set_skill("cast major", 77);
    set_skill("channel", 77);
    set_aggressive(1);
    set_follow(100,1);   
 
    weapon = clone_object("/wizards/tiergon/eq/bcmace");
    move_object(weapon, this_object());
}

   

