inherit "obj/monster";

reset(arg) {

    int i;
    object armour;
    ::reset(arg);
    if(arg) { return; }
    i = random(30);
    if(i>0) {
    set_level(i+20);
    set_name("eye");
    set_short("A multicoloured eye");
    set_long("A strange eye staring at you angrily.\n");
    set_animal(1);
    set_wc(i+20);
    set_ac(i+20);
    set_aggressive(1);
    set_gender(0);
        }
    if(i>5) {
    set_level(i+25);



    set_name("demon");
    set_short("A blue demon with a crystal horn");
    set_long("A demon hopping around and making strange sounds.\n"+
             "The crystal horn shines as light hits it.\n");
    set_animal(1);
    set_wc(i*5+30);
    set_ac(i+25);
    set_aggressive(1);
    set_gender(0);
      }


    if(i>15) {
    set_level(i+20);
    set_name("animal");
    set_short("A four handed animal");
    set_long("A tall hairy animal with four hands. It looks little\n"+
             "like a human, but its has no knees nor elbows.\n");
    set_animal(1);
    set_wc(i*5+30);
    set_ac(i+25);
    set_aggressive(1);
    set_gender(0);
      }
    if(i==0) {
  set_level(random(10) + 60);
    set_name("beast");
    set_short("A terrible beast with long horns");
    set_long("A huge beast with two long horns. Its crimson eyes\n"+
             "glows strongly.\n");
    set_animal(1);
    set_wc(100);
    set_ac(70);
    set_aggressive(1);
    set_gender(0);
    set_mage();
    set_log();

    set_str(query_str()+100);
    set_dex(query_dex()+50);
    set_skill("deceived attack", 75);
    set_skill("stun", 100);

    armour = clone_object("/wizards/siki/lizard/eq/beastbrac");
    move_object(armour,this_object());
    init_command("wear bracers");
      }
}
monster_died() {
    object ob;
    ob = find_object("/wizards/siki/lizard/monsters/shaman");
    if (!ob) { return; }
    ob->reduce_number();
}

