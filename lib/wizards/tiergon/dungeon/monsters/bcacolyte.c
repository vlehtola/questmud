inherit "obj/monster";

reset(arg) {
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(18);
    set_name("acolyte");
    set_short("A young acolyte studying the ways of Morai");
    set_long("This young man has been drawn from the Black Circle's pool of recruits to have the honour of serving as a priest of Morai.\n"+
             "He seems to be absorbed in prayer.");
    set_al(-40);
    set_follow(50,5);
    set_gender(1);
    set_race("human");
    set_spell_chance("chl hrm les", 60); 
    set_skill("cast divine", 60);
    set_skill("cast harm", 60);
    set_skill("cast lesser", 60);
    set_skill("channel", 60);

   
    weapon = clone_object("/wizards/tiergon/eq/bcmace");
    move_object(weapon, this_object());
}
   

