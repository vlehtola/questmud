inherit "obj/monster";
int e = random(3);

reset(arg) {
    object legu,neku,mokka,wepa;
    
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_level(random(5)+70);
    set_str(query_str()*2);
    set_con(query_con()*3);
    set_int(query_int()*2);
    set_max_hp(query_hp()+110000);
    query_max_hp();
    set_name("raphael");
 set_race("human");
    set_alias("exorcist");
    set_short("Raphael, the exorcist");
    set_long("Raphael the exorcist is an ancient-looking white-bearded man. He's got an ugly-looking big scar\n"+
             "going through his face. His right eye-socket is empty. His head looks terribly burned, and he's\n"+
		 "got almost no hair, only small tufts here and there. Scar tissue covers top of his head. Maybe\n"+
             "he's been in a very hard magickal battle which has ruined his physical and mental health.\n");
    	 

    set_al(-200);
    set_aggressive(1);

    set_skill("tumble", 45);
    set_skill("critical", 30);
    set_skill("doublehit", 90);
    set_skill("counter spell", 20);
    set_skill("stun", 30);
    set_spell_chance(40, "exs zzt strm"); 
    set_skill("chanting", 90);
    set_skill("cast essence", 100);
    set_skill("cast electric", 100);
    set_skill("cast storm", 100);
    set_skill("riposte", 60);
    set_skill("theory of electricity", 100);
    set_skill("mana control", 100);
    set_log();
  

  if(e == 0) {
   legu = clone_object("/wizards/veron/areat/golem/items/legs");
    move_object(legu, this_object());
    init_command("wear leggings");      
   wepa = clone_object("/wizards/veron/areat/golem/items/galstaff");
    move_object(wepa, this_object());
    init_command("wield staff");     
}
  if(e == 1) {
    mokka = clone_object("/wizards/veron/areat/golem/items/mokka");
    move_object(mokka, this_object());
    init_command("wear moccasins");      
   wepa = clone_object("/wizards/veron/areat/golem/items/galstaff");
    move_object(wepa, this_object());
    init_command("wield staff");     
}
   if(e == 2) {
    neku = clone_object("/wizards/veron/areat/golem/items/neku");
    move_object(neku, this_object());
    init_command("wear necklace");      
   wepa = clone_object("/wizards/veron/areat/golem/items/galstaff");
    move_object(wepa, this_object());
    init_command("wield staff");     
}
       


   
}

