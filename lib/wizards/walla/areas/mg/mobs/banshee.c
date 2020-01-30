inherit "obj/monster";

reset(arg) {
    object shield,miecka;
    ::reset(arg);
    if(arg) { return; }
    set_level(40+random(6));
    set_name("banshee");
    set_race("spirit");
    set_str(query_str()*2);
    set_short("A wailing banshee of the netherworld ");
    set_long("The banshee that you have awoken does not seem to be happy about being\n" +
             "disturbed. She has guarded the tomb of the valiant hero for a very long\n" +
             "time, and does not seem to like being awoken from the damnation. She has\n" +
             "for goal to destroy every person that dares to disturb her peace.\n");
    set_skill("cast divine", 100);
    set_skill("cast transfer", 100);
    set_skill("cast minor", 100);
    set_skill("chanting", 80);
    set_skill("channel", 80);
    set_skill("tumble", 40);
    set_skill("dodge", 70);
    set_skill("parry", 50);
    set_spell_chance(80, "chl xfr min");
    set_al(-35);
    set_aggressive(1);
    set_gender(2);
    set_undead();
    

    shield = clone_object("/wizards/walla/areas/mg/stuph/boneshield");
    move_object(shield, this_object());
/*    init_command("wear shield");
Jos on shieldi k�des ni kusee. Iskee kuulemma 0 damaa. Ahma */

    miecka = clone_object("/wizards/walla/areas/mg/stuph/bonesword");
    move_object(miecka, this_object());
    init_command("wield sword");


}
