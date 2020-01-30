inherit "obj/monster";

object shield,miecka;

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(50+random(6));
    set_name("wight");
    set_race("spirit");
    set_str(query_str()*2);
    set_short("The fearsome wight of Norman the Slim");
    set_long("The wight is that of the ancient village bard, Norman the Slim, creator of many\n" +
             "of the most beautiful songs, still sung in the city. The wight seems unhappy to\n" +
             "have been disturbed by an outsider. The wight still seems to be wearing his old\n" +
             "tunic and hat, but instead of a lute and a cymbal, he wields ferocious weapons.\n");
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
    set_dead_ob(this_object());

    shield = clone_object("/wizards/walla/areas/mg/stuph/illushield");
    move_object(shield, this_object());
    init_command("wear shield");

    miecka = clone_object("/wizards/walla/areas/mg/stuph/illublade");
    move_object(miecka, this_object());
    init_command("wield sword");


}

monster_died() {
  destruct(shield);
  destruct(miecka);
  return 0;
}