
inherit"obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(52);
  set_name("guard");
  set_gender(1);
  set_alias("guard");
  set_short("Jehu's personal gorilla");
  set_long("He is the one who is taking care of the Jehu, the great leader of the\n"
         + "university. He is here to kick your butt, 'cause you attacked Jehu!\n");
  set_skill("attack", 90);
  set_skill("doublehit", 70);
  set_skill("stun", 60);
  set_skill("critical", 60);
  set_al(10);
  set_aggressive(0);

}
