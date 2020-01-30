inherit "obj/monster";

reset(arg) {

  ::reset(arg);
  if(arg) { return; }


  set_level(21+random(3));
  set_dex(query_dex()*8);
  set_name("ghost");
  set_undead(1);
  set_short("A roaming ghost");
  set_long("An extremely agile ghost roaming all around the maze.\n"+
         "You can see through it.\n");
  set_al(-50);
  set_aggressive(random(2));
  set_gender(0);

    set_skill("dodge", 200);
    set_skill("alertness", 200);
    set_skill("ignore wrong strike", 200);
    set_skill("foresee attack", 200);
    set_skill("tumble", 250);
    set_skill("coordination", 100);
    set_skill("bare hands", 40);
    set_skill("punch", 40);
    set_skill("attack", 40);
    set_skill("critical", 100);
    set_skill("find weakness", 100);

}

