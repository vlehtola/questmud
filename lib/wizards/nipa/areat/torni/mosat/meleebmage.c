inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_name("battlemage");
    set_alias("mage");
    set_race("human");
    set_gender(3);
    set_mage(0);
    set_al(-10);  
    set_aggressive(0);    
    set_level(45+random(7));
    set_resists("cold", 15 + random(5));
    set_resists("fire", 15 + random(5));
    set_resists("electric", 15 + random(5));
    set_short("Tough looking female battlemage guarding here.");
    set_long("Battlemages are formidable opponents tha excel in both magical and\n"+ 
             "physical combat. In this magetower the adepts that have mastered the\n"+ 
             "arcane arts are either promoted to archmages or have chosen to go on\n"+
             "the hard path of becoming battlemages. Mages that have never even held\n"+ 
             "weapons are given and taught to use one. These mages are elite of\n"+ 
             "Alsatia and are respected and feared by its every resident.\n"+
             "There are two types of battlemages, those who are still training in the\n"+
             "use of martial weapons and are forbidden to use any magic and those who\n"+
             "are profient in using their chosen weapon and have already gained\n"+ 
             "permission to use magic again in battle. In front of you stands very\n"+
             "irritated mage. You notice that she doesnt even try to start a spell but\n"+
             "readies her stance for attacking you straightforward.\n");

  move_object(clone_object("/wizards/nipa/areat/torni/ekut/longsword.c"),this_object());
  move_object(clone_object("/wizards/nipa/areat/torni/ekut/redplate.c"),this_object());
     
    init_command("wear all");
    init_command("wield sword");

    set_skill("attack", 100);
    set_skill("dodge", 20);
    set_skill("parry", 20);
    set_skill("critical", 70);
    set_skill("attack", 100);
    set_skill_chance("strike", 60);
    set_skill("deceived attack", 30);
    set_skill("enhance criticals", 40);
    set_skill("find weakness", 40);
    set_skill("throw weight", 70);
    set_skill("blades", 100);
    set_skill("bludgeons", 100);
    set_skill("axes", 100);
    set_skill("slash", 80);
    set_skill("pound", 80);
    set_skill("cut", 80);
    set_skill("bare hands", 100);
    set_skill("punch", 100);
    set_skill("stun", 70);
    set_skill("agility", 40);
    set_skill("tumble", 15);
}
