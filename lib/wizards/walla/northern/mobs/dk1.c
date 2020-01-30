inherit "obj/monster";
 
    reset(arg) {
    int i,q;
    string chat_str;
    object axe,cloak,helmet,shield;
    ::reset(arg);
    if(arg) { return; }
 
    set_level(77+random(12));
    set_name("khazin-talak");
    set_alias("knight");
    set_alias("dwarf");
    set_str(query_str()*2);
    set_max_hp(query_hp() - 5000);
    set_short("Khazin-Talak, the dwarven deathknight ");
    set_long("The apparition before you is unlike you have ever seen. Before you stands\n"+
             "a figure, about 5 feet tall, wielding the biggest axe that you have seen.\n"+
             "His face is shrouded by a helmet with a small slit where the eyes should be,\n" +
             "only no eyes can be seen. In the place of his eyes are 2 specks of light, in\n" +
             "the color of the hottest fire. In his left hand, the deathknight holds a massive\n" +
             "shield made out of dragon scales.\n");
    set_race("dwarf");
    set_gender(1);
    set_al(-80);
    set_aggressive(1);
    set_skills("shield bash", 100);
    set_skills("axes", 100);
    set_skills("cut", 100);
    set_skills("inner strength", 100);
    set_mage();
    set_log();
    set_undead(1);
 
 
    axe = clone_object("/wizards/walla/northern/stuph/warlock_axe");
    move_object(axe, this_object());
    init_command("wield axe");
 
    helmet = clone_object("/wizards/walla/northern/stuph/warlock_helmet");
    move_object(helmet, this_object());
    init_command("wield helmet");

    shield = clone_object("/wizards/walla/northern/stuph/warlock_shield");
    move_object(shield, this_object());
    
    cloak = clone_object("/wizards/walla/northern/stuph/warlock_cloak");
    move_object(cloak, this_object());
    init_command("wear cloak");
 
   
    set_dead_ob(this_object());
  }
 
monster_died() {
    this_object()->query_attack()->set_quest("End the days of the Dwarven Death Knight");
    tell_object(this_object()->query_attack(),
    "Khazin-Talak takes his last breath as you smash his body to the ground for the last time.\n");
    shout(""+this_player()->query_name()+" roars in victory as he slays Khazin-Talak!\n");
    return 0;
}




