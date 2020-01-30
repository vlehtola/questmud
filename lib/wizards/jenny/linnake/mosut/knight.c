inherit "obj/monster";

reset(arg) {
    object robe;
    object sword;
    object sword2;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_level(random(5)+50);
        set_str(random(10)+350);
        set_max_hp(query_hp() + 8000);
    set_name("knight");
    set_alias("human");
    set_race("human");
    set_short("Valiant looking knight");
    set_long("Valiant looking knight, he is wearing a black robe and\n"+
              "some underwear under robe. He has blue eyes and a very\n"+
              "strong looking body.\n");
//tuned by Moonstar 17.5.2004
    set_al(10);
    set_aggressive(0);
   set_skills("blades", 100);
   set_skills("slash", 80);
   set_skills("two weapons combat", 100);
   set_skills("critical",100);
   set_skills("doublehit", 100);
   set_skills("find weakness", 80);
   set_skills("stun",100);
   set_skills("double strike",100);
   set_skills("disarm",70);
   set_skill_chance("disarm", 70);
   set_skills("find weakness",80);
   set_skills("reflect spell",15);
   set_skills("strike",100);
   set_skill_chance("strike", 50);

   robe = clone_object("/wizards/jenny/linnake/rojut/knight_robe.c");
    move_object(robe, this_object());
    init_command("wear robe");


   sword = clone_object("/wizards/jenny/linnake/rojut/knight_sword.c");
   move_object(sword, this_object());
   init_command("wield sword");

   sword2 = clone_object("/wizards/jenny/linnake/rojut/knight_sword.c");
   move_object(sword2, this_object());
   init_command("wield sword");

}
